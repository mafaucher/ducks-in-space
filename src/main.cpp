/*
 * main.cpp
 *
 * Last Modified: 11/07/19
 * 
 * Description:
 * Main program file.
 */

#include <GL/glut.h>

using namespace std;

#include "global.h"   // Global variables and constants
#include "display.h"  // GLUT Display Function
#include "reshape.h"  // GLUT Reshape Function
#include "input.h"    // GLUT Keyboard/Mouse Input Functions
#include "idle.h"     // GLUT Idle Function

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
    glutSpecialFunc(specialKeys);
    glutIdleFunc(idle);
    glutMainLoop();

    exit(0);
}
