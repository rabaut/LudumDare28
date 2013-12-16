//
//  main.cpp
//  onlyone
//
//  Created by Sean Rabaut on 12/13/13.
//  Copyright (c) 2013 Sean Rabaut. All rights reserved.
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "ResourcePath.hpp"

int main()
{
    const sf::Vector2i ScreenDimensions(800,600);
    
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(ScreenDimensions.x,ScreenDimensions.y),"YOU ONLY GET 1111");
    window.setVerticalSyncEnabled(true);
    window.setKeyRepeatEnabled(false);
    window.setMouseCursorVisible(false);
    
    Game Game;
    
    Game.Start();
    
    //Initialize our random seed
    srand (time(NULL));
    
    sf::Clock clock;
    float updateRate = 1/60;
    
    // Start the game loop
    while ( window.isOpen() )
    {
        // Process events
        sf::Event event;
        
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
        
        if( clock.restart().asSeconds() > updateRate )
        {
            Game.Update();
        }
        
        window.clear(sf::Color::Black);
        Game.Render(&window);
        window.display();
    }
    
    return EXIT_SUCCESS;
}
