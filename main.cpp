// #include "mainwindow.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>

#include "damier.h"

//#include <QApplication>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    Damier d = Damier(4);
    int movement;

    while (!d.isDefeat())
    {
        d.consolePrint();
        

    // QT quick application
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
    }
    
    // QApplication a(argc, argv);
    // MainWindow w;
    // w.show();
    // return a.exec();
    return 0;
}
