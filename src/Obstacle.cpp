#include "Obstacle.h"
#include <stdlib.h>
#include <time.h>

Obstacle::Obstacle()
{
    Obstacle(NULL);
}

Obstacle::Obstacle(Obstacle* prev)
{
    srand( time(NULL) );
    setNext(prev);
    setXPos( rand() % GAME_WIDTH  );
    setYPos( rand() % GAME_HEIGHT );
    setZPos(GAME_DEPTH);
}

// Obstacle::~Obstacle()
        
// void Obstacle::draw()
