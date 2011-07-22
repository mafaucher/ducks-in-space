/*
 * ObstacleList.h
 *
 * Description:
 * Singly Linked List of Obstacles.
 *
 * Last Modified:   11/07/22
 * Changelog:       11/07/22 - Constructor, Accessors, Mutators
 */

#ifndef OBSTACLE_LIST_H
#define OBSTACLE_LIST_H

#include "Obstacle.h"

class ObstacleList
{
    private:
        Obstacle* first;
        Obstacle* last;

    public:
        ObstacleList() {}
        // ~ObstacleList(); // Using default
        
        void setFirst(Obstacle* first) { this->first = first; }
        void setLast(Obstacle* last)   { this->last = last; }
        Obstacle* getFirst() { return this->first; }
        Obstacle* getLast()  { return this->last; }

        void add();
        void remove();
};

#endif
