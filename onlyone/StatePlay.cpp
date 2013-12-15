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
    mFont.loadFromFile(resourcePath() + "UbuntuMono.ttf");
    mFound.setFont(mFont);
    mTimeLeft.setFont(mFont);
    mFound.setPosition(20, 550);
    mTimeLeft.setPosition(600,550);
    mFound.setCharacterSize(20);
    mTimeLeft.setCharacterSize(20);
    mFound.setColor(sf::Color::Black);
    mTimeLeft.setColor(sf::Color::Black);
    mLastUpdate = mClock.getElapsedTime();
    mMusic.openFromFile(resourcePath() + "recording.wav");
    mMusic.play();
}

void StatePlay::Update()
{
    sf::Time currentTime = mClock.getElapsedTime();
    double timeRem = 60.0 - (currentTime.asMicroseconds() * 1e-6);
    std::string symbolsFound = mMap.GetFoundString();
    if(/*timeRem <= 55 || */(symbolsFound.find_first_not_of(' ') == std::string::npos))
    {
        std::string symbolsFound = mMap.GetFoundString();
        mGame->UpdateLdrBrd(symbolsFound, timeRem);
        mGame->SetState(Game::States::STATE_LDRBRD);
    }
    mTimeLeft.setString("Time Remaining: " + std::to_string(timeRem));
    mFound.setString("Symbols Remaining: " + mMap.GetFoundString());
    sf::Time dt = currentTime - mLastUpdate;
    mPlayer.Update(dt.asMicroseconds());
}

void StatePlay::Render(sf::RenderWindow* window)
{
    mMap.Render(window);
    mPlayer.Render(window);
    window->draw(mTimeLeft);
    window->draw(mFound);
}
