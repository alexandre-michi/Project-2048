#include "damier.h"
#include <stdlib.h>
#include <iostream>
#include <ctime> // to "unseed" rand function with srand and ctime

using namespace std;


/*
 * Constructeur : allocation de mémoire et initialisation à zéro
 * @params : taille du damier (ici obligatoire 4)
 */
Damier::Damier(int size)
{
    Size = size;
    tab = new int*[Size];
    last_tab = new int*[Size];
    score = 0;
    already_undo = false;

    for(int i=0; i<Size; i++){
        tab[i] = new int[Size];
        last_tab[i] = new int[Size];
        for(int j=0; j<Size; j++){
            tab[i][j] = 0;
        }
    }

    randomTile();
}

/*
 * Destructeur
 */
Damier::~Damier()
{
    std::cout << "Destruction !" << std::endl;
}

/*
 * Renvoie le damier
 */
int ** Damier::getTab(){
    return tab;
}

/*
 *  Place un 2 ou un 4 au hasard sur le damier
 */
void Damier::randomTile()
{
    srand(time(NULL));
    int i = rand() % Size;
    int j = rand() % Size;

    // On s'assure que la case est vide, sinon on en cherche une autre
    while(tab[i][j] != 0){
        i = rand() % Size;
        j = rand() % Size;
    }

    tab[i][j] = 2; // Possibilité de changer avec 4
}

/*
 * Contrôle si on peut réaliser un mouvement dans le damier
 */
bool Damier::isDefeat()
{
    for (int i = 0; i < Size; i++)
    {
        for (int j = 0; j < Size; j++)
        {
            int t = tab[i][j]; 
            // there is an empty tile
            if (t == 0){ return false;}
            // there is a possibility for fusion :
            else if (i - 1 >= 0 && t == tab[i - 1][j]){ return false;}
            else if (i+1 < Size && t == tab[i + 1][j]){ return false;}
            else if (j - 1 >= 0 && t == tab[i][j - 1]){ return false;}
            else if (j + 1 < Size && t == tab[i][j + 1]){return false;}
        } 
    }
    return true;   
}

/*
 * Renvoie une file contenant la ligne/colonne concernée par le mouvement (sans les éventuels zéros)
 * @params t : damier
 * @params mvt : mouvement
 */

std::queue<int> Damier::clearArray(const int t[], int mvt)
{
    std::queue<int> my_queue; // lifo
    // remplissage par la gauche
    if (mvt == UP || mvt == LEFT)
    {
        for (int i = 0; i < Size; i++)
        {
            if (t[i] != 0){ my_queue.push(t[i]);}
        }
    }
    // remplissage par la droite
    else
    {        
        for (int i = Size-1; i >= 0; i--)
        {
            if (t[i] != 0){ my_queue.push(t[i]);}
        }
    }
    return my_queue;
}

/*
 * Réalise un mouvement global sur tout le damier
 * @params mvt : mouvement demandé par le joueur
 */
void Damier::process(int movement)
{
    cout << "Process avec movement = " << movement << endl;

    // If player has not used his 'undo' ability yet, save the current tab before playing...
    if (already_undo != true){
        copyArray(tab, last_tab);
    }

    // Then play
    if (movement == UP) 
    {
        for (int j = 0; j < Size; j++)
        {
            int index = 0; // to fill tab
            int *col = new int[Size];
            for (int i = 0; i < Size; i++)
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
                    score += curr_num * 2;        // update score
                    index++;                      // increase index
                }
                else // no fustion needed
                {
                    tab[index][j] = curr_num; // fill tab with curr_num (not fusionned)
                    index++;                  // increase index
                }
            }
        }
    }
    else if (movement == DOWN)
    {
        for (int j = 0; j < Size; j++)
        {
            int index = Size-1; // to fill tab
            int *col = new int[Size];
            for (int i = 0; i < Size; i++)
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
                    score += curr_num * 2;        // update score
                    index--;                      // increase index
                }
                else // no fustion needed
                {
                    tab[index][j] = curr_num; // fill tab with curr_num (not fusionned)
                    index--;                  // increase index
                }
            }
        }
    }
    else if (movement == LEFT)
    {
        for (int i = 0; i < Size; i++)
        {
            int index = 0; // to fill tab
            int *line = tab[i];
            std::queue<int> my_queue = clearArray(line, movement); // queue with no 0
            
            for (int j = 0; j < Size; j++)
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
                    score += curr_num * 2;        // update score
                    index++;                      // increase index
                }
                else // no fustion needed 
                {
                    tab[i][index] = curr_num;    // fill tab with curr_num (not fusionned)
                    index++;                      // increase index
                }
            }
        }
    }
    else if (movement == RIGHT)
    {
        for (int i = 0; i < Size; i++)
        {
            int index = Size-1; // to fill tab
            int *line = tab[i];
            std::queue<int> my_queue = clearArray(line, movement); // queue with no 0
            for (int j = 0; j < Size; j++)
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
                    score += curr_num * 2;        // update score
                    index--;                      // decrease index
                }
                else // no fustion needed
                {
                    tab[i][index] = curr_num; // fill tab with curr_num (not fusionned)
                    index--;                  // increase index
                }
            }
        }
    }

    // TODO : create error if not the right movement

    randomTile();
}

/*
 * Affichage dans la console
 */
void Damier::consolePrint()
{
    for (int i = 0; i < Size; i++)
    {
        for (int j = 0; j < Size; j++)
        {
            std::cout << tab[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

void Damier::undo(){
    if (already_undo == false){
        copyArray(last_tab, tab);
        already_undo = true;
    }
}

void Damier::copyArray(int ** values, int ** copy){
    for (int i = 0; i < Size; i++)
    {
        for (int j = 0; j < Size; j++)
        {
            copy[i][j] = values[i][j];
        }
    }
}
