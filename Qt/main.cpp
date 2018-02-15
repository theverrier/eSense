#include "eSense.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    eSense w;
    w.show();

    return a.exec();
}
