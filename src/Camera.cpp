#include "Camera.h"

Camera::Camera()
{
    setPerspective(45.0, 0.1, GAME_DEPTH);
    setLookAt(0.0, 0.0, -1.0);
}

// Camera::~Camera(); // Using default

void Camera::setPerspective(float fov, float zNear, float zFar)
{
    this->fov   = fov;
    this->zNear = zNear;
    this->zFar  = zFar;
}

void Camera::setLookAt(float x, float y, float z)
{
    this->xAt = x;
    this->yAt = y;
    this->zAt = z;
}
