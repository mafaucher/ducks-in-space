/*
 * main.cpp
 *
 * Last Modified: 11/07/19
 * 
 * Description:
 * Main program file including GLUT Functions
 */

#include <GL/glut.h>

using namespace std;

#include "global.h"   // Global variables and constants

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    // Code here
    glPopMatrix();
    glutSwapBuffers();
}

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

void keyboard(unsigned char key, int x, int y)
{

}

void specialKey(int key, int x, int y)

{

}

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
