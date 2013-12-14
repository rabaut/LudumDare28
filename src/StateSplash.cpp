//
//  StateSplash.cpp
//  onlyone
//
//  Created by Sean Rabaut on 12/13/13.
//  Copyright (c) 2013 Sean Rabaut. All rights reserved.
//

#include "StateSplash.h"

StateSplash::StateSplash(Game* game) : State(game)
{
    Initialize();
}

void StateSplash::Initialize()
{
    if(mTexture)
}

void StateSplash::Update()
{
    mAlpha = mAlpha -3;
    if(mAlpha <= 0)
    {
        
    }
    mSplashSprite.setColor(sf::Color(255,255,255,mAlpha));
}