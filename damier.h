#ifndef DAMIER_H
#define DAMIER_H

#include <queue>

class Damier
{
    private :
        int Size;
        int ** tab;

    public:
        Damier(int size);
        ~Damier();
        bool checkDefeat();
        void randomTile();
        void process(int movement);
        std::queue<int> clearArray(int t[], int mvt); // lifo ie un paquet de gâteaux
        void consolePrint();
};

int const UP = 0;
int const RIGHT = 1;
int const DOWN = 2;
int const LEFT = 3;

#endif // DAMIER_H
