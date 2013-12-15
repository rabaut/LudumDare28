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
    
    enum EntType
    {
        ENT_BIN,
        ENT_HEX,
        ENT_BORDER,
        ENT_NODE,
        ENT_PLYR
    };
    
    void SetColor(sf::Color color) {mText.setColor(color);}
    sf::Color GetColor() {return mText.getColor();}
    
    void SetVisible(bool b) {mVisible = b;}
    bool IsVisible() {return mVisible;}
    
    void SetBinary();
    bool IsBinary() {return mType == ENT_BIN;}
    
    void SetHex();
    bool IsHex() {return mType == ENT_HEX;}
    
    void SetBorder();
    bool IsBorder() {return mType == ENT_BORDER;}
    
    void SetNode();
    bool IsNode() {return mType == ENT_NODE;}
    
    void NodeTouched();
    
    void SetString(sf::String string) {mText.setString(string);}
    sf::String GetString() {return mText.getString();}
    
    void UpdateColor(int n);
    
    void SetPosition(sf::Vector2i pos);
    sf::Vector2i GetPosition();
    
    void Render(sf::RenderWindow* window);
    
protected:
    sf::Text mText;
    sf::Font mFont;
    bool mVisible;
    Map* mMap;
    EntType mType;
    
private:
    MapEntity();
};

#endif /* defined(__onlyone__MapEntity__) */
