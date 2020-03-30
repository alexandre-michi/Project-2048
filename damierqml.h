#ifndef DAMIERQML_H
#define DAMIERQML_H
#include "damier.h"
#include <QObject>
#include <QString>
#include <QQmlApplicationEngine>
#include <QQmlComponent>


class DamierQML: public QObject
{
    Q_OBJECT
//    Q_PROPERTY(unsigned short _score READ score WRITE setScore NOTIFY valueChanged)

private:
    unsigned short _score;

public:
    explicit DamierQML(QObject *parent = nullptr);
    void setDamierQML();

    void setScore(unsigned short val);

signals:
    void damierChanged();

};

#endif // DAMIERQML_H
