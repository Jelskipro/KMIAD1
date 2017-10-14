#pragma once

#include "ofMain.h"
enum class MyState {
	HAPPY, SAD, ANGRY, MEH, SCARED, LOVE
};
class smilley : public ofBaseApp {
public:
	MyState smilleyState = MyState::HAPPY;
	void setup();
	void update();
	void draw();

	bool isTalking;
	bool isCrying;

	ofVideoPlayer smilleyTalking;
	ofVideoPlayer smilleyCrying;

	//Basic expressions
	ofImage smilleyHappy;
	ofImage smilleySad;
	ofImage smilleyAngry;
	ofImage smilleyMeh;
	ofImage smilleyScared;
	ofImage smilleyLove;

};

