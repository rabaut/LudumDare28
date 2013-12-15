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
        STATE_LDRBRD
    };
    
    void Start();
    void Update();
    void Render(sf::RenderWindow* window);
    
    void SetState(States nextState);
    State* GetState();
    
    void UpdateLdrBrd(std::string symbolsFound, double timeLeft);
    std::string GetLdrBrd() {return mLeaderBoard;}
    
    void SetUsername(std::string name) {mUsername = name;}
    
private:
    //! Pointer to the current state
    State* mCurrentState;
    int mStateID;
    int mNextState;
    std::string mUsername;
    std::string mLeaderBoard;
    bool mFreshBoard;
    
    void UpdateState();
};

#endif /* defined(__onlyone__Game__) */
