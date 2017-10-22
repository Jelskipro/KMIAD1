#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "Planet.h"
#include "ofxAssimpModelLoader.h"
#include <vector>

class ofApp : public ofBaseApp{

	public:
		std::vector<Planet> planets;
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		
		ofxAssimpModelLoader starDestroyer;
		ofxPanel gui;

		ofParameter<bool> drawGrid;
		ofParameter<bool> useLight;
		
		ofVec3f rotationPoint;
		ofColor color;
		ofLight light;
		ofEasyCam cam;

		ofParameter<int> radius;
		ofParameter<float> xRotPos;
		ofParameter<float> yRotPos;
		ofParameter<float> zRotPos;
		ofParameter<float> rotateX;
		ofParameter<float> rotateY;
		ofParameter<float> rotateZ;
		ofParameter<float> longitude;
		ofParameter<float> latitude;
		ofParameter<float> rotationRadius;
		ofParameter<float> rotationSpeed;
		
};
