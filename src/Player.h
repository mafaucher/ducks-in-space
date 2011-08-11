/*
 * Player.h
 * 
 * Description:
 * Player Class.
 *
 * Last Modified:   11/07/22
 * Changelog:       11/07/22 - Constructor, Accessors, Mutators
 *                  11/08/02 - Adapted for helicopter
 */

#ifndef PLAYER_H
#define PLAYER_H
#include "global.h"

class Player
{
    private:
        int lives;
        int health;
        int points;
        float xPos;
        float yPos;
		float zPos;

		float xLean;
		float zLean;

		float rad;

    public:
        Player();
        // ~Player(); // Using default

        void setLives(int lives)   { this->lives   = lives; }
        void setHealth(int health) { this->health  = health; }
        void setPoints(int points) { this->points  = points; }
        void addPoints(int points) { this->points += points; }
        void setXPos(float xPos)   { this->xPos    = xPos; }
        void setYPos(float yPos)   { this->yPos    = yPos; }
		void setZPos(float zPos)   { this->zPos    = zPos; }
		void setXLean(float xLean) { this->xLean   = xLean; }
		void setZLean(float zLean) { this->zLean   = zLean; }
		void setRad(float rad)	   {this->rad		= rad; }

        int getLives()  { return this->lives; }
        int getHealth() { return this->health; }
        int getPoints() { return this->points; }
        float getXPos() { return this->xPos; }
        float getYPos() { return this->yPos; }
		float getZPos() { return this->zPos; }
	    float getXLean() { return this->xLean; }
        float getZLean() { return this->zLean; }
		float getRad()	{return this->rad;	}


        void draw(bool testMode);
		void Move(float stepX, float stepY);
		void Lean();
};

#endif
