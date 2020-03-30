#include "damierqml.h"

DamierQML::DamierQML(QObject *parent) : QObject(parent)
{
    Damier D = Damier(4);
    // Using QQmlComponent
    QQmlEngine *engine = new QQmlEngine;
    QObject *grid_damier = parent->findChild<QObject *>("grid_damier");
    QQmlComponent component(engine, QUrl::fromLocalFile("tile.qml"));
    

    for (int i = 0; i < 16; i++)
    {
        QObject *tile = component.create();
        tile->setParent(grid_damier);
    }

    // delete object;
}
