//
//  main.cpp
//  onlyone
//
//  Created by Sean Rabaut on 12/13/13.
//  Copyright (c) 2013 Sean Rabaut. All rights reserved.
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "InputManager.h"
#include "Game.h"
#include "ResourcePath.hpp"

int main()
{
    const sf::Vector2i ScreenDimensions(600,600);
    
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(ScreenDimensions.x,ScreenDimensions.y),"YOU ONLY GET 1",sf::Style::None);
    window.setVerticalSyncEnabled(true);
    window.setKeyRepeatEnabled(false);
    
    InputManager InputManager;
    
    Game Game(&InputManager);
    
    Game.Start();
    
    
    sf::Clock clock;
    float updateRate = 1/60;
    
    // Start the game loop
    while ( window.isOpen() )
    {
        InputManager.clear();
        // Process events
        sf::Event event;
        
        //Loop through all keys
        for(int i = 0; i < sf::Keyboard::KeyCount; i++)
        {
            sf::Keyboard::Key Key = static_cast<sf::Keyboard::Key>(i);
            if(sf::Keyboard::isKeyPressed(Key))
            {
                InputManager.addKey(Key);
            }
        }
        
        //Loop through all mouse buttons
        for(int i = 0; i < sf::Mouse::ButtonCount; i++)
        {
            sf::Mouse::Button Button = static_cast<sf::Mouse::Button>(i);
            if(sf::Mouse::isButtonPressed(Button))
            {
                InputManager.addButton(Button);
            }
        }
        
        while ( window.pollEvent(event) )
        {
            // Close window : exit
            
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            // Espace pressed : exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            {
                window.close();
            }
        }
        
        // Clear screen
        if( clock.restart().asSeconds() > updateRate )
        {
            Game.Update();
        }
        
        //Update the window
        window.clear(sf::Color::White);
        Game.Render(&window);
        window.display();
    }
    
    return EXIT_SUCCESS;
}
