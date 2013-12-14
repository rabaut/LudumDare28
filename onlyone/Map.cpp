//
//  Map.cpp
//  onlyone
//
//  Created by Sean Rabaut on 12/14/13.
//  Copyright (c) 2013 Sean Rabaut. All rights reserved.
//

#include "Map.h"
#include "MapGenerator.h"

Map::Map(int mapWidth, int mapHeight)
{
    mMapWidth = mapWidth;
    mMapHeight = mapHeight;
    
    Generate();
}

void Map::Generate()
{
    MapGenerator mapGen(mMapWidth,mMapHeight);
    mMap = mapGen.GenerateMap();
}

void Map::PrintMap()
{
    std::cout << MapToString() << std::endl;
}

std::string Map::MapToString()
{
    std::string returnString;
    std::vector<std::string> mapSymbols;
    mapSymbols.push_back(".");
    mapSymbols.push_back("1");
    mapSymbols.push_back("+");
    
    for(int column=0,row=0; row < mMapHeight; row++ ) {
        for( column = 0; column < mMapWidth; column++ )
        {
            returnString += mapSymbols[mMap[column][row]];
        }
        returnString += '\n';
    }
    return returnString;
}