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
    mType = ENT_BIN;
    mMap = map;
    mFont.loadFromFile(resourcePath() + "sansation.ttf");
    mText.setFont(mFont);
    int value = rand()%2;
    mText.setString(std::to_string(value));
    mText.setCharacterSize(map->GetEntitySize());
    mText.setColor(mMap->GetEntityColor(value));
    mVisible = true;
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
    if(mVisible)
    {
        if(mType == ENT_NODE)
            mText.setColor(sf::Color(rand(),rand(),rand()));
        window->draw(mText);
    }
}

void MapEntity::SetHex()
{
    mType = ENT_HEX;
    mText.setStyle(sf::Text::Style::Italic);
}

void MapEntity::SetBorder()
{
    mType = ENT_BORDER;
    mText.setString("*");
    mText.setStyle(sf::Text::Style::Bold);
    mText.setColor(sf::Color::White);
}

void MapEntity::SetNode()
{
    mType = ENT_NODE;
    mText.setString("@");
    mText.setStyle(sf::Text::Style::Bold);
}

void MapEntity::NodeTouched()
{
    mType = ENT_HEX;
    char pos[5];
    for(int i = 0; i < 5; i++)
    {
        pos[i] = 65+i;
    }
    int r = rand() % 5;
    mText.setString(pos[r]);
    mMap->PlayNode();
}