#pragma once

#include "ofMain.h"
#include "ofxGui.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		//Maybe later needed for setting Arduino Thingy to low
		//void keyReleased(int key);
		bool isTalking;

	private:
		ofArduino arduino; 
		ofSoundPlayer response1;
		ofSoundPlayer response2;
		ofVideoPlayer smilleyTalking;

		//Basic expressions
		ofImage smilleyHappy;
		ofImage smilleyAngry;
		ofImage smilleyMeh;
		ofImage smilleyScared;
		ofImage smilleySad;
		ofImage smilleyHearth;
		//Cry frames
		ofImage smilleyCry1;
		ofImage smilleyCry2;
		ofImage smilleyCry3;
		//Talk frames
		ofImage smilleyTalk1;
		ofImage smilleyTalk2;
		ofImage smilleyTalk3;
		ofImage smilleyTalk4;

		void setupArduino(const int& version);

		void ofApp::digitalPinChanged(const int& pin);


};
