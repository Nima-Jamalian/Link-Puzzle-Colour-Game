//
//  Menu.hpp
//  Mini_Project_test
//
//  Created by Nima Jamalian on 27/11/2018.
//
#pragma once
#ifndef Menu_h
#define Menu_h
#include "ofMain.h"
class Menu {
public:
    int x, y, w, h;//Pos & Size
    string textRect = "";
    Menu(int _x, int _y, int _w, int _h, string _text);
    void outputRect();
    void drawRect();
    void drawRectText();
    bool overRect();
    void noFillOrLightColorDependingOnMouseOver();
    ofTrueTypeFont font;
};
#endif
