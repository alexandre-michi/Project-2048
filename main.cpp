#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <QQuickView>

#include "damier.h"
#include "damierqml.h"

#include <iostream>

using namespace std;


// #########################################################################
//                              Play 2048 in GUI
// #########################################################################

int main(int argc, char *argv[])
{
    // QT quick application
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    // Register Tile to be available in QML
    qmlRegisterType<DamierQML>("DamierQML", 1, 0, "DamierQML");

    QQuickView *view = new QQuickView;

    const QUrl url(QStringLiteral("qrc:/main.qml"));

    view->setSource(url);

    QObject *main_grid = view->rootObject()->findChild<QObject*>("main_grid");
//    QQuickItem *root = view->rootObject()->findChild<QQuickItem*>("main_grid");
    QQuickItem *root = view->rootObject();
    DamierQML damierQML(view->engine(), main_grid, root); // instanciate new DamierQML object with parent=main_grid
    view->engine()->rootContext()->setContextProperty("damierQML", &damierQML); // link object damierQML with QML document


//    QObject *main_grid = getObject(view->engine(), "main_grid");

    view->show();


    return app.exec();
}

// #########################################################################
//                          Play 2048 in the console
// #########################################################################

//int main(int argc, char *argv[])
//{
//    Damier d = Damier(4);
//    int movement;
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
//}
