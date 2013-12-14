//
//  StatePlay.cpp
//  onlyone
//
//  Created by Sean Rabaut on 12/13/13.
//  Copyright (c) 2013 Sean Rabaut. All rights reserved.
//

#include "StatePlay.h"

StatePlay::StatePlay(Game* game) : State(game)
{
    Initialize();
}

StatePlay::~StatePlay()
{
    
}

void StatePlay::Initialize()
{
    mMap = new Map(50,50);
}

void StatePlay::Update()
{
    
}

void StatePlay::Render(sf::RenderWindow* window)
{
    mMap->PrintMap();
}
