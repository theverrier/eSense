#ifndef SERIALDATAPARSER_H
#define SERIALDATAPARSER_H
#include <QtCore>

class SerialDataParser
{
public:
    //SerialDataParser();
    static QStringList extractMeteoData(char *rawMessage);//=rawMsg[]

};

#endif // SERIALDATAPARSER_H
