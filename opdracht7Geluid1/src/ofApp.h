#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		
		ofSoundPlayer voicePlayer[6];
		bool playing[6];
		float volume; 
private:
	ofArduino arduino;

	void setupArduino(const int& version);

	void ofApp::analogPinChanged(const int& pin);

	void ofApp::digitalPinChanged(const int& pin);
};

