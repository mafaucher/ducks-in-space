#include <stdlib.h>
#include <time.h>
#include "Obstacle.h"

Obstacle::Obstacle()
{
    Obstacle(NULL);
}

Obstacle::Obstacle(Obstacle* prev)
{
    srand( time(NULL) );
    setNext(prev);
    setXPos( rand() % 101 - 50); // Random from (-50 to 50)
    setZPos( rand() % 101 - 50);
    setYPos(0);
}

// Obstacle::~Obstacle()
        
// void Obstacle::draw()
