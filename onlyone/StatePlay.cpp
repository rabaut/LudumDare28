//
//  StatePlay.cpp
//  onlyone
//
//  Created by Sean Rabaut on 12/13/13.
//  Copyright (c) 2013 Sean Rabaut. All rights reserved.
//

#include "StatePlay.h"

StatePlay::StatePlay(Game* game) : State(game), mMap(600,600,45,10), mPlayer(&mMap)
{
    mGame = game;
}

StatePlay::~StatePlay()
{
    
}

void StatePlay::Initialize()
{

}

void StatePlay::Update()
{
    mPlayer.Update(mGame->GetInputManager());
}

void StatePlay::Render(sf::RenderWindow* window)
{
    mMap.Render(window);
    mPlayer.Render(window);
}
