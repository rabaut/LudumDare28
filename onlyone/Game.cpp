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
#include "StateLdrBrd.h"
#include "ResourcePath.hpp"
#include <fstream>
#include <sstream>
#include <iomanip>

Game::Game()
{
    mCurrentState = NULL;
    mStateID = STATE_NULL;
    mNextState = STATE_NULL;
    mUsername = "Player";
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
            case STATE_LDRBRD:
                delete mCurrentState;
                mCurrentState = new StateLdrBrd(this);
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

void Game::UpdateLdrBrd(std::string symbolsFound, double timeLeft)
{
    std::stringstream ss;
    ss << std::setw(20) << std::left << mUsername;
    ss << std::setw(27) << std::left << "|" + symbolsFound;
    ss << std::setw(21) << std::left << "|  " << std::setprecision(4) <<
            timeLeft << "  |" << std::endl;
    std::string str = ss.str();
    mLeaderBoard.append(str);
}