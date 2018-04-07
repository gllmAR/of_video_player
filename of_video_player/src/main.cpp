#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
    //ofSetupOpenGL(1024,768,OF_WINDOW);
    ofGLESWindowSettings settings;
    settings.setGLESVersion(2);
    ofCreateWindow(settings);
    ofRunApp(new ofApp());
};
