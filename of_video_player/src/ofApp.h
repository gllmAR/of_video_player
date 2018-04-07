#pragma once

#include "ofMain.h"
#include "video_player.hpp"
#include "ofxOscParameterSync.h"


#define HOST "localhost"
#define SYNC_INPORT 8701
#define SYNC_OUTPORT 8700


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    ofParameter<bool> fullscreen_b;
    Video_player video_player;
    ofxPanel panel;
    
    ofxOscParameterSync settings_sync;
    void fullscreen_b_changed(bool &b);
    
    
    bool show_mouse = 0;
    bool draw_gui = 1;
    
    void handle_gui();
    
    bool screen_workaround_to_update = 1;
    
};
