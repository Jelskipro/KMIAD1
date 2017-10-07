#pragma once

#include "ofMain.h"


class smilley
{
public:
	void setup();
	void update();
	void draw(bool isTalking);
	
	bool isTalking;

	ofVideoPlayer smilleyTalking;

	//Basic expressions
	ofImage smilleyHappy;
	ofImage smilleySad;
	ofImage smilleyAngry;
	ofImage smilleyMeh;
	ofImage smilleyScared;
};

