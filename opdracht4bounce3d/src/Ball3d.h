#pragma once

#include "ofMain.h"

class Ball3d
{
public:
	void setup(int radius, float speedX, float speedY, float speedZ, ofColor color);
	void update();
	void draw();
	float x;
	float y;
	float z;
	
	float speedX;
	float speedY;
	float speedZ;
	float maxX;
	float maxY;
	float maxZ;
	int radius;
	ofColor color;
};