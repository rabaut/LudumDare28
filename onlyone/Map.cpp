//
//  Map.cpp
//  onlyone
//
//  Created by Sean Rabaut on 12/14/13.
//  Copyright (c) 2013 Sean Rabaut. All rights reserved.
//

#include "Map.h"
#include "ResourcePath.hpp"
#include <sstream>
#include <algorithm>
#include <stdio.h>

using namespace std;

Map::Map(int mapWidth, int mapHeight, int percentAreWalls, int entitySize)
{
    mEntitySize = entitySize;
    mMapSize = PixelToMapCoord(mapWidth, mapHeight);
    mPercentAreWalls = percentAreWalls;
    // Symbols that need to be found
    mFoundString = "2 3 4 5 6 7 8 9 A B C D E F";
    
    mPlayerSpawn.x = mMapSize.x/2;
    mPlayerSpawn.y = mMapSize.y/2;

    for(int i=0;i<16;i++)
        mColors.push_back(sf::Color(rand(),rand(),rand()));
    
    mTransSound.loadFromFile(resourcePath() + "transform.wav");
    mNodeSound.loadFromFile(resourcePath() + "node.wav");

    InitializeMap();
    MakeNodes();
    RandomFillMap();
}

Map::~Map()
{
    for(int x = 0,y = 0; x < mMapSize.x; x++ )
    {
        for( y = 0; y < mMapSize.y; y++ )
        {
            mMap[x].erase(mMap[x].begin()+y);
        }
        mMap.erase(mMap.begin()+x);
    }
}

void Map::Render(sf::RenderWindow *window)
{
    for(int x = 0,y = 0; x < mMapSize.x; x++ )
    {
        for( y = 0; y < mMapSize.y; y++ )
        {
            mMap[x][y]->Render(window);
        }
    }
}

void Map::InitializeMap()
{
    // Initialize the map entities
    std::vector<MapEntity*> column;
    for(int x = 0,y = 0; x < mMapSize.x; x++ )
    {
        for( y = 0; y < mMapSize.y; y++ )
        {
            MapEntity* ent = new MapEntity(this);
            ent->SetPosition(sf::Vector2i(x*mEntitySize,y*mEntitySize));
            column.push_back(ent);
        }
        mMap.push_back(column);
        column.clear();
    }
}

void Map::RandomFillMap()
{
    int mapMiddle = 0; // Temp variable
    for(int x = 0,y = 0; x < mMapSize.x; x++ )
    {
        for( y = 0; y < mMapSize.y; y++ )
        {
            // If coordinants lie on the the edge of the map make them a border
            if(x == 0 || y == 0 || x == mMapSize.x-1 || y == mMapSize.y-1)
            {
                mMap[x][y]->SetBorder();
            }
            // Else, fill with a wall a random percent of the time
            else if(!mMap[x][y]->IsNode())
            {
                mapMiddle = (mMapSize.x / 2);
                
                if(x == mapMiddle)
                {
                    mMap[x][y]->SetVisible(false);
                }
                else
                {
                    if(!RandomPercent(mPercentAreWalls))
                    {
                        mMap[x][y]->SetVisible(false);
                    }
                }
            }
        }
    }
}

void Map::MakeNodes()
{
    //Top Left Node
    mMap[3][3]->SetNode();
    mMap[3][4]->SetNode();
    mMap[4][3]->SetNode();
    mMap[4][4]->SetNode();
    
    //Top Right Node
    mMap[mMapSize.x-4][3]->SetNode();
    mMap[mMapSize.x-4][4]->SetNode();
    mMap[mMapSize.x-5][3]->SetNode();
    mMap[mMapSize.x-5][4]->SetNode();
    
    //Bottom Left Node
    mMap[3][mMapSize.y-4]->SetNode();
    mMap[3][mMapSize.y-5]->SetNode();
    mMap[4][mMapSize.y-4]->SetNode();
    mMap[4][mMapSize.y-5]->SetNode();
    
    //Bottom Right Node
    mMap[mMapSize.x-4][mMapSize.y-4]->SetNode();
    mMap[mMapSize.x-4][mMapSize.y-5]->SetNode();
    mMap[mMapSize.x-5][mMapSize.y-4]->SetNode();
    mMap[mMapSize.x-5][mMapSize.y-5]->SetNode();
    
}

int Map::PlaceWallLogic(int x,int y)
{
    int numWalls = GetAdjacentWalls(x,y,1,1);
    
    
    if(mMap[x][y]->IsVisible())
    {
        if( numWalls >= 4 )
        {
            return 1;
        }
        if(numWalls<2)
        {
            return 0;
        }
    }
    else
    {
        if(numWalls>=5)
        {
            return 1;
        }
    }
    return 0;
}

int Map::GetAdjacentWalls(int x,int y,int scopeX,int scopeY)
{
    int startX = x - scopeX;
    int startY = y - scopeY;
    int endX = x + scopeX;
    int endY = y + scopeY;
    
    int wallCounter = 0;
    
    for(int iX = startX, iY; iX <= endX; iX++)
    {
        for(iY = startY; iY <= endY; iY++)
        {
            if(!(iX==x && iY==y))
            {
                if(IsEntity(sf::Vector2i(iX,iY)))
                {
                    wallCounter += 1;
                }
            }
        }
    }
    return wallCounter;
}

bool Map::IsEntity(sf::Vector2i point)
{
    if( mMap[point.x][point.y]->IsVisible() )
    {
        return true;
    }
    return false;
}

MapEntity* Map::GetEntity(sf::Vector2i point)
{
    return mMap[point.x][point.y];
}

bool Map::IsOutOfBounds(int x, int y)
{
    if( x<0 || y<0 )
    {
        return true;
    }
    else if( x>mMapSize.x-1 || y>mMapSize.y-1 )
    {
        return true;
    }
    return false;
}

bool Map::RandomPercent(int percent)
{
    if( percent >= (rand() % 100) )
    {
        return true;
    }
    return false;
}

// This is used to check if an entity is a border element
bool IsBorder(char c) {return (c == '*');}

void Map::CheckLeftPattern(sf::Vector2i point)
{
    string pattern("");
    //Check in left direction for pattern
    for(int x = point.x-1; x > point.x-4; x--)
    {
        sf::Vector2i nextEntity(x,point.y);
        if(!IsOutOfBounds(x-1,point.y))
        {
            if(IsEntity(nextEntity) && !mMap[x][point.y]->IsHex() &&
               !mMap[x][point.y]->IsNode())
                pattern.append(mMap[x][point.y]->GetString());
            else
                break;
        }
        else
            break;
    }
    pattern.push_back('1');
    std::remove_if(pattern.begin(),pattern.end(), IsBorder);
    pattern.shrink_to_fit();
    if(pattern.length() > 1)
    {
        unsigned long long int dec;
        dec = strtoul(pattern.c_str(), NULL, 2);
        char hexString[5];
        std::snprintf(hexString, 7, "%llX", dec);
        for(int i = 1; i < pattern.length()-1; i++)
        {
            mMap[point.x-i][point.y]->SetVisible(false);
        }
        mMap[point.x-(pattern.length()-1)][point.y]->SetString(hexString);
        mMap[point.x-(pattern.length()-1)][point.y]->UpdateColor(dec);
        mMap[point.x-(pattern.length()-1)][point.y]->SetHex();
        SymbolFound(hexString);
    }
}
void Map::CheckRightPattern(sf::Vector2i point)
{
    string pattern("");
    //Check in left direction for pattern
    for(int x = point.x+1; x < point.x+4; x++)
    {
        sf::Vector2i nextEntity(x,point.y);
        if(!IsOutOfBounds(x+1,point.y))
        {
            if(IsEntity(nextEntity) && !mMap[x][point.y]->IsHex() &&
               !mMap[x][point.y]->IsNode())
                pattern.append(mMap[x][point.y]->GetString());
            else
                break;
        }
        else
            break;
    }
    pattern.insert(pattern.begin(),'1');
    std::remove_if(pattern.begin(),pattern.end(), IsBorder);
    pattern.shrink_to_fit();
    if(pattern.length() > 1)
    {
        unsigned long long int dec;
        dec = strtoul(pattern.c_str(), NULL, 2);
        char hexString[5];
        std::snprintf(hexString, 7, "%llX", dec);
        for(int i = 1; i < pattern.length()-1; i++)
        {
            mMap[point.x+i][point.y]->SetVisible(false);
        }
        mMap[point.x+(pattern.length()-1)][point.y]->SetString(hexString);
        mMap[point.x+(pattern.length()-1)][point.y]->SetHex();
        mMap[point.x+(pattern.length()-1)][point.y]->UpdateColor(dec);
        SymbolFound(hexString);
    }
}
void Map::CheckUpPattern(sf::Vector2i point)
{
    string pattern("");
    //Check in left direction for pattern
    for(int y = point.y-1; y > point.y-4; y--)
    {
        sf::Vector2i nextEntity(point.x,y);
        if(!IsOutOfBounds(point.x,y-1))
        {
            if(IsEntity(nextEntity) && !mMap[point.x][y]->IsHex() &&
               !mMap[point.x][y]->IsNode())
                pattern.append(mMap[point.x][y]->GetString());
            else
                break;
        }
        else
            break;
    }
    pattern.push_back('1');
    std::remove_if(pattern.begin(),pattern.end(), IsBorder);
    pattern.shrink_to_fit();
    if(pattern.length() > 1)
    {
        unsigned long long int dec;
        dec = strtoul(pattern.c_str(), NULL, 2);
        char hexString[5];
        std::snprintf(hexString, 7, "%llX", dec);
        for(int i = 1; i < pattern.length()-1; i++)
        {
            mMap[point.x][point.y-i]->SetVisible(false);
        }
        mMap[point.x][point.y-(pattern.length()-1)]->SetString(hexString);
        mMap[point.x][point.y-(pattern.length()-1)]->SetHex();
        mMap[point.x][point.y-(pattern.length()-1)]->UpdateColor(dec);
        SymbolFound(hexString);
    }
}
void Map::CheckDownPattern(sf::Vector2i point)
{
    string pattern("");
    //Check in left direction for pattern
    for(int y = point.y+1; y < point.y+4; y++)
    {
        sf::Vector2i nextEntity(point.x,y);
        if(!IsOutOfBounds(point.x,y+1))
        {
            if(IsEntity(nextEntity) && !mMap[point.x][y]->IsHex() &&
               !mMap[point.x][y]->IsNode())
                pattern.append(mMap[point.x][y]->GetString());
            else
                break;
        }
        else
            break;
    }
    pattern.insert(pattern.begin(),'1');
    std::remove_if(pattern.begin(),pattern.end(), IsBorder);
    pattern.shrink_to_fit();
    if(pattern.length() > 1)
    {
        unsigned long long int dec;
        dec = strtoul(pattern.c_str(), NULL, 2);
        char hexString[5];
        std::snprintf(hexString, 7, "%llX", dec);
        for(int i = 1; i < pattern.length()-1; i++)
        {
            mMap[point.x][point.y+i]->SetVisible(false);
        }
        mMap[point.x][point.y+(pattern.length()-1)]->SetString(hexString);
        mMap[point.x][point.y+(pattern.length()-1)]->UpdateColor(dec);
        mMap[point.x][point.y+(pattern.length()-1)]->SetHex();
        SymbolFound(hexString);
    }
}

void Map::SymbolFound(std::string symbol)
{
    mSound.setBuffer(mTransSound);
    mSound.play();
    size_t f = mFoundString.find(symbol);
    if(f!=std::string::npos)
        mFoundString.replace(f, symbol.length(), " ");
}


void Map::PlayNode()
{
    mSound.setBuffer(mNodeSound);
    mSound.play();
}

sf::Vector2i Map::PixelToMapCoord(sf::Vector2i point)
{
    return sf::Vector2i(point.x/mEntitySize,point.y/mEntitySize);
}
sf::Vector2i Map::PixelToMapCoord(int x, int y)
{
    return sf::Vector2i(x/mEntitySize,y/mEntitySize);
}