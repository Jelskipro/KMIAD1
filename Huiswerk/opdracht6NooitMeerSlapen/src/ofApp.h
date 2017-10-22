#pragma once

#include "ofMain.h"
#define CAM_WIDTH 320
#define CAM_HEIGHT 240

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);

	private:
		bool drawLeft = true;

		ofVideoGrabber videoGrabber;
		ofImage image;
		ofPixels workspace;

};
