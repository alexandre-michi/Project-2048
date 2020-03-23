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

//    while (!d.isDefeat())
//    {
//        d.consolePrint();

//        cout << "   0 : UP" << endl;
//        cout << "   1 : RIGHT" << endl;
//        cout << "   2 : DOWN" << endl;
//        cout << "   3 : LEFT" << endl;
//        cout << "Movement : ";
//        cin >> movement;
//        d.process(movement);
//    }


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


//int main(int argc, char *argv[])
//{
//    Damier d = Damier(4);
//    int movement;

//    while (!d.isDefeat())
//    {
//        d.consolePrint();
        
//        cout << "   0 : UP" << endl;
//        cout << "   1 : RIGHT" << endl;
//        cout << "   2 : DOWN" << endl;
//        cout << "   3 : LEFT" << endl;
//        cout << "Movement : ";
//        cin >> movement;
//        d.process(movement);
//    }
    
//    // QApplication a(argc, argv);
//    // MainWindow w;
//    // w.show();
//    // return a.exec();
//    return 0;
//}
