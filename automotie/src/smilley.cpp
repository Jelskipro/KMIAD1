#include "smilley.h"

void smilley::setup() {
	

	//smilleyTalking.setPixelFormat(OF_PIXELS_RGBA);
	smilleyTalking.load("Smilley/Talk1.mp4");
	smilleyTalking.play();
	//smilleyCrying.load("Smilley/Cry1.mp4");
	//smilleyCrying.play();

	smilleyHappy.load("Smilley/Happy.png");
	smilleySad.load("Smilley/Sad.png");
	smilleyAngry.load("Smilley/Angry.png");
	smilleyMeh.load("Smilley/Meh.png");
	smilleyScared.load("Smilley/Scared.png");
	smilleyLove.load("Smilley/Love.png");
	
}

void smilley::update() {
	smilleyTalking.update();
	//smilleyCrying.update();

}
void smilley::draw() {
	switch (smilleyState) {
	case MyState::HAPPY:
		smilleyHappy.draw(0, 0, 1280, 1024);
		break;
	case MyState::SAD:
		smilleySad.draw(0, 0, 1280, 1024);
		break;
	case MyState::ANGRY:
		smilleyAngry.draw(0, 0, 1280, 1024);
		break;
	case MyState::MEH:
		smilleyMeh.draw(0, 0, 1280, 1024);
		break;
	case MyState::SCARED:
		smilleyScared.draw(0, 0, 1280, 1024);
		break;
	case MyState::LOVE:
		smilleyLove.draw(0, 0, 1280, 1024);
		break;
	}

	if (isCrying != true)
	{
		//smilleyCrying.draw(999, 999, 1280, 1024);

	}
	if (isCrying == true)
	{
		//smilleyCrying.draw(0, 0, 1280, 1024);
	}

	if (isTalking != true)
	{
		smilleyTalking.draw(999, 999, 1280, 1024);

	}
	if (isTalking == true)
	{
		smilleyTalking.draw(0, 0, 1280, 1024);
	}

}
