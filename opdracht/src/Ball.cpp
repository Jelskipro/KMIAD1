#include "Ball.h"


void Ball::setup()
{
	x = ofRandom(0, ofGetWidth());
	y = ofRandom(0, ofGetHeight());

	speedX = ofRandom(-3, 3);
	speedY = ofRandom(-3, 3);

	radius = 40;

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
	ofSetColor(ofColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255)));
	ofDrawCircle(x, y, radius);
}