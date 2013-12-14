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

Game::Game(InputManager* inputManager)
{
    mInputManager = inputManager;
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
    //std::cout << mStateID << std::endl;
    UpdateState();
    if(mCurrentState)
        mCurrentState->Update();
}

void Game::Render(sf::RenderWindow* window)
{
    if(mCurrentState)
        mCurrentState->Render(window);
}

void Game::Quit()
{
    
}

void Game::SetState(States nextState)
{
    mNextState = nextState;
    mCurrentState = NULL;
}

void Game::UpdateState()
{
    //if the state needs to be changed
    if(mNextState != STATE_NULL)
    {
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
            default:
                mCurrentState = NULL;
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