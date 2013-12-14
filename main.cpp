
//
// Disclamer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resource, use the helper
// method resourcePath() from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "InputManager.h"
#include "Game.h"

// Here is a small helper for you ! Have a look.
#include "ResourcePath.hpp"

int main()
{
    const sf::Vector2i ScreenDimensions(960,540);
    
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(ScreenDimensions.x,ScreenDimensions.y),"YOU ONLY GET 1");
    window.setVerticalSyncEnabled(true);
    window.setKeyRepeatEnabled(false);
    
    Game Game;
    
    InputManager InputManager;
    
    sf::Clock clock;
    float updateRate = 1/2;
    
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
        window.clear();
        Game.Render(window);
        window.display();
    }
    
    return EXIT_SUCCESS;
}
