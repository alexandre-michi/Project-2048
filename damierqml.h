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
    QObject ** tiles;
    Damier *D;
    std::map<std::string, QString> COLORS;

public:
    explicit DamierQML(QObject *parent = nullptr, QQuickItem *root = nullptr);
    Q_INVOKABLE void updateTilesContent(int key);

signals:
    void damierChanged();
};


#endif // DAMIERQML_H
