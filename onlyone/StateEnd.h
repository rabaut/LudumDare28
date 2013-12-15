//
//  StateEnd.h
//  onlyone
//
//  Created by Sean Rabaut on 12/15/13.
//  Copyright (c) 2013 Sean Rabaut. All rights reserved.
//

#ifndef __onlyone__StateEnd__
#define __onlyone__StateEnd__

#include <iostream>

#include "State.h"

class StateEnd : public State
{
public:
    StateEnd(Game* game);
    
    virtual void Initialize();
    virtual void Update();
    virtual void Render(sf::RenderWindow* window);
    
private:
    sf::Texture mTexture;
    sf::Sprite mSprite;
    sf::Text mText;
    sf::Font mFont;
    
};

#endif /* defined(__onlyone__StateEnd__) */
