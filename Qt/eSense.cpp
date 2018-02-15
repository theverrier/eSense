#include "eSense.h"
#include "ui_eSense.h"

eSense::eSense(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::eSense)
{
    ui->setupUi(this);
    ui->serialPortInfo->setText(serialPortName);
    ui->hostInfo->setText(dbHost);

    serialport = new QSerialPort(this);
    serialport->setPortName(serialPortName);
    serialport->setBaudRate(QSerialPort::Baud9600);
    //    serialport->open(QIODevice::ReadOnly);
    //    serialport->open(QIODevice::WriteOnly);
    serialport->open(QIODevice::ReadWrite);
    connect(serialport, &QSerialPort::readyRead, this, &eSense::readData);

    database = QSqlDatabase::addDatabase(dbType);
    database.setHostName(dbHost);
    database.setPort(dbPort);
    database.setDatabaseName(dbName);
    database.setUserName(dbUser);
    database.setPassword(dbPwd);
    openDBTable(dbTableWeather);
    connect(this, SIGNAL(newParsedData(QStringList)),this, SLOT(sendSQLData(QStringList)));

}

eSense::~eSense()
{
    delete ui;
}
//*******************************FUNCTIONS*******************************
void eSense::debugQuery(QSqlQuery query)
{
    qDebug() << "LAST QUERY: " << query.lastQuery();
    qDebug() << "ROWS AFFECTED: " << query.numRowsAffected();
    qCritical() << "LAST ERROR: " << query.lastError().text();
}

void eSense::openDBTable(QString table)
{
    if (database.open())
    {
        QSqlQuery query;
        qDebug() << "Connection ok...";
        //        qDebug() << "does it,too?: " <<database.tables().contains("wp_options");
        query.prepare(QString("CREATE TABLE IF NOT EXISTS %1 (Timestamp TIMESTAMP UNIQUE PRIMARY KEY, "
                              "Temperature VARCHAR(30), Humidity VARCHAR(30), HeatIndex VARCHAR(30));").arg(table));
        if(query.exec())
            qDebug() << "table created or already existing!";
        else
            debugQuery(query);
    }
}
//*********************************SLOTS********************************
void eSense::readData()
{
    if(serialport->canReadLine()){
        serialport->readLine(buffer,sizeof(buffer));
        //        qDebug() << "data: " << buffer;
    }
    QStringList parsedData = SerialDataParser::extractMeteoData(buffer);
    emit newParsedData(parsedData);

    QByteArray message("RPi2Adn");
    serialport->write(message);

    temperature = parsedData.value(0);
    humidity = parsedData.value(1);
    heatIndex = parsedData.value(2);
//        qDebug() << "temp: " << temperature << " humid:" << humidity << " Heat index:" << heatIndex <<endl;
}

void eSense::sendSQLData(QStringList parsedData)
{
    if(database.isOpen()){

        QSqlQuery query;
        /* selects rows having empty values, recounts the new nr of rows
         * checks if more rows than permitted, deletes the extra rows
         * and pastes it in the log windows */
        query.exec("DELETE FROM wp_weather WHERE Temperature='' ");
        query.exec("SELECT COUNT(*) FROM wp_weather");
        if(query.next()){
            curNrRows = query.value(0).toInt();
            if(curNrRows<maxNrRows)
                curNrRows = maxNrRows;
        }
        query.prepare("DELETE FROM wp_weather LIMIT :limit");
        query.bindValue(":limit", curNrRows-maxNrRows);
        if(query.exec())
            ui->log->append(QString("%1 rows deleted").arg(curNrRows-maxNrRows));
        //            qDebug() << curNrRows-maxNrRows << " values deleted!";
        else
            debugQuery(query);

        /* inserts new read data into the table
         * pastes informative message in log window */
        query.prepare(
                    "INSERT INTO wp_weather (Timestamp, Temperature, Humidity, HeatIndex)"
                    "VALUES (:time, :temp, :humid, :heatIndex );");
        query.bindValue(":time", QDateTime::currentDateTime());
        query.bindValue(":temp", temperature);
        query.bindValue(":humid", humidity);
        query.bindValue(":heatIndex", heatIndex);
        if(query.exec())
            ui->log->append("new values added");
        //            qDebug() << "new values added";
        else
            debugQuery(query);
    }
}
