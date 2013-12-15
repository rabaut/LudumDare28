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
    mFont.loadFromFile(resourcePath() + "UbuntuMono.ttf");
    mText.setFont(mFont);
    mText.setString("  Enter to Play\nL for Leaderboard\n   ESC to Quit");
    mText.setCharacterSize(20);
    mText.setPosition(300,500);
    mSprite.setTexture(mTexture);
}

void StateMenu::Update()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
    {
        std::cout << "Enter Username: " << std::endl;
        std::string s;
        std::cin >> s;
        mGame->SetUsername(s);
        mGame->SetState(Game::STATE_PLAY);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::L))
    {
        mGame->SetState(Game::STATE_LDRBRD);
    }
}

void StateMenu::Render(sf::RenderWindow* window)
{
    mText.setColor(sf::Color(rand(),rand(),rand()));
    window->draw(mSprite);
    window->draw(mText);
}