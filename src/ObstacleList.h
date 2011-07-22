/*
 * ObstacleList.h
 *
 * Description:
 * Singly Linked List of Obstacles Main Obstacle Class.
 *
 * Last Modified:   11/07/22
 * Changelog:
 */

#ifndef OBSTACLE_LIST_H
#define OBSTACLE_LIST_H

class ObstacleList
{
    private:
        Obstacle* first;
        Obstacle* last;

    public:
        ObstacleList() { first = last = NULL; }
        // ~ObstacleList(); // Using default
        
        void setFirst(Obstacle* first) { this->first = first; }
        void setLast(Obstacle* last)   { this->last = last; }
        Obstacle* getFirst() { return this->first; }
        Obstacle* getLast()  { return this->last; }

        void add();
        void remove();
};

#endif
