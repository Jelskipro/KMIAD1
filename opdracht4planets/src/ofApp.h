#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxAssimpModelLoader.h"
#include "Planet.h"
#include <vector>

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);

		ofxPanel gui;

		ofParameter<bool> drawGrid;
		ofParameter<bool> useLight;

		ofLight light;
		ofEasyCam cam;

		ofParameter<int> radius;
		ofParameter<float> longitude;
		ofParameter<float> latitude;
		ofParameter<float> rotationRadius;
		ofParameter<float> rotationSpeed;
		ofParameter<float> Lx;
		ofParameter<float> Ly;
		ofParameter<float> Lz;

		ofVec3f rotationPoint;
		ofColor color;
		ofImage earthTexture;
		ofImage moonTexture;
		ofImage sunTexture;

		ofSpherePrimitive planet;
		ofSpherePrimitive moon;
		ofSpherePrimitive sun;
		ofxAssimpModelLoader starDestroyer;
private:
	ofArduino arduino;

	void setupArduino(const int& version);

	void ofApp::analogPinChanged(const int& pin);

	void ofApp::digitalPinChanged(const int& pin);
};
