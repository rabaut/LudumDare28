//
//  StatePlay.cpp
//  onlyone
//
//  Created by Sean Rabaut on 12/13/13.
//  Copyright (c) 2013 Sean Rabaut. All rights reserved.
//

#include "StatePlay.h"

StatePlay::StatePlay(Game* game) : State(game), mMap(800,550,45,10), mPlayer(&mMap)
{
    mGame = game;
    Initialize();
}

StatePlay::~StatePlay()
{
    
}

void StatePlay::Initialize()
{
    mLastUpdate = mClock.getElapsedTime();
    mFont.loadFromFile(resourcePath() + "UbuntuMono.ttf");
    mScore.setFont(mFont);
    mTimeLeft.setFont(mFont);
    mScore.setPosition(20, 550);
    mTimeLeft.setPosition(600,550);
    mScore.setCharacterSize(20);
    mTimeLeft.setCharacterSize(20);
    mScore.setColor(sf::Color::Black);
    mTimeLeft.setColor(sf::Color::Black);
}

void StatePlay::Update()
{
    sf::Time currentTime = mClock.getElapsedTime();
    int timeRem = 60 - currentTime.asSeconds();
    mTimeLeft.setString("Time Remaining: " + std::to_string(timeRem));
    int score = mMap.GetScore();
    mScore.setString("Score: " + std::to_string(score));
    sf::Time dt = currentTime - mLastUpdate;
    mPlayer.Update(dt.asMicroseconds());
}

void StatePlay::Render(sf::RenderWindow* window)
{
    mMap.Render(window);
    mPlayer.Render(window);
    window->draw(mTimeLeft);
    window->draw(mScore);
}
