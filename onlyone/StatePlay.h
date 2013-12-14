//
//  StatePlay.h
//  onlyone
//
//  Created by Sean Rabaut on 12/13/13.
//  Copyright (c) 2013 Sean Rabaut. All rights reserved.
//

#ifndef __onlyone__StatePlay__
#define __onlyone__StatePlay__

#include <iostream>
#include "State.h"

class StatePlay : public State
{
public:
    StatePlay(Game* game);
    ~StatePlay();
    
    virtual void Initialize();
    virtual void Update();
    virtual void Render(sf::RenderWindow* window);
    
private:
    
};

#endif /* defined(__onlyone__StatePlay__) */
