//
//  MapGenerator.cpp
//  onlyone
//
//  Created by Sean Rabaut on 12/13/13.
//  Copyright (c) 2013 Sean Rabaut. All rights reserved.
//

#include "MapGenerator.h"
#include <stdlib.h>

MapGenerator::MapGenerator(int mapWidth, int mapHeight, int percentAreWalls)
{
    mMapWidth = mapWidth;
    mMapHeight = mapHeight;
    mPercentAreWalls = percentAreWalls;
    
    RandomFillMap();
}

void MapGenerator::GenerateMap()
{
    
}

void MapGenerator::MakeCaverns()
{
    // By initilizing column in the outter loop, its only created ONCE
    for(int column=0, row=0; row <= mMapHeight-1; row++)
    {
        for(column = 0; column <= mMapWidth-1; column++)
        {
            mMap[column][row] = PlaceWallLogic(column,row);
        }
    }
}

int MapGenerator::PlaceWallLogic(int x,int y)
{
    int numWalls = GetAdjacentWalls(x,y,1,1);
    
    
    if(mMap[x][y]==1)
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

int MapGenerator::GetAdjacentWalls(int x,int y,int scopeX,int scopeY)
{
    int startX = x - scopeX;
    int startY = y - scopeY;
    int endX = x + scopeX;
    int endY = y + scopeY;
    
    int iX = startX;
    int iY = startY;
    
    int wallCounter = 0;
    
    for(iY = startY; iY <= endY; iY++) {
        for(iX = startX; iX <= endX; iX++)
        {
            if(!(iX==x && iY==y))
            {
                if(IsWall(iX,iY))
                {
                    wallCounter += 1;
                }
            }
        }
    }
    return wallCounter;
}

bool MapGenerator::IsWall(int x,int y)
{
    // Consider out-of-bound a wall
    if( IsOutOfBounds(x,y) )
    {
        return true;
    }
    
    if( mMap[x][y]==1	 )
    {
        return true;
    }
    
    if( mMap[x][y]==0	 )
    {
        return false;
    }
    return false;
}

bool MapGenerator::IsOutOfBounds(int x, int y)
{
    if( x<0 || y<0 )
    {
        return true;
    }
    else if( x>mMapWidth-1 || y>mMapHeight-1 )
    {
        return true;
    }
    return false;
}

void MapGenerator::PrintMap()
{
    //Console.Write(MapToString());
}

std::string MapGenerator::MapToString()
{
//    std::string returnString = std::string.Join(" ", // Seperator between each element
//                                      "Width:",
//                                      MapWidth.ToString(),
//                                      "\tHeight:",
//                                      MapHeight.ToString(),
//                                      "\t% Walls:",
//                                      PercentAreWalls.ToString(),
//                                      Environment.NewLine
//                                      );
//    
//    List<string> mapSymbols = new List<string>();
//    mapSymbols.Add(".");
//    mapSymbols.Add("#");
//    mapSymbols.Add("+");
//    
//    for(int column=0,row=0; row < MapHeight; row++ ) {
//        for( column = 0; column < MapWidth; column++ )
//        {
//            returnString += mapSymbols[Map[column,row]];
//        }
//        returnString += Environment.NewLine;
//    }
//    return returnString;
}

void MapGenerator::BlankMap()
{
    for(int column=0,row=0; row < mMapHeight; row++) {
        for(column = 0; column < mMapWidth; column++) {
            mMap[column][row] = 0;
        }
    }
}

void MapGenerator::RandomFillMap()
{
    
    int mapMiddle = 0; // Temp variable
    for(int column=0,row=0; row < mMapHeight; row++) {
        for(column = 0; column < mMapWidth; column++)
        {
            // If coordinants lie on the the edge of the map (creates a border)
            if(column == 0)
            {
                mMap[column][row] = 1;
            }
            else if (row == 0)
            {
                mMap[column][row] = 1;
            }
            else if (column == mMapWidth-1)
            {
                mMap[column][row] = 1;
            }
            else if (row == mMapHeight-1)
            {
                mMap[column][row] = 1;
            }
            // Else, fill with a wall a random percent of the time
            else
            {
                mapMiddle = (mMapHeight / 2);
                
                if(row == mapMiddle)
                {
                    mMap[column][row] = 0;
                }
                else
                {
                    mMap[column][row] = RandomPercent(mPercentAreWalls);
                }
            }
        }
    }
}

int MapGenerator::RandomPercent(int percent)
{
    if( percent >= (rand() % 100) )
    {
        return 1;
    }
    return 0;
}
