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
    if(!mMenuTexture.loadFromFile(resourcePath() + "MainMenu.png"))
        std::cout << "Could not load MainMenu.png" << std::endl;
    else
        mMenuSprite.setTexture(mMenuTexture);
}

void StateMenu::Update()
{
    InputManager* input = mGame->GetInputManager();
    if(input->isKeyPressed(sf::Keyboard::Return))
    {
        mGame->SetState(Game::STATE_PLAY);
    }
}

void StateMenu::Render(sf::RenderWindow* window)
{
    window->draw(mMenuSprite);
}