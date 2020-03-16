#include "damier.h"
#include <stdlib.h>

// Constructeur : allocation de mémoire et initialisation à zéro
Damier::Damier(int size)
{
    int Size = size;
    tab = new int*[Size];

    for(int i=0; i<Size; i++){
        tab[i] = new int[Size];
        for(int j=0; j<Size; j++){
            tab[i][j] = 0;
        }}

    randomTile();
}

// Place un 2 ou un 4 au hasard sur le damier
void Damier::randomTile()
{
    int i = rand() % Size;
    int j = rand() % Size;

    // On s'assure que la case est vide, sinon on en cherche une autre
    while(tab[i][j] != 0){
        int i = rand() % Size;
        int j = rand() % Size;
    }

    tab[i][j] = 2; // Possibilité de changer avec 4

}
