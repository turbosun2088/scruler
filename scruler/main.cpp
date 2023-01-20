#include "mainscruler.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/images/mainicon.icns"));
    MainScruler w;
    w.show();
    return a.exec();
}
