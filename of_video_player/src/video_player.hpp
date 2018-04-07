//
//  video_player.hpp
//  of_video_player
//
//  Created by Guillaume Arseneault on 18-04-07.
//
//

#ifndef video_player_hpp
#define video_player_hpp

#include "ofMain.h"
#include "ofxGui.h"

class Video_player
{
public:
    ofVideoPlayer player;
    ofParameter<bool> play_b;
    ofParameter<std::string> movie_path;
    ofxGuiGroup gui;
    
    void setup();
    void load(std::string file);
    void set_size(int w, int h);
    void update();
    void draw();
    
    void reload();
    
    void play_b_changed(bool &b);
    void movie_path_changed(std::string &s);
    
    
    
private:
    int width;
    int height;

    
};
#endif /* video_player_hpp */
