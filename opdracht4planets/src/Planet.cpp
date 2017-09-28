#include "Planet.h"

void Planet::setup(int r, float lO, float lA, float rR, float rS, ofVec3f rP, ofColor c) {
	if (r)
		radius = r;
	if (lO)
		longitude = lO;
	if (lA)
		latitude = lA;
	if (rR)
		rotationRadius = rR;
	if (rS)
		rotationSpeed = rS;

	rotationPoint = rP;
	color = c;
}
void Planet::update() {
	planet.setRadius(radius);
	moon.setRadius(20);

	if (longitude < 360)
	{
		longitude = longitude + rotationSpeed;
	}
	else
	{
		longitude = 0;
	}
}
void Planet::draw() {
	
	planet.orbit(longitude, latitude, rotationRadius, rotationPoint);
	
	ofLog() << radius;

	ofSetColor(color);
	planet.draw();

	moon.setParent(planet, false);

	moon.orbit(longitude, latitude, 200, ofVec3f(0, 0, 0));

	moon.draw();
}