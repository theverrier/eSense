#include "SerialDataParser.h"

//SerialDataParser::SerialDataParser()
//{

//}

QStringList SerialDataParser::extractMeteoData(char *rawMessage)
{
        QStringList fineDataList;
        QString temperature, humidity, heatIndex;
        // split entries by each meteo measured data
        QStringList rawDataList = QString(rawMessage).split("\t");
        for(int index = 0; index < rawDataList.length(); index++){
            if(QString(rawDataList.value(index)).contains("Temperature")){
                temperature = QString(rawDataList.value(index));
                temperature = temperature.split(":").value(1);
            }
            else if(QString(rawDataList.value(index)).contains("Humidity")){
                humidity = QString(rawDataList.value(index));
                humidity = humidity.split(":").value(1);
            }
            else{ //if(QString(rawDataList.value(index)).contains("Heat index"))
                heatIndex = QString(rawDataList.value(index));
                heatIndex = heatIndex.split(":").value(1);
                heatIndex = heatIndex.split("\r").value(0);
            }
        }
        fineDataList.append(temperature);
        fineDataList.append(humidity);
        fineDataList.append(heatIndex);
        return fineDataList;
}
