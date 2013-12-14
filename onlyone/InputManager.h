//
//  InputManager.h
//  Local
//
//  Created by Sean Rabaut on 7/8/13.
//  Copyright (c) 2013 Sean Rabaut. All rights reserved.
//

#ifndef __Local__InputManager__
#define __Local__InputManager__

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <algorithm>

class InputManager
{
public:
    InputManager();
    ~InputManager();
    
    void Update(sf::Event event);
    
    bool isKeyPressed(sf::Keyboard::Key Key);
    void addKey(sf::Keyboard::Key Key);
    
    bool isButtonPressed(sf::Mouse::Button Button);
    void addButton(sf::Mouse::Button Button);
    
    void clear();
    
private:
    sf::Event event;
    std::vector<int> Keys;
    std::vector<int> Buttons;
    std::vector<int>::iterator it;
};

#endif /* defined(__Local__InputManager__) */
