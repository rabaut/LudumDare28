//
//  Map.h
//  onlyone
//
//  Created by Sean Rabaut on 12/14/13.
//  Copyright (c) 2013 Sean Rabaut. All rights reserved.
//

#ifndef __onlyone__Map__
#define __onlyone__Map__

#include <iostream>
#include <vector>

class Map
{
public:
    Map(int mapHeight=600, int mapWidth=800);
    
    void PrintMap();
    std::string MapToString();
    
private:
    Map();
    int** mMap;
    
    void Generate();
    
    int mMapHeight;
    int mMapWidth;
};

#endif /* defined(__onlyone__Map__) */
