#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    
    ofSetVerticalSync(true);
    ofBackground(0, 0, 0);
    ofSetFrameRate(60);
    
    panel.setup("video_player", "video_player.json", 20, 20);
    panel.add(fullscreen_b.set("fullscreen",0));
    video_player.setup();
    
    panel.add(&video_player.gui);
    
    panel.loadFromFile("video_player.json");
    settings_sync.setup((ofParameterGroup&)panel.getParameter(),
                        SYNC_INPORT, "localhost", SYNC_OUTPORT);
    
    video_player.reload();
    
    fullscreen_b.addListener(this, &ofApp::fullscreen_b_changed);
    ofSetFullscreen(fullscreen_b);
    ofHideCursor();
}

//--------------------------------------------------------------
void ofApp::update()
{
    video_player.update();
    settings_sync.update();
}

//--------------------------------------------------------------
void ofApp::draw()
{
    video_player.draw();
    if (draw_gui)
    {
        panel.draw();
    }
    
    
    if (screen_workaround_to_update)
    {
        
        windowResized(ofGetWidth(), ofGetHeight());
        screen_workaround_to_update = 0;
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    if (key == 'f'){fullscreen_b=!fullscreen_b;}
    if( key == 'g' ){handle_gui();}
    if( key == 'm' )
    {
        show_mouse =!show_mouse;
        if (show_mouse)
        {
            ofShowCursor();
        } else {
            ofHideCursor();
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y )
{

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
     if( button == 2 ){handle_gui();}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{
    video_player.set_size(w,h);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{

}

void ofApp::fullscreen_b_changed(bool &b)
{
    if (fullscreen_b)
    {
        ofSetFullscreen(1);
    } else {
        ofSetFullscreen(0);
    }
}

void ofApp::handle_gui()
{
    draw_gui=!draw_gui;
    
    if (draw_gui)
    {
        ofShowCursor();
    } else {
        ofHideCursor();
    }
}
