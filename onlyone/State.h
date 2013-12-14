//
//  State.h
//  onlyone
//
//  Created by Sean Rabaut on 12/13/13.
//  Copyright (c) 2013 Sean Rabaut. All rights reserved.
//

#ifndef __onlyone__State__
#define __onlyone__State__

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"

//! Abstract base class for States
class State
{
public:
    State(Game* game);
    virtual ~State();
    
    virtual void Initialize();
    virtual void Update();
    virtual void Render(sf::RenderWindow* window);
    
protected:
    //! Pointer to the game
    Game* mGame;
    
private:
    //! Default constructor (disabled)
    State();
};


#endif /* defined(__onlyone__State__) */
