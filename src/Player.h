/*
 * Player.h
 * 
 * Description:
 * Player Class.
 *
 * Last Modified:   11/07/22
 * Changelog:       11/07/22 - Constructor, Accessors, Mutators
 */

#ifndef PLAYER_H
#define PLAYER_H

class Player
{
    private:
        int lives;
        int health;
        int points;
        float xPos;
        float zPos;

    public:
        Player();
        // ~Player(); // Using default

        void setLives(int lives)   { this->lives   = lives; }
        void setHealth(int health) { this->health  = health; }
        void setPoints(int points) { this->points  = points; }
        void setXPos(float xPos)   { this->xPos    = xPos; }
        void setZPos(float zPos)   { this->zPos    = zPos; }

        int getLives()  { return this->lives; }
        int getHealth() { return this->health; }
        int getPoints() { return this->points; }
        float getXPos() { return this->xPos; }
        float getZPos() { return this->zPos; }

        void draw();
};

#endif
