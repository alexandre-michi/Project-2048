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
    Q_PROPERTY(QString score READ readScore NOTIFY scoreChanged)

private:
    int score = 2048;
    int size;
    QObject ** tiles;
    Damier *D;
    std::map<std::string, QString> COLORS;

public:
    explicit DamierQML(QObject *parent = nullptr, QQuickItem *root = nullptr);
    QString readScore ();
    Q_INVOKABLE void updateTilesContent(int key);

signals:
    void damierChanged();
    void scoreChanged();
};


#endif // DAMIERQML_H
