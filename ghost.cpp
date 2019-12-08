#include "Ghost.h"
#include "Particle.h"

Ghost::Ghost(float scale_factor, Vec3 color) : cloth(scale_factor*8.5, scale_factor*8.5,55,45),
ball_radius(scale_factor*1.8),
ball_pos(4.5 * scale_factor,-1.87 *scale_factor ,-4 *scale_factor),
move_speed(0.1,0,0)
{
    this->color = color;
    cloth.setColor(color);
}

void Ghost::display()
{
    move();
    cloth.addForce(Vec3(0,-0.3,0)*TIME_STEPSIZE2); // add gravity each frame, pointing down
    cloth.windForce(-move_speed*3);
    cloth.timeStep(); // calculate the particle positions of the next frame
    cloth.ballCollision(ball_pos,ball_radius); // resolve collision with the ball
    cloth.drawShaded(); // finally draw the cloth with smooth shading
    glPushMatrix(); // to draw the ball we use glutSolidSphere, and need to draw the sphere at the position of the ball
    glTranslatef(ball_pos.f[0],ball_pos.f[1],ball_pos.f[2]); // hence the translation of the sphere onto the ball position
    glColor3f(color.f[0],color.f[1],color.f[2]);
    //glColor3f(color.f[0],color.f[1],color.f[2]);
    glutSolidSphere(ball_radius,50,50); // draw the ball, but with a slightly lower radius, otherwise we could get ugly visual artifacts of cloth penetrating the ball slightly
    glPopMatrix();
}

void Ghost::move()
{
    //we need to move both the ball and the cloth
    ball_pos += move_speed;
    cloth.move(move_speed, ball_pos);
}
