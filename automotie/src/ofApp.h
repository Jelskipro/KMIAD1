#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "smilley.h"
#include "ofxCvHaarFinder.h"
#include "ofxOpenCv.h"  

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
		void keyReleased(int key);

		shared_ptr<smilley> isTalking;
		shared_ptr<smilley> smilleyTalking;

		bool hasCustomer;
		bool personInFront;
		bool personWalkingBy;

		ofParameter<string> text;
		ofTrueTypeFont font;
		ofSoundPlayer responseHoi;
		ofSoundPlayer responseHallo;
		ofSoundPlayer responseGoedeKeuze;
		ofSoundPlayer responseOokGoedeKeuze;

		//Close by cam
		ofImage colorImg;
		ofImage grayImage;
		ofVideoGrabber vidGrabber;
		ofxCvHaarFinder finder;
		//Timer to prevent false positives
		float startTime;
		float endTime;
		float timer;

		//Walk by cam1
		ofImage colorImgWalk1;
		ofImage grayImageWalk1;
		ofVideoGrabber GrabberwalkBy1;
		ofxCvHaarFinder FinderwalkBy1;
		//Timer to prevent false positives
		float startTimewalkBy1;
		float endTimewalkBy1;
		float timerwalkBy1;

		//Timer to prevent too much greetings
		float startTimeCoolDown;
		float endTimeCoolDown;
		float timerCoolDown;

	private:
		ofArduino arduino; 

		void setupArduino(const int& version);

		void ofApp::digitalPinChanged(const int& pin);


};
