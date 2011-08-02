#include "Obstacle.h"
#include <stdlib.h>
#include <time.h>

Obstacle::Obstacle(Obstacle* prev=NULL)
{
    srand( time(NULL) );
    setXPos( rand() % GAME_WIDTH  );
    setYPos( rand() % GAME_HEIGHT );
    setZPos(GAME_DEPTH);
    prev->setNext(this);
}

// Obstacle::~Obstacle() // Using default
        
void Obstacle::draw()
{
    glPushMatrix();
    glTranslatef(getXPos(), getYPos(), getZPos());
    glutWireTeapot(1.0);
    glPopMatrix();
}
