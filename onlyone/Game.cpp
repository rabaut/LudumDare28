//
//  Game.cpp
//  onlyone
//
//  Created by Sean Rabaut on 12/13/13.
//  Copyright (c) 2013 Sean Rabaut. All rights reserved.
//

#include "Game.h"
#include "StateMenu.h"
#include "StatePlay.h"
#include "ResourcePath.hpp"
#include <fstream>
#include <sstream>
#include <iomanip>

Game::Game()
{
    mCurrentState = NULL;
    mStateID = STATE_NULL;
    mNextState = STATE_NULL;
}

void Game::Start()
{
    mCurrentState = new StateMenu(this);
    mStateID = STATE_MENU;

}

void Game::Update()
{
    UpdateState();
    if(mCurrentState)
        mCurrentState->Update();
}

void Game::Render(sf::RenderWindow* window)
{
    if(mCurrentState)
        mCurrentState->Render(window);
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
            case STATE_MENU:
                delete mCurrentState;
                mCurrentState = new StateMenu(this);
                break;
            case STATE_PLAY:
                delete mCurrentState;
                mCurrentState = new StatePlay(this);
                break;
            default:
                delete mCurrentState;
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