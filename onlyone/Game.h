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
#include "InputManager.h"

class State;

class Game
{
public:
    Game(InputManager* inputManager);
    ~Game();
    
    enum States
    {
        STATE_NULL,
        STATE_EXIT,
        STATE_SPLASH,
        STATE_MENU,
        STATE_PLAY,
    };
    
    void Start();
    void Update();
    void Render(sf::RenderWindow* window);
    void Quit();
    
    void SetState(States nextState);
    State* GetState();
    
    InputManager* GetInputManager() {return mInputManager;}
    
private:
    Game();
    
    InputManager* mInputManager;
    //! Pointer to the current state
    State* mCurrentState;
    int mStateID;
    int mNextState;
    
    void UpdateState();
};

#endif /* defined(__onlyone__Game__) */
