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
		bool personInFront;
		bool personWalkingBy;

		ofParameter<string> text;

		ofSoundPlayer response1;
		ofSoundPlayer response2;

		ofTrueTypeFont font;
	
		//Close by cam
		ofImage colorImg;
		ofImage grayImage;
		ofVideoGrabber vidGrabber;
		ofxCvHaarFinder finder;
		ofxCvHaarFinder eyeFinder;

		//Walk by cam1
		ofImage colorImgWalk1;
		ofImage grayImageWalk1;
		ofVideoGrabber GrabberwalkBy1;
		ofxCvHaarFinder FinderwalkBy1;

	private:
		ofArduino arduino; 

		void setupArduino(const int& version);

		void ofApp::digitalPinChanged(const int& pin);


};
