/*
 * global.h
 *
 * Description:
 * Global variables and constants for Parachute Drop game
 *
 * Last Modified:   11/07/19
 * Changelog:       
 */

#ifndef GLOBAL_H
#define GLOBAL_H

#include <math.h>

#define HEIGHT      600
#define WIDTH       800


/* Window */

int height = HEIGHT;
int width  = WIDTH;


/* Camera */

// Perspective
float fov = 45.0;
float zNear = 0.1;
float zFar = 100.0;

// Position
float cx = 0.0;
float cy = 100.0;
float cz = 0.0;

// Direction
float dx = 0.0;
float dy = 0.0;
float dz = -1.0;

#endif
