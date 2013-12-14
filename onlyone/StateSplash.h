//
//  StateSplash.h
//  onlyone
//
//  Created by Sean Rabaut on 12/13/13.
//  Copyright (c) 2013 Sean Rabaut. All rights reserved.
//

#ifndef __onlyone__StateSplash__
#define __onlyone__StateSplash__

#include <iostream>
#include "State.h"

class StateSplash : public State
{
public:
    StateSplash(Game* game);
    
    virtual void Initialize();
    virtual void Update();
    virtual void Render(sf::RenderWindow* window);

private:
    //! Default constructor (disabled)
    StateSplash();
    
    //! Texture for the splash image
    sf::Texture mSplashTexture;
    //! Sprite for the splash iamge
    sf::Sprite mSplashSprite;
    //! Alpha value for fading splash image
    int mAlpha;
};

#endif /* defined(__onlyone__StateSplash__) */
