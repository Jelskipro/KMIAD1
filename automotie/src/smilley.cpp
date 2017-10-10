#include "smilley.h"

void smilley::setup() {


	//smilleyTalking.setPixelFormat(OF_PIXELS_RGBA);
	smilleyTalking.load("Talk1.mov");
	smilleyTalking.play();
	smilleyHappy.load("Emotions/HappyB.png");

}
void smilley::update() {
	smilleyTalking.update();

}
void smilley::draw(bool isTalking) {
	smilleyHappy.draw(350, 380, 512, 512);
	
	if (isTalking != true)
	{
		smilleyTalking.draw(999, 999, 512, 512);

	}
	if (isTalking == true)
	{
		smilleyTalking.draw(350, 380, 512, 512);
	}

}
