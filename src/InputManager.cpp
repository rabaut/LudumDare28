//
//  InputManager.cpp
//  Local
//
//  Created by Sean Rabaut on 7/8/13.
//  Copyright (c) 2013 Sean Rabaut. All rights reserved.
//

#include "InputManager.h"

InputManager::InputManager()
{
    //ctor
}

InputManager::~InputManager()
{
    //dtor
}

//It would be really cool to use a template here! Maybe later...

void InputManager::addKey(sf::Keyboard::Key Key)
{
    Keys.push_back(Key);
}

bool InputManager::isKeyPressed(sf::Keyboard::Key Key)
{
    for(int i = 0; i < Keys.size(); i++)
    {
        if( Keys[i] == Key )
        {
            return true;
        }
    }
    return false;
}

void InputManager::addButton(sf::Mouse::Button Button)
{
    Buttons.push_back(Button);
}

bool InputManager::isButtonPressed(sf::Mouse::Button Button)
{
    for(int i = 0; i < Buttons.size(); i++)
    {
        if( Buttons[i] == Button )
        {
            Buttons.clear();
            return true;
        }
    }
    return false;
}


void InputManager::clear()
{
    std::vector<int>().swap(Keys);
    std::vector<int>().swap(Buttons);
}
