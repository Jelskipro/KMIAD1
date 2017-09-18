#include "Ball.h"


void Ball::setup(int r, float sX, float sY, ofColor c) {
	x = ofRandom(0, ofGetWidth());
	y = ofRandom(0, ofGetHeight());

	speedX = ofRandom(-2, 2);
	speedY = ofRandom(-2, 2);
	if (r)
		radius = r;
	if (sX)
		speedX = sX;
	if (sY)
		speedY = sY;

	color = c;
}

//--------------------------------------------------------------
void Ball::update()
{
	if (x < radius) {
		x = radius;
		speedX = -speedX;
	}
	else if (x > ofGetWidth()) {
		x = ofGetWidth();
		speedX = -speedX;
	}
	if (y < radius) {
		y = radius;
		speedY = -speedY;
	}
	else if (y > ofGetHeight()) {
		y = ofGetHeight();
		speedY = -speedY;
	}

	x += speedX;
	y += speedY;
}

//--------------------------------------------------------------
void Ball::draw()
{
	ofSetColor(color);
	ofDrawCircle(x, y, radius);
}