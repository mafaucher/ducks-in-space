/*
 * main.cpp
 *
 * Description:
 * Main program file including GLUT Functions for the OpenGL game
 * 'Parachute Drop'.
 *
 * Last Modified:   11/07/19
 * Changelog:       11/07/19 - Basic GLUT functions
 *                  11/08/02 - Tested basic classes
 *                  11/08/05 - Started level design
 *                  11/08/06 - Integrated ObstacleList
 *                           - Timer functions create/delete obstacles
 */

#include <cstdlib>
#include <cmath>
#include <ctime>
#include <GL/glut.h>

#include "global.h"       // Global variables and constants
#include "Camera.h"       // Camera movement
#include "Player.h"       // Player drawing and x/y movement
#include "ObstacleList.h" // Linked List of obstacles and z movement

int width  = WIDTH;       // Current window width
int height = HEIGHT;      // Current window height

enum gameState { MENU, LEVEL, GAME_OVER };
gameState state = MENU;

int level = 0;

float bgSize = 0.0;

// Fog
GLfloat fogColor[3] = { 0.0, 0.0, 0.0 };
float fogStart = 0.0;
float fogEnd   = 0.0;

// Game speed (milliseconds)
int speedMove   = 100;
int speedCreate = 1000;

Camera cam;
Player player;
ObstacleList obstacles;

// TESTING 
float xRot = 0.0;
float yRot = 0.0;
float xPrev = 0.0;
float yPrev = 0.0;

// Mouse
float sensitivity = 0.2;

// Game values for Level 1
void setLevel1()
{
    state = LEVEL;
    level = 1;
    
    // Start fog at 3/4 of play field for Level 1
    fogColor[R] = 0.9; fogColor[G] = 0.9; fogColor[B] = 1.0;
    fogStart = -(GAME_DEPTH) * FOGEND_L1*0.75;
    fogEnd   = -(GAME_DEPTH) * FOGEND_L1;

    speedCreate = 3000;
}

// Game values for Level 2
void setLevel2()
{
    state = LEVEL;
    level = 2;
    
    // Start fog at 3/4 of play field for Level 2
    fogColor[R] = 0.6; fogColor[G] = 0.3; fogColor[B] = 0.2;
    fogStart = -(GAME_DEPTH) * FOGEND_L2*0.75;
    fogEnd   = -(GAME_DEPTH) * FOGEND_L2;

    speedCreate = 2000;
}

void setLevel3()
{
    state = LEVEL;
    level = 3;

    // Start fog at 3/4 of play field for Level 3
    fogColor[R] = 0.3; fogColor[G] = 0.2; fogColor[B] = 0.3;
    fogStart = -(GAME_DEPTH) * FOGEND_L3*0.75;
    fogEnd   = -(GAME_DEPTH) * FOGEND_L3;

    speedCreate = 1000;
}

void drawWorld()
{
    // Light
    GLfloat ambientLight[] = { 0.2, 0.2, 0.2, 1 };
    glLightModelfv( GL_LIGHT_MODEL_AMBIENT, ambientLight );

    glEnable(GL_LIGHT0);
    GLfloat lightColor0[] = { 0.8, 0.8, 0.8 };
    GLfloat lightPos0[] = { -0.5, 1, 0.25, 0.0 };
    glLightfv( GL_LIGHT0, GL_DIFFUSE, lightColor0 );
    glLightfv( GL_LIGHT0, GL_POSITION, lightPos0 );

    // Draw Background to cover field of view at GAME_DEPTH
    glDisable(GL_FOG);
    bgSize = ( GAME_DEPTH / cos(cam.fov/2) );
    glColor3f(fogColor[R], fogColor[G], fogColor[B]);
    glBegin(GL_QUADS);
    glVertex3f( (GAME_WIDTH/2)-bgSize, (GAME_HEIGHT/2)-bgSize, GAME_DEPTH );
    glVertex3f( (GAME_WIDTH/2)-bgSize, (GAME_HEIGHT/2)+bgSize, GAME_DEPTH );
    glVertex3f( (GAME_WIDTH/2)+bgSize, (GAME_HEIGHT/2)+bgSize, GAME_DEPTH );
    glVertex3f( (GAME_WIDTH/2)+bgSize, (GAME_HEIGHT/2)-bgSize, GAME_DEPTH );
    glEnd();
    
    // Set Fog
    glEnable(GL_FOG);
    glFogfv( GL_FOG_COLOR, fogColor);
    glFogi( GL_FOG_MODE, GL_LINEAR);
    glFogi( GL_FOG_START, fogStart);
    glFogi( GL_FOG_END, fogEnd);
}

// GLUT Display Function
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();

	player.draw();

    switch (state)
    {
        case MENU:
            

        break;
        case LEVEL:
            
            glRotatef(xRot/10, 1.0, 0.0, 0.0);
            glRotatef(yRot/10, 0.0, 1.0, 0.0);
            // TODO: draw Player;
            drawWorld();
            obstacles.drawAll(level);

        break;
        case GAME_OVER:

        break;
    }
    
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
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective( cam.fov, w/h, cam.zNear, cam.zFar );
    glMatrixMode(GL_MODELVIEW);
}

// GLUT Keyboard Function
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27: // <ESC> to quit
            exit(0);
    }
}

// GLUT Special Keyboard Function
void specialKey(int key, int x, int y)
{
    switch (key)
    {
        case GLUT_KEY_F1:
            setLevel1();
        break;
        case GLUT_KEY_F2:
            setLevel2();
        break;
        case GLUT_KEY_F3:
            setLevel3();
        break;
    }

    // Player movement (allows simultaneous key presses)
    if (key == GLUT_KEY_UP)
    {
		player.Move(0,PLAYER_STEP);
    }
    if (key == GLUT_KEY_DOWN)
    {
        player.Move(0,-PLAYER_STEP);
    }
    if (key == GLUT_KEY_LEFT)
    {
        player.Move(-PLAYER_STEP,0);
    }
    if (key == GLUT_KEY_RIGHT)
    {
        player.Move(PLAYER_STEP,0);
    }
    glutPostRedisplay();
}

// GLUT mouse Function
void mouse(int x, int y)
{
    int xDiff = x - xPrev;
    int yDiff = y - yPrev;
    xPrev = x;
    yPrev = y;
    //if (xRot >= xMouseMax && )
    xRot += (float) yDiff * sensitivity;
    yRot += (float) xDiff * sensitivity;
}

// GLUT Timer Function for obstacles
void moveTimer(int value)
{
    if (state == LEVEL)
    {
        // Move Obstacles
        obstacles.moveAll(level);
        
        // Remove Obstacles that exit world
        if ( !obstacles.isEmpty() && (obstacles.getFirst())->getZPos() >= 0 )
        {
            // Detect collisions
            float xDiff = player.getXPos() - (obstacles.getFirst())->getXPos();
            float yDiff = player.getYPos() - (obstacles.getFirst())->getYPos();
            
            obstacles.remove();

            if (xDiff < 5 || yDiff < 5) {
                // TODO: COLLISION DETECTION - IMPLEMENT PLAYER/OBS SIZE
            }
        }

        glutPostRedisplay();
    }
    glutTimerFunc(speedMove, moveTimer, 0);
}

void createTimer(int value)
{
    if (state == LEVEL)
    {
        // Create an obstacle at a random location
        obstacles.insert( rand() % GAME_WIDTH, rand() % GAME_HEIGHT, GAME_DEPTH );
    }
    glutTimerFunc(speedCreate, createTimer, 0);
}

// OpenGL Initialisation
void init(void)
{
    srand( time(NULL) );
    glClearColor(0.0, 0.0, 0.0, 0.0);

    glShadeModel(GL_SMOOTH);

    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_FOG);
    glEnable(GL_LIGHTING);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);

    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

    glEnable(GL_BLEND);
    glBlendFunc(  GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
}

int main(int argc, char** argv)
{
    // GLUT initialisation and callbacks
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(width, height);
    glutCreateWindow("Helicopter");
    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKey);
    glutPassiveMotionFunc(mouse);

    glutTimerFunc(speedMove, moveTimer, 0);
    glutTimerFunc(speedCreate, createTimer, 0);

    glutMainLoop();

    exit(0);
}
