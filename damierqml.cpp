#include "damierqml.h"
#include <iostream>
using namespace std;

DamierQML::DamierQML(QQmlEngine *engine, QObject *parent, QQuickItem *root): QObject(parent)
{
    cout << "salut je suis dans damierqml" << endl;
    size = 4;
    D = new Damier(size);
    tiles = new QQuickItem*[16];
    // Using QQmlComponent

    const QUrl url(QStringLiteral("qrc:/MyTile.qml"));

//    QQuickItem *tileObj = qobject_cast<QQuickItem*>(component.create());
//    QObject *tile = component.create();
//    tile->setProperty("size", 100);
//    tile->setParent(parent);

    for (int i = 0; i < size*size; i++)
    {
        QQmlComponent component(engine, url);
        QQuickItem *tileObj = qobject_cast<QQuickItem*>(component.create());
//        QObject *tile = component.create();
        tiles[i] = tileObj;
        tiles[i]->setProperty("size", 200);
        tiles[i]->setParent(parent);
        tiles[i]->setParentItem(root);
        cout << tiles[i] << endl;
    }

    // delete tile;
}


void DamierQML::setTilesParent(QObject* parent, QQuickItem *root){
    for(size_t i = 0; i < sizeof(tiles); ++i) {
        tiles[i]->setParent(parent);
        tiles[i]->setParentItem(root);
        tiles[i]->setVisible(true);
    }

    cout << parent << endl;
}

