#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "Ball.h"
#include "Ball3d.h"
#include <vector>

class ofApp : public ofBaseApp {

public:
	std::vector<Ball3d> balls;

	void setup();
	void update();
	void draw();

	void keyPressed(int key);

	ofxPanel gui;

	ofParameter<bool> drawGrid;
	ofParameter<bool> useLight;
	
	ofParameter<int>radius;
	ofParameter<float>speedX;
	ofParameter<float>speedY;
	ofParameter<float>speedZ;
	ofParameter<ofColor>color;

	ofLight light;
	ofEasyCam cam;
};
