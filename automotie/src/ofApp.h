#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "smilley.h"
#include "ofxCvHaarFinder.h"
#include "ofxOpenCv.h"  

class ofApp : public ofBaseApp{

	public:
		smilley smilley;
		void setup();
		void update();
		void draw();
		void keyPressed(int key);

		bool isTalking;
		bool personInSight;

		ofParameter<string> text;

		ofSoundPlayer response1;
		ofSoundPlayer response2;

		ofImage colorImg;
		ofImage grayImage;
		
		ofTrueTypeFont font;
		ofVideoGrabber vidGrabber;
		ofxCvHaarFinder finder;
		ofxCvHaarFinder eyeFinder;
	private:
		ofArduino arduino; 

		void setupArduino(const int& version);

		void ofApp::digitalPinChanged(const int& pin);


};
