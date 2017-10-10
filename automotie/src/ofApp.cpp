#include "ofApp.h"
#define DRINK_BUTTON1 11
#define DRINK_BUTTON2 12

void ofApp::setup(){
		//&ofApp::setupArduino);
	//arduino.connect("COM5");
	//arduino.sendFirmwareVersionRequest();

	ofSetLogLevel(OF_LOG_NOTICE);
	
	response1.load("response1.mp3");
	response2.load("response2.mp3");

	smilley.setup();
	isTalking = false;

	font.load("Neuzeit Grotesk Bold.ttf", 56, true, true, false, 0.3f, 0);

	//Close by cam setup
	finder.setup("haarcascade_frontalface_default.xml");
	eyeFinder.setup("haarcascade_eye.xml");

	vidGrabber.listDevices();
	vidGrabber.setVerbose(true);
	vidGrabber.setDeviceID(0);
	vidGrabber.initGrabber(320, 240);
	colorImg.allocate(320, 240, OF_IMAGE_COLOR);
	grayImage.allocate(320, 240, OF_IMAGE_GRAYSCALE);

	personInFront = false;

	//Walk by cam setup
	FinderwalkBy1.setup("haarcascade_upperbody.xml");
	
	GrabberwalkBy1.listDevices();
	GrabberwalkBy1.setVerbose(true);
	GrabberwalkBy1.setDeviceID(1);
	GrabberwalkBy1.initGrabber(320, 240);
	colorImgWalk1.allocate(320, 240, OF_IMAGE_COLOR);
	grayImageWalk1.allocate(320, 240, OF_IMAGE_GRAYSCALE);

	personWalkingBy = false;

}

void ofApp::update(){
	//arduino.update();
	smilley.update();
	
	//Haar finder update
	vidGrabber.update();

	if (vidGrabber.isFrameNew())
	{
		auto pixels = vidGrabber.getPixels();

		colorImg.setFromPixels(pixels.getData(), 320, 240, OF_IMAGE_COLOR, false);
		grayImage = colorImg;

		finder.findHaarObjects(grayImage);
		eyeFinder.findHaarObjects(grayImage);

	}
	GrabberwalkBy1.update();

	if (GrabberwalkBy1.isFrameNew())
	{
		auto pixelsWalkBy1 = GrabberwalkBy1.getPixels();

		colorImgWalk1.setFromPixels(pixelsWalkBy1.getData(), 320, 240, OF_IMAGE_COLOR, false);
		grayImageWalk1 = colorImgWalk1;

		FinderwalkBy1.findHaarObjects(grayImageWalk1);

	}
}

void ofApp::draw(){
	
	//Close by cam draw
	ofSetHexColor(0xffffff);
	colorImg.draw(0, 0);

	ofNoFill();
	for (unsigned int i = 0; i < finder.blobs.size(); i++)
	{
		ofRectangle cur = finder.blobs[i].boundingRect;
		ofRect(cur.x, cur.y, cur.width, cur.height);
	
	}
	for (unsigned int i = 0; i < eyeFinder.blobs.size(); i++)
	{
		ofSetHexColor(0xff0c49);
		ofRectangle cur = eyeFinder.blobs[i].boundingRect;
		ofRect(cur.x, cur.y, cur.width, cur.height);

	}
	
	//Walk by cam draw
	ofSetHexColor(0xffffff);
	colorImgWalk1.draw(400, 0);

	for (unsigned int i = 0; i < FinderwalkBy1.blobs.size(); i++)
	{
		ofRectangle cur = FinderwalkBy1.blobs[i].boundingRect;
		ofRect(cur.x + 400, cur.y, cur.width, cur.height);

	}
	if (FinderwalkBy1.blobs.size() > 0)
	{
		personWalkingBy = true;
		text = "Person walking by";
	}
	else if (FinderwalkBy1.blobs.size() == 0 || finder.blobs.size() == 0 && eyeFinder.blobs.size() == 0)
	{
		personWalkingBy = false;
		text = "Nothing";
	}
	if (finder.blobs.size() > 0 && eyeFinder.blobs.size() > 0)
	{
		personInFront = true;
		text = "Person in front";
	}

	if (response1.isPlaying() == false || response2.isPlaying() == false)
	{
		isTalking = false;

	}
	if (response1.isPlaying() || response2.isPlaying())
	{
		isTalking = true;
	}

	//smilley.draw(isTalking);
	ofSetColor(ofColor::black);
	font.drawString(text, 0, 600);

}

void ofApp::keyPressed(int key){
	if (key == '1') {
		response2.stop();
		response1.play();

	}
	if (key == '2') {
		response1.stop();
		response2.play();
	}

}

//void ofApp::setupArduino(const int& version) {
	//ofLog() << "Arduino firmware found " << arduino.getFirmwareName()
		//<< arduino.getMajorFirmwareVersion()
		//<< arduino.getMinorFirmwareVersion() << endl;

	//arduino.sendDigitalPinMode(DRINK_BUTTON1, ARD_INPUT);
	//arduino.sendDigitalPinMode(DRINK_BUTTON2, ARD_INPUT);

	//ofAddListener(arduino.EDigitalPinChanged, this, &ofApp::digitalPinChanged);

//}

//void ofApp::digitalPinChanged(const int& pin) {
	//ofLog() << "Digital Pin " << pin << " value: " << arduino.getDigital(pin) << endl;
	
	//if (arduino.getDigital(12) == 1)
	//{
		//response2.stop();
		//response1.play();
	//}
	//if (arduino.getDigital(11) == 1)
	//{
		//response1.stop();
		//response2.play();
	//}
//}
