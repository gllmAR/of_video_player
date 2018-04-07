//
//  video_player.cpp
//  of_video_player
//
//  Created by Guillaume Arseneault on 18-04-07.
//
//

#include "video_player.hpp"

void Video_player::setup()
{
    gui.setup("movie");
    gui.add(play_b.set("play",0));
    gui.add(loop_i.set("loop",1,0,1));
    gui.add(movie_path.set("movie_path","movie.mp4"));
    
    play_b.addListener(this, &Video_player::play_b_changed);
    loop_i.addListener(this, &Video_player::loop_i_changed);
    movie_path.addListener(this, &Video_player::movie_path_changed);
    
    set_player();
}

void Video_player::set_player()
{
    player.setPixelFormat(OF_PIXELS_NATIVE);
    player.load(movie_path);
    set_player_loop(loop_i);
    if(play_b)
    {
        player.play();
    }
}


void Video_player::load(std::string file)
{
    player.loadAsync(file);
}

void Video_player::set_size(int w, int h)
{
    width=w;
    height=h;
}

void Video_player::update()
{
    if (player.isLoaded() && !player.isPlaying() && play_b)
    {
        player.play();
    }
    
    if (player.isLoaded())
    {
    player.update();
    }
}

void Video_player::draw()
{
    if (player.isLoaded() && player.isPlaying())
    {
    player.draw(0,0,width,height);
    }
}

void Video_player::set_player_loop(int i)
{
    if (i==0)
    {
        player.setLoopState(OF_LOOP_NONE);
    } else if (i==1) {
        player.setLoopState(OF_LOOP_NORMAL);
    } else if (i==2) {
        player.setLoopState(OF_LOOP_PALINDROME);
    } else {
        cout<<"loop type: "<<i<<" is unsupported)]"<<endl;
    }
}


void Video_player::play_b_changed(bool &b)
{
    if(play_b)
    {
        player.play();
    } else {
        player.stop();
    }
}

void Video_player::loop_i_changed(int &i)
{
    set_player_loop(loop_i);
}

void Video_player::movie_path_changed(std::string &s)
{
    ofFile movie_to_read;
    if (!movie_to_read.doesFileExist(movie_path.get()))
    {
        cout<<"file: "<<movie_path<<" does not exist";
    }else{
        load(movie_path);
    }
}

void Video_player::reload()
{
    player.loadAsync(movie_path.get());
}
