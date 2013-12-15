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
}

void MapEntity::UpdateColor()
{
    std::string s = mText.getString();
    unsigned int x=0;
    std::stringstream ss;
    ss << std::hex << s;
    ss >> x;
    x = static_cast<int>(x);
    SetColor(mMap->GetEntityColor(x));
}

void MapEntity::SetPosition(sf::Vector2i pos)
{
    mText.setPosition(pos.x,pos.y);
}

sf::Vector2i MapEntity::GetPosition()
{
    return sf::Vector2i(mText.getPosition().x,mText.getPosition().y);
}