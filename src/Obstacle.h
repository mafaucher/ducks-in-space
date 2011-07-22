/*
 * Obstacle.h
 *
 * Description:
 * Main Obstacle Class.
 *
 * Last Modified:   11/07/22
 * Changelog:       11/07/22 - Constructor, Accessors, Mutators
 */

#ifndef OBSTACLE_H
#define OBSTACLE_H

class Obstacle
{
    private:
        Obstacle* next;
        float xPos;
        float zPos;
        float yPos;

    public:
        Obstacle();
        Obstacle(Obstacle* prev);
        // ~Obstacle(); // Using default
        
        void setNext(Obstacle* next) { this->next = next; }
        void setXPos(float x)        { this->xPos = x; }
        void setYPos(float y)        { this->yPos = y; }
        void setZPos(float z)        { this->zPos = z; }
        
        Obstacle* getNext() { return this->next; }
        float getXPos()     { return this->xPos; }
        float getZPos()     { return this->zPos; }
        float getYPos()     { return this->yPos; }

        // void draw();
};

#endif
