#include <iostream>
#include <QApplication>
#include "mainWindow.h"
#include "videoByFrame.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainWindow w;
    w.show();
    return a.exec();
}
