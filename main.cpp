#include "mainwindow.h"

#include "damier.cpp"

#include <QApplication>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    Damier d = Damier(4);
    int movement;
    while (!d.checkDefeat())
    {
        d.consolePrint();
        cout << "Movement (u, l, r, d) ?";
        cin >> movement;
        d.process(movement);
    }
    
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
