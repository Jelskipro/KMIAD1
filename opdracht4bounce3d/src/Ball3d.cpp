#include "Ball3d.h"


void Ball3d::setup(int r, float sX, float sY, float sZ, ofColor c) {
	//maximum amount of x, y and z
	maxX = 400;
	maxY = 400;
	maxZ = 400;

	x = ofRandom(0, maxX);
	y = ofRandom(0, maxY);
	z = ofRandom(0, maxZ);

	speedX = ofRandom(-2, 2);
	speedY = ofRandom(-2, 2);
	speedZ = ofRandom(-2, 2);
	if (r)
		radius = r;
	if (sX)
		speedX = sX;
	if (sY)
		speedY = sY;
	if (sZ)
		speedZ = sZ;

	color = c;
}

//--------------------------------------------------------------
void Ball3d::update()
{
	if (x < radius) {
		x = radius;
		speedX = -speedX;
	}
	else if (x > maxX) {
		x = maxX;
		speedX = -speedX;
	}
	if (y < radius) {
		y = radius;
		speedY = -speedY;
	}
	else if (y > maxY) {
		y = maxY;
		speedY = -speedY;
	}
	if (z < radius) {
		z = radius;
		speedZ = -speedZ;
	}
	else if (z > maxZ) {
		z = maxZ;
		speedZ = -speedZ;
	}

	x += speedX;
	y += speedY;
	z += speedZ;
}

//--------------------------------------------------------------
void Ball3d::draw()
{
	ofSetColor(color);
	ofDrawSphere(x, y, z, radius);
}