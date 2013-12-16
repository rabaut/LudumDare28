//
//  Map.h
//  onlyone
//
//  Created by Sean Rabaut on 12/14/13.
//  Copyright (c) 2013 Sean Rabaut. All rights reserved.
//

#ifndef __onlyone__Map__
#define __onlyone__Map__

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <sstream>
#include "MapEntity.h"
#include "ResourcePath.hpp"

class Game;

class Map
{
public:
    Map(Game* game, int mapHeight=200, int mapWidth=200, int percentAreWalls=45, int entitySize=10);
    ~Map();
    
    void Render(sf::RenderWindow* window);
    
    bool IsEntity(sf::Vector2i point);
    MapEntity* GetEntity(sf::Vector2i point);
    
    void CheckLeftPattern(sf::Vector2i point);
    void CheckRightPattern(sf::Vector2i point);
    void CheckUpPattern(sf::Vector2i point);
    void CheckDownPattern(sf::Vector2i point);
    
    sf::Vector2f GetPlayerSpawn() {return mPlayerSpawn;}
    
    int GetEntitySize() {return mEntitySize;}
    sf::Color GetEntityColor(int n) {return mColors.at(n);}
    
    sf::Vector2i PixelToMapCoord(sf::Vector2i point);
    sf::Vector2i PixelToMapCoord(int x, int y);
    
    std::string GetFoundString() {return mFoundString;}
    
    void PlayNode();
    
    sf::Font* GetEntityFont();
    sf::Font* GetPlayerFont();
    
private:
    Map();
    int PlaceWallLogic(int x,int y);
    int GetAdjacentWalls(int x,int y,int scopeX,int scopeY);
    bool IsWall(int x,int y);
    bool IsOutOfBounds(int x, int y);
    void InitializeMap();
    void RandomFillMap();
    bool RandomPercent(int percent);
    void MakeNodes();
    void SymbolFound(std::string symbol);
    
    std::vector<std::vector<MapEntity*>> mMap;
    sf::Vector2i mMapSize;
    int mPercentAreWalls;
    int mEntitySize;
    std::string mFoundString;
    
    sf::Vector2f mPlayerSpawn;
    std::vector<sf::Color> mColors;
    
    sf::SoundBuffer mTransSound;
    sf::SoundBuffer mNodeSound;
    
    sf::Sound mSound;
        
    Game* mGame;
};

#endif /* defined(__onlyone__Map__) */
