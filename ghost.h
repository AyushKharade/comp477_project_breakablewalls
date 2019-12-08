#ifndef COMP_477_A1_PROBLEM_1_GHOST_H
#define COMP_477_A1_PROBLEM_1_GHOST_H

#include "Vec3.h"
#include "Cloth.h"
#include <GL/glew.h>
#include "glut.h"
#define TIME_STEPSIZE2 0.5*0.5 // how large time step each particle takes each frame

class Ghost 
{
private:
    Vec3 ball_pos;
    float ball_radius;
    Cloth cloth;
    Vec3 move_speed;
    Vec3 color;

public:
    Ghost(float scale_factor, Vec3 color);
    void display();
    void move();
    inline void setMoveSpeed(Vec3 speed){move_speed = speed;}
    inline void setColor(Vec3 color){this->color = color;}
};

#endif
