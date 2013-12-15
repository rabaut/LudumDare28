//
//  Player.cpp
//  onlyone
//
//  Created by Sean Rabaut on 12/14/13.
//  Copyright (c) 2013 Sean Rabaut. All rights reserved.
//

#include "Player.h"
#include "ResourcePath.hpp"

Player::Player(Map* map) : MapEntity(map)
{
    mFont.loadFromFile(resourcePath() + "UbuntuMono.ttf");
    mActive = true;
    mText.setString("1");
    mText.setPosition(mMap->MapCoordToPixel(mMap->GetPlayerSpawn()));
    mText.setCharacterSize(mMap->GetEntitySize());
    mText.setColor(mMap->GetPlayerColor());
    mText.setFont(mFont);
}

void Player::Update(InputManager* input)
{
    sf::Vector2i newPos(mText.getPosition());
    
    // Check Pattern Detector Key Bindings
    if( input->isKeyPressed(sf::Keyboard::Left))
    {
        mMap->CheckLeftPattern(mMap->PixelToMapCoord(newPos));
    }
    else if( input->isKeyPressed(sf::Keyboard::Right))
    {
        mMap->CheckRightPattern(mMap->PixelToMapCoord(newPos));
    }
    else if( input->isKeyPressed(sf::Keyboard::Up))
    {
        mMap->CheckUpPattern(mMap->PixelToMapCoord(newPos));
    }
    else if( input->isKeyPressed(sf::Keyboard::Down))
    {
        mMap->CheckDownPattern(mMap->PixelToMapCoord(newPos));
    }
    
    // Check Movememnt Key Bindings
    if( input->isKeyPressed(sf::Keyboard::D) )
        newPos.x += GetSize();
    else if( input->isKeyPressed(sf::Keyboard::A) )
        newPos.x -= GetSize();
    else if( input->isKeyPressed(sf::Keyboard::W) )
        newPos.y -= GetSize();
    else if( input->isKeyPressed(sf::Keyboard::S) )
        newPos.y += GetSize();
    
    if(!mMap->IsEntity(mMap->PixelToMapCoord(newPos)))
        mText.setPosition(newPos.x,newPos.y);
}

void Player::Render(sf::RenderWindow *window)
{
    if(mActive)
    {
        window->draw(mText);
    }
}