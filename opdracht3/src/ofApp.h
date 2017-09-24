#pragma once

#include "ofMain.h"
#include "Ball.h"
#include <vector>

class ofApp : public ofBaseApp{

	public:
		std::vector<Ball> balls;

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);

		int radius;
		ofParameter<float>speedX;
		ofParameter<float>speedY;
		ofParameter<ofColor>color;

private:
	ofArduino arduino;

	void setupArduino(const int& version);

	void ofApp::analogPinChanged(const int& pin);

	void ofApp::digitalPinChanged(const int& pin);
};
