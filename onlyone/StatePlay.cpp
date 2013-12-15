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
    mIsGameOver = false;
    mFont.loadFromFile(resourcePath() + "UbuntuMono.ttf");
    mFound.setFont(mFont);
    mTimeLeft.setFont(mFont);
    mFound.setPosition(20, 550);
    mTimeLeft.setPosition(600,550);
    mFound.setCharacterSize(20);
    mTimeLeft.setCharacterSize(20);
    mFound.setColor(sf::Color::Black);
    mTimeLeft.setColor(sf::Color::Black);
    mGameOver.setFont(mFont);
    mGameOver.setCharacterSize(50);
    mGameOver.setString("GAME OVER");
    mGameOver.setPosition(270, 220);
    mLastUpdate = mClock.getElapsedTime();
    mMusic.openFromFile(resourcePath() + "recording.wav");
    mMusic.play();
    mBuffer.loadFromFile(resourcePath() + "gameover.wav");
}

void StatePlay::Update()
{
    sf::Time currentTime = mClock.getElapsedTime();
    if(!mIsGameOver)
    {
        double timeRem = 60.0 - (currentTime.asMicroseconds() * 1e-6);
        std::string symbolsFound = mMap.GetFoundString();
        if(timeRem <= 55 || (symbolsFound.find_first_not_of(' ') == std::string::npos))
        {
            mIsGameOver = true;
            mGameOverAnimTimer = currentTime.asSeconds();
            mMusic.stop();
            mSound.setBuffer(mBuffer);
            mSound.play();
            std::string symbolsFound = mMap.GetFoundString();
            mGame->UpdateLdrBrd(symbolsFound, timeRem);
        }
        mTimeLeft.setString("Time Remaining: " + std::to_string(timeRem));
        mFound.setString("Symbols Remaining: " + mMap.GetFoundString());
        sf::Time dt = currentTime - mLastUpdate;
        mPlayer.Update(dt.asMicroseconds());
    }
    else if(currentTime.asSeconds() - mGameOverAnimTimer > 3)
        mGame->SetState(Game::States::STATE_LDRBRD);

}

void StatePlay::Render(sf::RenderWindow* window)
{
    if(mIsGameOver)
    {
        mGameOver.setColor(sf::Color(rand(),rand(),rand()));
        window->draw(mGameOver);
    }
    mMap.Render(window);
    mPlayer.Render(window);
    window->draw(mTimeLeft);
    window->draw(mFound);
}
