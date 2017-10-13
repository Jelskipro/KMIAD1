#include "ofApp.h"
#define DRINK_BUTTON1 11
#define DRINK_BUTTON2 12

void ofApp::setup(){
	ofAddListener(arduino.EInitialized, this,
		&ofApp::setupArduino);
	arduino.connect("COM5");
	arduino.sendFirmwareVersionRequest();

	ofSetLogLevel(OF_LOG_NOTICE);
	
	//isTalking = false;

	font.load("Neuzeit Grotesk Bold.ttf", 56, true, true, false, 0.3f, 0);
	responseHoi.load("hoi.mp3");
	responseHallo.load("hallo.mp3");
	responseGoedeKeuze.load("GoedeKeuze.mp3");
	responseOokGoedeKeuze.load("OokGoedeKeuze.mp3");

	//Close by cam setup
	finder.setup("haarcascade_eye.xml");
	vidGrabber.listDevices();
	vidGrabber.setVerbose(true);
	vidGrabber.setDeviceID(0);
	vidGrabber.initGrabber(320, 240);
	colorImg.allocate(320, 240, OF_IMAGE_COLOR);
	grayImage.allocate(320, 240, OF_IMAGE_GRAYSCALE);

	personInFront = false;

	//Close by cam timer setup
	startTime = ofGetElapsedTimeMillis();
	endTime = 20000;

	//Walk by cam setup
	FinderwalkBy1.setup("haarcascade_upperbody.xml");
	GrabberwalkBy1.listDevices();
	GrabberwalkBy1.setVerbose(true);
	GrabberwalkBy1.setDeviceID(1);
	GrabberwalkBy1.initGrabber(320, 240);
	colorImgWalk1.allocate(320, 240, OF_IMAGE_COLOR);
	grayImageWalk1.allocate(320, 240, OF_IMAGE_GRAYSCALE);

	personWalkingBy = false;

	//Walk by cam timer setup
	startTimewalkBy1 = ofGetElapsedTimeMillis();
	endTimewalkBy1 = 20000;
	
	//Cool down timer setup
	startTimeCoolDown = ofGetElapsedTimeMillis();
	endTimeCoolDown = 100000;
}
void ofApp::update(){
	arduino.update();

	//Haar finder update
	vidGrabber.update();

	if (vidGrabber.isFrameNew())
	{
		auto pixels = vidGrabber.getPixels();

		colorImg.setFromPixels(pixels.getData(), 320, 240, OF_IMAGE_COLOR, false);
		grayImage = colorImg;

		finder.findHaarObjects(grayImage);
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
		//Start timer to check if it is actually a person
		timerwalkBy1 = ofGetElapsedTimeMillis() - startTimewalkBy1;

	}
	else if (FinderwalkBy1.blobs.size() == 0 || finder.blobs.size() == 0)
	{
		personWalkingBy = false;
		personInFront = false;
		timerwalkBy1 = 0;
		timer = 0;
		text = "Nothing";
	}
	if (finder.blobs.size() > 0)
	{
		//Start timer to check if it is actually a person
		timer = ofGetElapsedTimeMillis() - startTime;
	}

	if (timerwalkBy1 >= endTimewalkBy1 && !personWalkingBy) {
		personWalkingBy = true;
		ofSetColor(ofColor::green);
		text = "Person walking by";
		if (timerCoolDown >= endTimeCoolDown && responseHoi.isPlaying() == false)
		{
			
		}
		responseHoi.play();
		timerCoolDown = ofGetElapsedTimeMillis() - startTimeCoolDown;
	}
	else if (timer >= endTime && !personInFront) {
		personInFront = true;
		ofSetColor(ofColor::blue);
		text = "Person in front";
		if (responseHallo.isPlaying() == false) {
			responseHallo.play();
		}
	}

	ofSetColor(ofColor::black);
	font.drawString(text, 0, 600);

}
void ofApp::keyPressed(int key){
	if (key == 'f') {
		isTalking->isTalking = true;
	}
}
void ofApp::keyReleased(int key) {
	if (key == 'f') {
		isTalking->isTalking = false;
		//TODO sort out coolDown timer!!!!!!
		//timerCoolDown = 0;
	}
}
void ofApp::setupArduino(const int& version) {
	ofLog() << "Arduino firmware found " << arduino.getFirmwareName()
		<< arduino.getMajorFirmwareVersion()
		<< arduino.getMinorFirmwareVersion() << endl;

	arduino.sendDigitalPinMode(DRINK_BUTTON1, ARD_INPUT);
	arduino.sendDigitalPinMode(DRINK_BUTTON2, ARD_INPUT);

	ofAddListener(arduino.EDigitalPinChanged, this, &ofApp::digitalPinChanged);

}

void ofApp::digitalPinChanged(const int& pin) {
	ofLog() << "Digital Pin " << pin << " value: " << arduino.getDigital(pin) << endl;
	
	if (arduino.getDigital(12) == 1 && responseOokGoedeKeuze.isPlaying() == false)
	{
		responseGoedeKeuze.play();
	}
	if (arduino.getDigital(11) == 1 && responseGoedeKeuze.isPlaying() == false)
	{
		responseOokGoedeKeuze.play();
	}
}
