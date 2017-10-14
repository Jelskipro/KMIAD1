#include "ofMain.h"
#include "ofApp.h"
#include "smilley.h"
#include "ofAppGLFWWindow.h"

//========================================================================
int main( ){
	ofGLFWWindowSettings settings;

	settings.width = 600;
	settings.height = 600;
	settings.setPosition(ofVec2f(300, 25));
	settings.resizable = true;
	shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);

	settings.width = 512;
	settings.height = 512;
	settings.setPosition(ofVec2f(0, 25));
	settings.resizable = true;
	shared_ptr<ofAppBaseWindow> smilleyWindow = ofCreateWindow(settings);

	shared_ptr<ofApp> mainApp(new ofApp);
	shared_ptr<smilley> smilley(new smilley);
	mainApp->smilleyTalking = smilley;
	mainApp->isTalking = smilley;
	mainApp->smilleyState = smilley;

	ofRunApp(smilleyWindow, smilley);
	ofRunApp(mainWindow, mainApp);
	ofRunMainLoop();


}
