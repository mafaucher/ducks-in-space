/*
 * Obstacle.cpp
 *
 * Description:
 * Main Obstacle Class.
 *
 * Last Modified:   11/07/22
 * Changelog:
 */

#include <stdlib.h>
#include <time.h>
#include "Obstacle.h"

Obstacle()
{
    Obstacle(NULL);
}

Obstacle(const Obstacle &prev)
{
    srand( time(NULL) );
    setNext(prev);
    setXPos( rand() % 101 - 50); // Random from (-50 to 50)
    setZPos( rand() % 101 - 50);
    setYPos(0);
}

// ~Obstacle() 
        
// void draw()

#endif
