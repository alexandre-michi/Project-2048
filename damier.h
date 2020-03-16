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
        void process();
        std::queue<int> clearArray(int[] t);
};

#endif // DAMIER_H
