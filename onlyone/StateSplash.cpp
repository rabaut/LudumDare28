//
//  StateSplash.cpp
//  onlyone
//
//  Created by Sean Rabaut on 12/13/13.
//  Copyright (c) 2013 Sean Rabaut. All rights reserved.
//

#include "StateSplash.h"
#include "ResourcePath.hpp"

StateSplash::StateSplash(Game* game) : State(game)
{
    Initialize();
}

void StateSplash::Initialize()
{
    mAlpha = 255;
    if(!mSplashTexture.loadFromFile(resourcePath() + "splash.png"))
        std::cout << "Could not load splash.png" << std::endl;
    else
        mSplashSprite.setTexture(mSplashTexture);
}

void StateSplash::Update()
{
    mAlpha = mAlpha -3;
    if(mAlpha <= 0)
    {
        mGame->SetState(Game::STATE_MENU);
    }
    mSplashSprite.setColor(sf::Color(255,255,255,mAlpha));
}

void StateSplash::Render(sf::RenderWindow* window)
{
    window->draw(mSplashSprite);
}