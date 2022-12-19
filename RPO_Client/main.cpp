#include "mainwindow.h"

//#include <QCoreApplication>
#include <QApplication>

//#include "server.h"

// Temp
//#include "config.h"
#include <iostream>

int main(int argc, char *argv[])
{
    // QCoreApplication a(argc, argv);
     QApplication a(argc, argv);

     //Server server;
     MainWindow w;
     w.show();

     return a.exec();
}
