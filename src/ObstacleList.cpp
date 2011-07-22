#include "ObstacleList.h"

void ObstacleList::add()
{
    setLast(new Obstacle);
    if (first)
        setFirst(last);
}

void ObstacleList::remove()
{
    Obstacle* temp = first;
    setFirst( first->getNext() );
    delete temp;
}
