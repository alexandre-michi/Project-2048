#include "damier.h"
#include <stdlib.h>
#include <iostream>

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

bool Damier::checkDefeat()
{
    for (size_t i = 0; i < Size; i++)
    {
        for (size_t j = 0; j < Size; j++)
        {
            int t = tab[i][j]; 
            if (t == 0){ return false;} // there is an empty tile
            // there is a possibility for fusion :
            else if (i - 1 >= 0 && t == tab[i - 1][j]){ return false;}
            else if (i+1 < Size && t == tab[i + 1][j]){ return false;}
            else if (j - 1 >= 0 && t == tab[i][j - 1]){ return false;}
            else if (j + 1 < Size && t == tab[i][j + 1]){return false;}
        } 
    }
    return true;   
}

std::queue<int> Damier::clearArray(int t[], int mvt)
{
    std::queue<int> my_queue; // lifo ie un paquet de gâteaux
    if (mvt == UP || mvt == LEFT)
    {
        for (size_t i = 0; i < Size; i++)
        {
            if (t[i] != 0){ my_queue.push(t[i]);}
        }
    }
    else
    {
        for (size_t i = Size-1; i >= 0; i--)
        {
            if (t[i] != 0){ my_queue.push(t[i]);}
        }
    }
    return my_queue;
}

void Damier::process(int movement)
{
    if (movement == UP) 
    {
        for (size_t j = 0; j < Size; j++)
        {
            size_t index = 0; // to fill tab
            int *col = new int[Size];
            for (size_t i = 0; i < Size; i++)
            {
                col[i] = tab[i][j];
                tab[i][j] = 0; // reset column by setting everything to 0
            }

            std::queue<int> my_queue = clearArray(col, movement); // queue with no 0

            while (!my_queue.empty())
            {
                int curr_num = my_queue.front(); // to get value because pop returns void
                my_queue.pop();
                if (curr_num == my_queue.front()) // same number, hence needs fusion
                {
                    my_queue.pop();               // pop because value already processed
                    tab[index][j] = curr_num * 2; // fill tab
                    index++;                      // increase index
                }
            }
        }
    }
    else if (movement == DOWN)
    {
        for (size_t j = 0; j < Size; j++)
        {
            size_t index = Size-1; // to fill tab
            int *col = new int[Size];
            for (size_t i = 0; i < Size; i++)
            {
                col[i] = tab[i][j];
                tab[i][j] = 0; // reset column by setting everything to 0
            }

            std::queue<int> my_queue = clearArray(col, movement); // queue with no 0

            while (!my_queue.empty())
            {
                int curr_num = my_queue.front(); // to get value because pop returns void
                my_queue.pop();
                if (curr_num == my_queue.front()) // same number, hence needs fusion
                {
                    my_queue.pop();               // pop because value already processed
                    tab[index][j] = curr_num * 2; // fill tab
                    index--;                      // increase index
                }
            }
        }
    }
    else if (movement == LEFT)
    {
        for (size_t i = 0; i < Size; i++)
        {
            size_t index = 0; // to fill tab
            int *line = tab[i];
            std::queue<int> my_queue = clearArray(line, movement); // queue with no 0
            for (size_t j = 0; j < Size; j++)
            {
                tab[i][j] = 0; // reset line by setting everything to 0
            } 
            
            while (!my_queue.empty())
            {
                int curr_num = my_queue.front(); // to get value because pop returns void
                my_queue.pop();
                if (curr_num == my_queue.front()) // same number, hence needs fusion
                {
                    my_queue.pop();               // pop because value already processed
                    tab[i][index] = curr_num * 2; // fill tab
                    index++;                      // increase index
                }
            }
        }
    }
    else if (movement == RIGHT)
    {
        for (size_t i = 0; i < Size; i++)
        {
            size_t index = Size-1; // to fill tab
            int *line = tab[i];
            std::queue<int> my_queue = clearArray(line, movement); // queue with no 0
            for (size_t j = 0; j < Size; j++)
            {
                tab[i][j] = 0; // reset line by setting everything to 0
            } 

            while (!my_queue.empty())
            {
                int curr_num = my_queue.front(); // to get value because pop returns void
                my_queue.pop();
                if (curr_num == my_queue.front()) // same number, hence needs fusion
                {
                    my_queue.pop();               // pop because value already processed
                    tab[i][index] = curr_num * 2; // fill tab
                    index--;                      // decrease index
                }
            }
        }
    }

    randomTile();
}

void Damier::consolePrint()
{
    for (size_t i = 0; i < Size; i++)
    {
        for (size_t j = 0; j < Size; j++)
        {
            std::cout << tab[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}
