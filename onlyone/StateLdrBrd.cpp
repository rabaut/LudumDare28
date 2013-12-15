//
//  StateLdrBrd.cpp
//  onlyone
//
//  Created by Sean Rabaut on 12/15/13.
//  Copyright (c) 2013 Sean Rabaut. All rights reserved.
//

#include "StateLdrBrd.h"
#include "ResourcePath.hpp"
#include <fstream>
#include <iomanip>
#include <sstream>

StateLdrBrd::StateLdrBrd(Game* game) : State(game)
{
    Initialize();
}

void StateLdrBrd::Initialize()
{
    // Read in the leader board if there is one
    std::ifstream loadFile;
    std::string file = "ldrbrd.txt";
    std::string board;
    
    loadFile.open (file, std::ifstream::in);
    if(!loadFile.good())
    {
        // Setup the leader board
        std::stringstream ss;
        std::ofstream saveFile (file);
        
        ss << std::setw(20) << std::left << "Usernames";
        ss << std::setw(28) << std::left << "|     Symbols Not Found";
        ss << std::setw(21) << std::left << "|  Time Remaining  |\n";
        ss << std::setfill('-')<< std::setw(68) << "-" << std::endl;
        
        board = ss.str();
        
        saveFile << board;
        
        saveFile.close();
    }
    else if(loadFile)
    {
        loadFile.seekg(0, std::ios::end);
        board.resize(loadFile.tellg());
        loadFile.seekg(0, std::ios::beg);
        loadFile.read(&board[0], board.size());
        loadFile.close();
    }
    board.append(mGame->GetLdrBrd());
    mFont.loadFromFile(resourcePath() + "UbuntuMono.ttf");
    mBoardText.setFont(mFont);
    mBoardText.setString(board);
    mBoardText.setCharacterSize(20);
    mBoardText.setPosition(0,0);
    mBoardText.setColor(sf::Color::Black);
    mInstrText.setFont(mFont);
    mInstrText.setString(" P to Play\nESC to Quit");
    mInstrText.setCharacterSize(20);
    mInstrText.setPosition(320,500);
}

void StateLdrBrd::Update()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::P))
    {
        mGame->SetState(Game::STATE_PLAY);
    }
}

void StateLdrBrd::Render(sf::RenderWindow* window)
{
    window->draw(mBoardText);
    mInstrText.setColor(sf::Color(rand(),rand(),rand()));
    window->draw(mInstrText);
}