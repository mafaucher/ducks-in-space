/*
 * main.cpp
 *
 * Description:
 * Main program file including GLUT Functions for the OpenGL game
 * 'Parachute Drop'.
 *
 * Last Modified:   11/07/21
 * Changelog:       
 */

#include <GL/glut.h>

using namespace std;

#include "global.h"       // Global variables and constants
#include "Camera.h"       // Camera movement
#include "Player.h"       // Player drawing and horizontal movement
#include "ObstacleList.h" // Linked List of obstacles moving vertically

// GLUT Display Function
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();

    // Code here
    player.draw();
    
    glPopMatrix();
    glutSwapBuffers();
}

// GLUT Reshape Function
void reshape(int w, int h)
{
    width = w;
    height = h;
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glLoadIdentity();
    gluPerspective((GLfloat) fov, (GLfloat) w / (GLfloat) h, zNear, zFar);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(cx, cy, cz, cx + dx, cy + dy, cz + dz, 0.0, 0.0, -1.0);
}

// GLUT Keyboard Function
void keyboard(unsigned char key, int x, int y)
{

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
    glShadeModel(GL_FLAT);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
}

int main(int argc, char** argv)
{
    Player player;
    ObstacleList obstacles;

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
