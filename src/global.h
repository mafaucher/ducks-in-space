/*
 * global.h
 *
 * Description:
 * Global variables and constants for Parachute Drop game
 *
 * Last Modified:   11/07/22
 * Changelog:       11/07/22 - window height & width
 */

#ifndef GLOBAL_H
#define GLOBAL_H

// Window
#define HEIGHT      600
#define WIDTH       800

int height = HEIGHT;
int width  = WIDTH;

#include "Camera.h"       // Camera movement
#include "Player.h"       // Player drawing and horizontal movement
#include "ObstacleList.h" // Linked List of obstacles moving vertically

Camera cam;
Player player;
ObstacleList obstacles;

#endif
