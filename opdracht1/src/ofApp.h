#pragma once

#include "ofMain.h"
#include "Ball.h"
#define NBALLS 20

class ofApp : public ofBaseApp{

	public:
		Ball myBall[NBALLS];
		void setup();
		void update();
		void draw();

		void keyPressed(int key);


		
		
};
