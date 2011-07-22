#include "Player.h"

#include <GL/glut.h>

using namespace std;

Player::Player()
{
    setLives(3);
    setLives(3);
    setPoints(0);
    setXPos(0);
    setZPos(0);
}

// Player::~Player(); // Using default

void Player::draw()
{
    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glutSolidCube(1.0);
    glPopMatrix();
}
