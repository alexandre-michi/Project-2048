#ifndef DAMIERQML_H
#define DAMIERQML_H
#include "damier.h"
#include <QObject>
#include <QString>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQuickItem>


class DamierQML: public QObject
{
    Q_OBJECT
//    Q_PROPERTY(int score READ score WRITE setScore NOTIFY damierChanged)

private:
    int score;
    int size;
    QQuickItem ** tiles;
    Damier *D;

public:
    explicit DamierQML(QQmlEngine *engine = nullptr, QObject *parent = nullptr, QQuickItem *root = nullptr);
    void setTilesParent(QObject *parent, QQuickItem *root);
//    void setDamierQML();

    void setScore(unsigned short val);

signals:
    void damierChanged();

};

#endif // DAMIERQML_H
