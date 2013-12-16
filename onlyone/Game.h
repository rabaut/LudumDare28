//
//  Game.h
//  onlyone
//
//  Created by Sean Rabaut on 12/13/13.
//  Copyright (c) 2013 Sean Rabaut. All rights reserved.
//

#ifndef __onlyone__Game__
#define __onlyone__Game__

#include <iostream>
#include <SFML/Graphics.hpp>

class State;

class Game
{
public:
    Game();
    
    enum States
    {
        STATE_NULL,
        STATE_EXIT,
        STATE_MENU,
        STATE_PLAY,
    };
    
    void Start();
    void Update();
    void Render(sf::RenderWindow* window);
    
    void SetState(States nextState);
    State* GetState();
    
    sf::Font* GetUbuntuFont() {return mUFont;}
    sf::Font* GetSansFont() {return mSFont;}
    
private:
    //! Pointer to the current state
    State* mCurrentState;
    int mStateID;
    int mNextState;
    sf::Font* mUFont;
    sf::Font* mSFont;
    
    void UpdateState();
};

#endif /* defined(__onlyone__Game__) */
