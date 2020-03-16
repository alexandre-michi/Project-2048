#include "damier.h"
#include <iostream>


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
