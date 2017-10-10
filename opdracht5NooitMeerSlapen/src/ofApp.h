#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);

		ofEasyCam cam;
		ofLight light;
		ofVideoGrabber grabber;

		ofIcoSpherePrimitive sphere1;
		ofIcoSpherePrimitive sphere2;
		ofIcoSpherePrimitive sphere3;
		ofIcoSpherePrimitive sphere4;

};
