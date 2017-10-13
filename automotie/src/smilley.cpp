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
void smilley::draw() {
	smilleyHappy.draw(0, 0, 512, 512);
	
	if (isTalking != true)
	{
		smilleyTalking.draw(999, 999, 512, 512);

	}
	if (isTalking == true)
	{
		smilleyTalking.draw(0, 0, 512, 512);
	}

}
