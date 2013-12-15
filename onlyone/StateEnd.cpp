//
//  StateEnd.cpp
//  onlyone
//
//  Created by Sean Rabaut on 12/15/13.
//  Copyright (c) 2013 Sean Rabaut. All rights reserved.
//

#include "StateEnd.h"
#include "ResourcePath.hpp"

StateEnd::StateEnd(Game* game) : State(game)
{
    Initialize();
}

void StateEnd::Initialize()
{
    mTexture.loadFromFile(resourcePath() + "mainMenu.png");
    mFont.loadFromFile(resourcePath() + "UbuntuMono.ttf");
    mText.setFont(mFont);
    mText.setString("Press Enter");
    mText.setCharacterSize(20);
    mText.setPosition(345,520);
    mSprite.setTexture(mTexture);
}

void StateEnd::Update()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
    {
        mGame->SetState(Game::STATE_PLAY);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::L))
    {
        mGame->SetState(Game::STATE_LDRBRD);
    }
}

void StateEnd::Render(sf::RenderWindow* window)
{
    mText.setColor(sf::Color(rand(),rand(),rand()));
    window->draw(mSprite);
    window->draw(mText);
}