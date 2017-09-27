#include "Planet.h"


void Planet::setup(int r, float rX, float rY, float rZ, float lO, float lA, float rR, float rS, ofVec3f rP, ofColor c) {
	
	if (r)
		radius = r;
	if (rX)
		rotateX = rX;
	if (rY)
		rotateY = rY;
	if (rZ)
		rotateZ = rZ;
	if (lO)
		longitude = lO;
	if (lA)
		latitude = lA;
	if (rR)
		rotationRadius = rR;
	if (rS)
		rotationSpeed = rS;
	
	planet.setRadius(radius);
	rotationPoint = rP;
	color = c;
}

//--------------------------------------------------------------
void Planet::update()
{
	if (longitude > 0)
	{
		longitude = longitude + rotationSpeed;

	}
	if (latitude > 0)
	{
		latitude = latitude + rotationSpeed;

	}
}

//--------------------------------------------------------------
void Planet::draw()
{
	//planet.rotate(60, rotateX, rotateY, rotateZ);
	planet.orbit(longitude, latitude, rotationRadius, rotationPoint);
	ofSetColor(color);
	planet.draw();

}