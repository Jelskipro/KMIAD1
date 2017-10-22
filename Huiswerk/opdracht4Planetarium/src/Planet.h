#pragma once

#include "ofMain.h"

class Planet
{
public:
	void setup(int radius, float rotateX, float rotateY, float rotateZ, float longitude, float latitude, float rotationRadius, float rotationSpeed, ofVec3f rotationPoint, ofColor color);
	void update();
	void draw();

	int radius;
	float rotateX;
	float rotateY;
	float rotateZ;
	float longitude;
	float latitude;
	float rotationRadius;
	float rotationSpeed;
	
	ofVec3f rotationPoint;
	ofColor color;
	ofSpherePrimitive planet;

};