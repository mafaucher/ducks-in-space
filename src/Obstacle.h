/*
 * Obstacle.h
 *
 * Description:
 * Main Obstacle Class.
 *
 * Last Modified:   11/07/22
 * Changelog:       11/07/22 - Constructor, Accessors, Mutators
 *                  11/08/02 - Adapted for helicopter
 *                  11/08/06 - Implemented as Linked List Node
 */

#include "global.h"

#ifndef OBSTACLE_H
#define OBSTACLE_H

class Obstacle
{
	private:
		float xPos, yPos, zPos;                 // Object coordinates
		int xAxis, yAxis, zAxis;				// Axes of rotation
		float spinAngle, colorGen;				// Angle of rotation, color generator
		Obstacle* next;                         // A pointer to the next node		
		objType objtype;						// type of 'this' object
        bool crash;

	public:
		Obstacle();                             //default constructor is added
		Obstacle(float,float,float,Obstacle*);  // Regular constructor
		Obstacle(float,float,float,Obstacle*,objType);  // Regular constructor
		//~Obstacle();                          // Destructor

		void setXPos(float);
		float getXPos();

		void setYPos(float);
		float getYPos();

		void setZPos(float);
		float getZPos();

		void setNext(Obstacle*); // Changes next
		Obstacle* getNext();     // Returns next

		void setObjType(objType); //sets type
		objType getObjType();	//gets Type

        void setCrash(bool);
        bool getCrash();

		void setSunPos(float,float,float,float);

        void draw(int level);
        void move(int level);

        bool collide(int xDiff, int yDiff);
        void explode();
};

#endif
