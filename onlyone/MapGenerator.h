//
//  MapGenerator.h
//  onlyone
//
//  Created by Sean Rabaut on 12/13/13.
//  Copyright (c) 2013 Sean Rabaut. All rights reserved.
///Users/OPTIMUS/Desktop/onlyone/onlyone/MapGenerator.cpp

#ifndef __onlyone__MapGenerator__
#define __onlyone__MapGenerator__

#include <iostream>
#include <vector>

class MapGenerator
{
public:
    MapGenerator(int mapWidth=40, int mapHeight=21, int percentAreWalls=40);
    
    int** GenerateMap();
    
private:
    int** mMap;
    int mMapWidth;
    int mMapHeight;
    int mPercentAreWalls;
    
    void MakeCaverns();
    int PlaceWallLogic(int x,int y);
    int GetAdjacentWalls(int x,int y,int scopeX,int scopeY);
    bool IsWall(int x,int y);
    bool IsOutOfBounds(int x, int y);
    void BlankMap();
    void RandomFillMap();
    
    int RandomPercent(int percent);
};

#endif /* defined(__onlyone__MapGenerator__) */
