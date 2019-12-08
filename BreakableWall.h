#pragma once


#include "Vec3.h"
#include <GL/glew.h>
#include "glut.h"
#define TIME_STEPSIZE2 0.5*0.5 // how large time step each particle takes each frame

class BreakableWall
{
private:
	//position variables:
	float xPosition;
	float yPosition;
	float zPosition;
	

	float size;

	bool isDestroyed;

	float distanceToPacMan;


public:
	//BreakableWall(Vec3 spawnLocation, float wallSize );
	BreakableWall(float xPos, float yPos, float zPos, float wallSize );

	void Draw();			//; render the wall
	void Destroy();      // do the destruction particle effect and stop rendering.

	bool GetDestroyed()
	{
		return isDestroyed;
	}

	void SetDestroyWall()
	{
		isDestroyed = true;
	}
};