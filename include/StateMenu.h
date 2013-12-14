//
//  StateMenu.h
//  onlyone
//
//  Created by Sean Rabaut on 12/13/13.
//  Copyright (c) 2013 Sean Rabaut. All rights reserved.
//

#ifndef __onlyone__StateMenu__
#define __onlyone__StateMenu__

#include <iostream>
#include "State.h"

class StateMenu : public State
{
public:
    StateMenu(Game* game);
    ~StateMenu();

};

#endif /* defined(__onlyone__StateMenu__) */
