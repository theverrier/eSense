#ifndef ESENSE_H
#define ESENSE_H

#include <QMainWindow>
#include <QSerialPort>
#include <QDebug>
#include "Utilities/Arduino/SerialDataParser.h"
#include <qsqldatabase.h>
#include <qsqlquery.h>
#include <qsqlerror.h>
#include <qdatetime.h>

#include <QLabel>
#include <QTextBrowser>

namespace Ui {
class eSense;
}

class eSense : public QMainWindow
{
    Q_OBJECT

public:
    explicit eSense(QWidget *parent = 0);
    ~eSense();

private:
    Ui::eSense *ui;
    QSerialPort *serialport;
    QString serialPortName = "ttyUSB0";//"ttyACM0";
    char buffer[75];

    QString temperature, humidity, heatIndex;

    QString dbType = "QMYSQL";
    QString dbHost = "localhost";//"192.168.178.41";
    int dbPort = 3306;
    QString dbName = "wordpress";
    QString dbUser = "root";
    QString dbPwd = "password";
    QSqlDatabase database;
    QString dbTableWeather = "wp_weather";
    int curNrRows = 0;
    const int maxNrRows = 30;

    void debugQuery(QSqlQuery query);  
    void openDBTable(QString table);

signals:
    void newParsedData(QStringList data);

public slots:

private slots:
    void readData();
    void sendSQLData(QStringList parsedData);
};

#endif // ESENSE_H
