/*
 * ObstacleList.cpp
 *
 * Description:
 * Singly Linked List of Obstacles Main Obstacle Class.
 *
 * Last Modified:   11/07/22
 * Changelog:
 */

#include "ObstacleList.h"

void add()
{
    setLast(new Obstacle);
    if (first == NULL)
        setFirst(last);
}

void remove()
{
    Obstacle* temp = first;
    setFirst( first->getNext() );
    delete temp;
}
