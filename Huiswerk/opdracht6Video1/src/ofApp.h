#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		
		ofVideoGrabber grabber;
		ofImage image;
		ofPixels workspace;
		
		bool drawGrabbedImage;

		int randomRmutation;
		int randomGmutation;
		int randomBmutation;


};
