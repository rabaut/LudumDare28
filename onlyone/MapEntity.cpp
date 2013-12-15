//
//  MapEntity.cpp
//  onlyone
//
//  Created by Sean Rabaut on 12/14/13.
//  Copyright (c) 2013 Sean Rabaut. All rights reserved.
//

#include "MapEntity.h"
#include "Map.h"
#include <sstream>
#include "ResourcePath.hpp"

MapEntity::MapEntity(Map* map)
{
    mMap = map;
    mFont.loadFromFile(resourcePath() + "sansation.ttf");
    mText.setFont(mFont); mActive = false;
    mHex = false;
    mBorder = false;
}

void MapEntity::UpdateColor(int n)
{
    SetColor(mMap->GetEntityColor(n));
}

void MapEntity::SetPosition(sf::Vector2i pos)
{
    mText.setPosition(pos.x,pos.y);
}

sf::Vector2i MapEntity::GetPosition()
{
    return sf::Vector2i(mText.getPosition().x,mText.getPosition().y);
}

void MapEntity::Render(sf::RenderWindow *window)
{
    if(mActive)
    {
        if(!mHex && !mBorder)
            mText.setColor(sf::Color(rand(),rand(),rand()));
        window->draw(mText);
    }
}

void MapEntity::SetHex(bool hex)
{
    mHex = hex;
    mText.setStyle(sf::Text::Style::Italic);
}

void MapEntity::SetBorder()
{
    mBorder = true;
    mActive = true;
    mText.setString("*");
    mText.setStyle(sf::Text::Style::Bold);
    mText.setColor(sf::Color::Black);
}