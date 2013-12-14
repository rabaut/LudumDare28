//
//  Game.cpp
//  onlyone
//
//  Created by Sean Rabaut on 12/13/13.
//  Copyright (c) 2013 Sean Rabaut. All rights reserved.
//

#include "Game.h"
#include "StateSplash.h"
#include "StateMenu.h"
#include "StatePlay.h"

Game::Game()
{
    mCurrentState = NULL;
    mStateID = STATE_NULL;
    mNextState = STATE_NULL;
}

Game::~Game()
{
    
}

void Game::Start()
{
    mCurrentState = new StateSplash(this);
    mStateID = STATE_SPLASH;
}

void Game::Update()
{
    if(mCurrentState)
        mCurrentState->Update();
}

void Game::Render(sf::RenderWindow& window)
{
    if(mCurrentState)
        mCurrentState->Render(window);
}

void Game::Quit()
{
    
}

void Game::SetState(State* state)
{
    //if the state needs to be changed
    if(mNextState != STATE_NULL)
    {
        //delete current stage
        if(mNextState != STATE_EXIT)
        {
            delete mCurrentState;
        }
        
        //change the state
        switch( mNextState )
        {
            case STATE_SPLASH:
                mCurrentState = new StateSplash(this);
                break;
                
            case STATE_MENU:
                mCurrentState = new StateMenu(this);
                break;
                
            case STATE_PLAY:
                mCurrentState = new StatePlay(this);
                break;
        }
        mStateID = mNextState;
        mNextState = STATE_NULL;
    }
}

State* Game::GetState()
{
    return mCurrentState;
}