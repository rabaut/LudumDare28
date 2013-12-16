//
//  Player.h
//  onlyone
//
//  Created by Sean Rabaut on 12/14/13.
//  Copyright (c) 2013 Sean Rabaut. All rights reserved.
//

#ifndef __onlyone__Player__
#define __onlyone__Player__

#include <iostream>
#include "Map.h"
#include "MapEntity.h"

class Player : public MapEntity
{
public:
    Player(Map* map);
    
    void Update();

private:
    Player();
};

#endif /* defined(__onlyone__Player__) */
