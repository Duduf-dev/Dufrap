#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>
#include "params.h"

int main(int argc, char *argv[])
{
    QTranslator translator;
    translator.load("languages/dufrap_" + QLocale::system().name());
    QApplication a(argc, argv);
    Params p;
    translator.load(p.getLanguage());
    a.installTranslator(&translator);
    MainWindow w(argc,argv);
    w.show();

    return a.exec();
}
