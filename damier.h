#ifndef DAMIER_H
#define DAMIER_H

#include <queue>

class Damier
{
    private :
        int Size;
        int ** tab;
        int score;

    public:
        Damier(int size);
        ~Damier();
        bool isDefeat();
        void randomTile();
        void process(int movement);
        std::queue<int> clearArray(const int t[], int mvt); // lifo ie un paquet de gâteaux
        void consolePrint();

        int ** getTab() { return tab;};
        int getScore(){ return score;};
};

const int UP = 0;
const int RIGHT = 1;
const int DOWN = 2;
const int LEFT = 3;

#endif // DAMIER_H
