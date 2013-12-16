//
//  StateMenu.cpp
//  onlyone
//
//  Created by Sean Rabaut on 12/13/13.
//  Copyright (c) 2013 Sean Rabaut. All rights reserved.
//

#include "StateMenu.h"
#include "ResourcePath.hpp"

StateMenu::StateMenu(Game* game) : State(game)
{
    Initialize();
}

void StateMenu::Initialize()
{
    mTexture.loadFromFile(resourcePath() + "mainMenu.png");
    mText.setFont(*mGame->GetUbuntuFont());
    mText.setString("Press Enter");
    mText.setCharacterSize(30);
    mText.setPosition(300,500);
    mText.setStyle(sf::Text::Style::Bold);
    mSprite.setTexture(mTexture);
}

void StateMenu::Update()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
        mGame->SetState(Game::STATE_PLAY);
}

void StateMenu::Render(sf::RenderWindow* window)
{
    mText.setColor(sf::Color(rand(),rand(),rand()));
    window->draw(mSprite);
    window->draw(mText);
}