/*
 * Camera.h
 * 
 * Description:
 * Camera Class.
 *
 * Last Modified:   11/07/22
 * Changelog:       11/07/22 - Constructor, Accessors, Mutators
 */

#ifndef CAMERA_H
#define CAMERA_H

class Camera
{
    private:
        // Perspective
        float fov;
        float zNear;
        float zFar;

        // Direction
        float xAt;
        float yAt;
        float zAt;
        
    public:
        Camera();
        // ~Camera(); // Using default

        void setPerspective(float fov, float zNear, float zFar);
        void setLookAt(float xAt, float yAt, float zAt);
};

#endif
