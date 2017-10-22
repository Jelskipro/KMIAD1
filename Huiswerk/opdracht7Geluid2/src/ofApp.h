#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		
		float phase;

		void audioOut(float* outpute, int bufferSize, int nChannels);

		ofSoundStream soundStream;

		float step;
		
};
