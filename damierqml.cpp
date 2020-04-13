#include "damierqml.h"
#include <iostream>
#include <string>
using namespace std;

/*
 * Constructeur
 */
DamierQML::DamierQML(QObject *parent, QQuickItem *root): QObject(parent)
{
    // Setting colors parameters for display
    COLORS["0"] = "#3f334d";
    COLORS["2"] = "#c0d461";
    COLORS["4"] = "#aef78e";
    COLORS["8"] = "#caffb9";
    COLORS["16"] = "#66a182";
    COLORS["32"] = "#2e4057";
    COLORS["64"] = "#6e9887";
    COLORS["128"] = "#b5bfa1";
    COLORS["256"] = "#edbfb7";
    COLORS["512"] = "#f283b6";
    COLORS["1024"] = "#e06c9f";
    COLORS["2048"] = "#91171F";
    COLORS["4096"] = "#EA2B1F";
    COLORS["8192"] = "#EDAE49";
    COLORS["16384"] = "#F9DF74";

    // Initialize damier
    size = 4;
    D = new Damier(size);
    tiles = new QObject*[16];

    // Get tiles from QML
    for (int i = 0; i < size*size; i++)
    {
        QString name = "tile" + QString::number(i);
        tiles[i] = root->findChild<QObject*>(name);
    }
}

/*
 * Met à jour le contenu des cases
 * @params key : mouvement demandé par le joueur
 */
void DamierQML::updateTilesContent(int key){

    // Movement in the Damier class
    D->process(key);
    int ** t = D->getTab();

    // Tiles are updates
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            tiles[i*size+j]->setProperty("color", COLORS[to_string(t[i][j])]);
            if (t[i][j] != 0){
                tiles[i*size+j]->setProperty("tileLbl", QString::number(t[i][j]));
            } else {
                tiles[i*size+j]->setProperty("tileLbl", "");
            }
        }
    }

    // Send signal
    damierChanged();
}
