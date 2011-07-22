/*
 * Player.cpp
 *
 * Description:
 * Player Class.
 *
 * Last Modified:   11/07/22
 * Changelog:       
 */

#include "Player.h"

#include <GL/glut.h>

using namespace std;

Player()
{
    setLives(3);
    setLives(3);
    setPoints(0);
    setXPos(0);
    setZPos(0);
}

// ~Player();

void draw()
{
    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glutSolidCube(1.0);
    glPopMatrix();
}
