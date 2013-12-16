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
    mText.setString("1");
    mText.setPosition(mMap->GetPlayerSpawn());
    mText.setCharacterSize(mMap->GetEntitySize());
    mText.setColor(sf::Color(rand(),rand(),rand()));
    mText.setFont(mFont);
    mText.setStyle(sf::Text::Style::Bold);
    mType = ENT_PLYR;
    mLastUpdate = 0;
    mSpeed = 2;
}

void Player::Update(double dt)
{
    sf::Vector2i newPos(mText.getPosition());
    
    // Check Pattern Detector Key Bindings
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        mMap->CheckLeftPattern(mMap->PixelToMapCoord(newPos));
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        mMap->CheckRightPattern(mMap->PixelToMapCoord(newPos));
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        mMap->CheckUpPattern(mMap->PixelToMapCoord(newPos));
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        mMap->CheckDownPattern(mMap->PixelToMapCoord(newPos));
    
    // Check Movememnt Key Bindings
    if( sf::Keyboard::isKeyPressed(sf::Keyboard::D) )
        newPos.x += mMap->GetEntitySize();
    else if( sf::Keyboard::isKeyPressed(sf::Keyboard::A) )
        newPos.x -= mMap->GetEntitySize();
    else if( sf::Keyboard::isKeyPressed(sf::Keyboard::W) )
        newPos.y -= mMap->GetEntitySize();
    else if( sf::Keyboard::isKeyPressed(sf::Keyboard::S) )
        newPos.y += mMap->GetEntitySize();
    
    MapEntity* ent = mMap->GetEntity(mMap->PixelToMapCoord(newPos));
    if(ent->IsNode())
    {
        ent->NodeTouched();
    }
    else if(!ent->IsVisible())
        mText.setPosition(newPos.x,newPos.y);
}