#include "ObstacleList.h"

// Add a random obstacle to the tail of the list
void ObstacleList::add()
{
    Obstacle newObs(last);
    setLast(&newObs);
    if (!first)
        setFirst(&newObs);
}

// Remove the first obstacle in the list
void ObstacleList::remove()
{
    Obstacle* temp = first;
    setFirst( first->getNext() );
    delete &temp;
}

void ObstacleList::draw()
{
    Obstacle* temp = first;
    while (temp)
    {
        temp->draw();
        temp = temp->getNext();
    }
}
