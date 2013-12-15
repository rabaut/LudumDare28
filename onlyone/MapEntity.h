//
//  MapEntity.h
//  onlyone
//
//  Created by Sean Rabaut on 12/14/13.
//  Copyright (c) 2013 Sean Rabaut. All rights reserved.
//

#ifndef __onlyone__MapEntity__
#define __onlyone__MapEntity__

#include <SFML/Graphics.hpp>
#include <iostream>

class Map;

class MapEntity
{
public:
    MapEntity(Map* map);
    
    void SetColor(sf::Color color) {mText.setColor(color);}
    sf::Color GetColor() {return mText.getColor();}
    
    void SetActive(bool active) {mActive = active;}
    bool IsActive() {return mActive;}
    
    void SetString(sf::String string) {mText.setString(string);}
    sf::String GetString() {return mText.getString();}
    
    void UpdateColor();
    
    void SetPosition(sf::Vector2i pos);
    sf::Vector2i GetPosition();
    
    void SetSize(int size) {mText.setCharacterSize(size);}
    int GetSize() {return mText.getCharacterSize();}
    
    virtual void Render(sf::RenderWindow* window) {
        if(mActive) window->draw(mText);}
    
protected:
    sf::Text mText;
    sf::Font mFont;
    Map* mMap;
    bool mActive;
    
private:
    MapEntity();
};

#endif /* defined(__onlyone__MapEntity__) */
