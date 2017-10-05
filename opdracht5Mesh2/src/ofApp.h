#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		ofConePrimitive primitive;

		float coneRadius = 100;
		float coneHeight = 200;
		int coneRadiusSegments = 10;
		int coneHeightSegments = 10;
		
};
