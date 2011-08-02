/*
 * main.cpp
 *
 * Description:
 * Main program file including GLUT Functions for the OpenGL game
 * 'Parachute Drop'.
 *
 * Last Modified:   11/07/19
 * Changelog:       11/07/19 - Basic GLUT functions
 */

#include <GL/glut.h>

using namespace std;

#include "global.h"       // Global variables and constants
#include "Camera.h"       // Camera movement
#include "Player.h"       // Player drawing and x/y movement
#include "ObstacleList.h" // Linked List of obstacles and z movement

int width  = WIDTH;       // Current window width
int height = HEIGHT;      // Current window height

Camera cam;
Player player;
ObstacleList obstacles;

// GLUT Display Function
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();

    // Code here
    //player.draw();
    obstacles.draw();
    
    glPopMatrix();
    glutSwapBuffers();
}

// GLUT Reshape Function
void reshape(int w, int h)
{
    // Set global variables & adjust view
    width = w;
    height = h;
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
}

// GLUT Keyboard Function
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'o':
            obstacles.add();
        break;
        case 27: // <ESC> to quit
            exit(0);
    }
}

// GLUT Special Keyboard Function
void specialKey(int key, int x, int y)
{

}

// GLUT Idle Function
void idle(void)
{
    glutPostRedisplay();
}

// OpenGL Initialisation
void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
}

int main(int argc, char** argv)
{
    // GLUT initialisation and callbacks
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(width, height);
    glutCreateWindow("Parachute Drop");
    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKey);
    glutIdleFunc(idle);
    glutMainLoop();

    exit(0);
}
