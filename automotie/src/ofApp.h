#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);


	private:
		ofArduino arduino; 
		
		void setupArduino(const int& version);

		void ofApp::digitalPinChanged(const int& pin);

};
