//
//  StatePlay.h
//  onlyone
//
//  Created by Sean Rabaut on 12/13/13.
//  Copyright (c) 2013 Sean Rabaut. All rights reserved.
//

#ifndef __onlyone__StatePlay__
#define __onlyone__StatePlay__

#include <iostream>
#include "State.h"
#include "Map.h"
#include "Player.h"

class StatePlay : public State
{
public:
    StatePlay(Game* game);
    ~StatePlay();
    
    virtual void Initialize();
    virtual void Update();
    virtual void Render(sf::RenderWindow* window);
    
private:
    Game* mGame;
    Map mMap;
    Player mPlayer;
    sf::Text mFound;
    sf::Text mInstrText;
    sf::Text mTimeLeft;
    sf::Text mGameOver;
    sf::Font mFont;
    sf::Clock mClock;
    sf::Time mLastUpdate;
    sf::Music mMusic;
    sf::SoundBuffer mLoseBuffer;
    sf::SoundBuffer mWinBuffer;
    sf::Sound mSound;
    
    bool mIsGameOver;
};

#endif /* defined(__onlyone__StatePlay__) */
