#include "mainwindow.h"

#include "damier.h"

#include <QApplication>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    Damier d = Damier(4);
    int movement;

    while (!d.isDefeat())
    {
        d.consolePrint();
        
        cout << "   0 : UP" << endl;
        cout << "   1 : RIGHT" << endl;
        cout << "   2 : DOWN" << endl;
        cout << "   3 : LEFT" << endl;
        cout << "Movement : ";
        cin >> movement;
        d.process(movement);
    }
    
    // QApplication a(argc, argv);
    // MainWindow w;
    // w.show();
    // return a.exec();
    return 0;
}
