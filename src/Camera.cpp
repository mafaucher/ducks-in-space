#include "Camera.h"

Camera::Camera()
{
    setPerspective(45.5, 0.1, 100.0);
    setLookAt(0.0, -1.0, 0.0); 
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
