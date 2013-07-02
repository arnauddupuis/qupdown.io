#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setOrganizationName("Codepreneur.org");
    QCoreApplication::setOrganizationDomain("codepreneur.org");
    QCoreApplication::setApplicationName("Qupdown.io");
    MainWindow w;
    w.show();
    
    return a.exec();
}
