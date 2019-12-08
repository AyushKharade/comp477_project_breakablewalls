/*
make:
constructor --> initialize with size, and coordinate location.
destroy function. (bool if destroyed --> if yes then dont draw it.

breaking part --> do it like a particle system, spawns smaller wall models (cubes of same sizes which fall around.)

if possible, lets do a wall texture.
*/

#include"BreakableWall.h"

BreakableWall::BreakableWall(float xPos, float yPos, float zPos, float wallSize)
{
	xPosition = xPos;
	yPosition = yPos;
	zPosition = zPos;
	size = wallSize;
	isDestroyed = false;
}

void BreakableWall::Draw()
{
	//draw wall at location
	glNormal3f(0.0f, 0.0f, 1.0f);
	glColor3f(1, 0, 0); // Red
	glPushMatrix();
	glTranslatef(xPosition, yPosition, zPosition);
	glutSolidCube(size);
	glPopMatrix();
}