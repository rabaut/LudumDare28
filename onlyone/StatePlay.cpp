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
    mTimeLeft.setPosition(570,550);
    mFound.setCharacterSize(20);
    mTimeLeft.setCharacterSize(20);
    mFound.setColor(sf::Color::Black);
    mTimeLeft.setColor(sf::Color::Black);
    mGameOver.setFont(mFont);
    mGameOver.setCharacterSize(100);
    mGameOver.setPosition(190, 120);
    mInstrText.setFont(mFont);
    mInstrText.setString("ENT to Play Again\n        or\n  ESC to Give Up");
    mInstrText.setCharacterSize(30);
    mInstrText.setPosition(265,280);
    mInstrText.setColor(sf::Color::Black);
    mInstrText.setStyle(sf::Text::Style::Bold);
    mLastUpdate = mClock.getElapsedTime();
    mMusic.openFromFile(resourcePath() + "recording.wav");
    mMusic.play();
    mMusic.setLoop(true);
    mLoseBuffer.loadFromFile(resourcePath() + "gameover.wav");
    mWinBuffer.loadFromFile(resourcePath() + "gamewon.wav");
}

void StatePlay::Update()
{
    sf::Time currentTime = mClock.getElapsedTime();
    if(!mIsGameOver)
    {
        double timeRem = 60.0 - (currentTime.asMicroseconds() * 1e-6);
        std::string symbolsFound = mMap.GetFoundString();
        if(timeRem <= 0)
        {
            timeRem = 0.0;
            mIsGameOver = true;
            mGameOver.setString("GAME OVER");
            mMusic.stop();
            mSound.setBuffer(mLoseBuffer);
            mSound.play();
        }
        if(symbolsFound.find_first_not_of(' ') == std::string::npos)
        {
            mIsGameOver = true;
            mGameOver.setString("YOU WON!!");
            mMusic.stop();
            mSound.setBuffer(mWinBuffer);
            mSound.play();
        }
        mTimeLeft.setString("Time Remaining: " + std::to_string(timeRem));
        mFound.setString("Symbols Remaining: " + mMap.GetFoundString());
        sf::Time dt = currentTime - mLastUpdate;
        mPlayer.Update(dt.asMicroseconds());
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
    {
        mGame->SetState(Game::States::STATE_PLAY);
    }
}

void StatePlay::Render(sf::RenderWindow* window)
{
    mMap.Render(window);
    mPlayer.Render(window);
    window->draw(mTimeLeft);
    window->draw(mFound);
    if(mIsGameOver)
    {
        mGameOver.setColor(sf::Color(rand(),rand(),rand()));
        window->draw(mInstrText);
        window->draw(mGameOver);
    }
}
