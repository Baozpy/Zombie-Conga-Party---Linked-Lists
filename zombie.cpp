/*

    Description: The class of zombie
*/
#include <stdlib.h>
#include <time.h>
#include "zombie.h"

Zombie::Zombie()
{
    srand(time(NULL));
    int n = rand() % 6;
    switch(n)
    {
        case 0:
            color = 'R';
            break;
        case 1:
            color = 'Y';
            break;
        case 2:
            color = 'G';
            break;
        case 3:
            color = 'B';
            break;
        case 4:
            color = 'M';
            break;
        case 5:
            color = 'C';
            break;
    }
}

char Zombie::get()
{
    return color;
}
