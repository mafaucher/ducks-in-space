/*
 * reshape.cpp
 *
 * Last Modified: 11/07/19
 * 
 * Description:
 * GLUT Reshape Function
 */

// OpenGL Reshape Function
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

