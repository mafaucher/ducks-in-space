/* 
 * display.cpp
 *
 * Last Modified: 11/07/19
 * 
 * Description:
 * GLUT Display Function for OpenGL game 'Parachute Drop'
 */

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();

    glPopMatrix();
    glutSwapBuffers();
}
