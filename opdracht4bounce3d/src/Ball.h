#pragma once

#include "ofMain.h"

class Ball
{
public:
	void setup(int radius, float speedX, float speedY, ofColor color);
	void update();
	void draw();
	float x;
	float y;
	float speedX;
	float speedY;
	int radius;
	ofColor color;
};