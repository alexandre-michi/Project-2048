#ifndef DAMIERQML_H
#define DAMIERQML_H
#include "damier.h"
#include <QObject>
#include <QString>


class DamierQML: public QObject
{
    Q_OBJECT

public:
    explicit DamierQML(QObject *parent = nullptr);

signals:
    void damierChanged();

};

#endif // DAMIERQML_H
