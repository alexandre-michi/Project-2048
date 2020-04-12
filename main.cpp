#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>

#include "damier.h"
#include "damierqml.h"

#include <iostream>

using namespace std;

QObject* getObject(const QQmlApplicationEngine &engine, QString objectName)
{
    // Get object by name
    QObject *object = nullptr;
    QList<QObject*> lObj = engine.rootObjects();
    for (int i = 0; i < lObj.size(); ++i)
    {
        QObject *obj = lObj.at(i);
        if(obj != nullptr)
        {
            object = obj->findChild<QObject*>(objectName);
            if(object != nullptr){
                break;
            }
        }
    } return object;
}


int main(int argc, char *argv[])
{
    Damier d = Damier(4);
    int movement;

//   while (!d.isDefeat())
//   {
//       d.consolePrint();

//       cout << "   0 : UP" << endl;
//       cout << "   1 : RIGHT" << endl;
//       cout << "   2 : DOWN" << endl;
//       cout << "   3 : LEFT" << endl;
//       cout << "Movement : ";
//       cin >> movement;
//       d.process(movement);
//   }


    // QT quick application
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    // Register Tile to be available in QML
    qmlRegisterType<DamierQML>("DamierQML", 1, 0, "DamierQML");

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
