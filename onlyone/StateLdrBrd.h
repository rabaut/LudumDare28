//
//  StateLdrBrd.h
//  onlyone
//
//  Created by Sean Rabaut on 12/15/13.
//  Copyright (c) 2013 Sean Rabaut. All rights reserved.
//

#ifndef __onlyone__StateLdrBrd__
#define __onlyone__StateLdrBrd__

#include <iostream>
#include "State.h"

class StateLdrBrd : public State
{
public:
    StateLdrBrd(Game* game);
    
    virtual void Initialize();
    virtual void Update();
    virtual void Render(sf::RenderWindow* window);
    
private:
    sf::Text mText;
    sf::Font mFont;
};


#endif /* defined(__onlyone__StateLdrBrd__) */
