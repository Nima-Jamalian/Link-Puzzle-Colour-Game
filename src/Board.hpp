//
//  Board.hpp
//  Mini_Project_test
//
//  Created by Nima Jamalian on 27/11/2018.
//

#pragma once
#ifndef Board_hpp
#define Board_hpp
#include "ofMain.h"
#include "GameData.hpp"

class Board {
public:
    Board();
    vector <vector <int> > level;
    //ellipse center
    int ec;
    //size of the board
    int grid;
    //position of x when you start
    int startx;
    //game level
    bool levelChosen = false;
    //position of y when you start
    int starty;
    //current position of x
    int currentx;
    //corrent position of y
    int currenty;
    //for check if you won
    bool selected = false;
    bool won = false;
    //timer
    int milliseconds;
    int millisecond10;
    int seconds;
    int minutes;
    //moves
    int moves;
    //-------------------------------
    void draw();
    void checkwin();
    void timerandmoves();
    //-------------------------------
    ofTrueTypeFont font;
    ofTrueTypeFont font1;
    //-------------------------------
    ofColor numToColor(int num) {
        if (num == 1) return ofColor(0, 0, 255);
        if (num == 2) return ofColor(255, 0, 0);
        if (num == 3) return ofColor(255, 100, 0);
        if (num == 4) return ofColor(0, 255, 0);
        if (num == 5) return ofColor(0, 255, 255);
        if (num == 6) return ofColor(255, 0, 255);
        if (num == 7) return ofColor(255, 255, 0);
        if (num == 8) return ofColor(76, 0, 153);
        return ofColor(255);
    }
    //----------------------------------------------------------
    ofColor numToColorPipe(int num) {
        if (num == 1) return ofColor(0, 0, 255, 100);
        if (num == 2) return ofColor(255, 0, 0, 100);
        if (num == 3) return ofColor(255, 100, 0, 100);
        if (num == 4) return ofColor(0, 255, 0, 100);
        if (num == 5) return ofColor(0, 255, 255, 100);
        if (num == 6) return ofColor(255, 0, 255, 100);
        if (num == 7) return ofColor(255, 255, 0, 100);
        if (num == 8) return ofColor(50, 0, 100, 100);
        return ofColor(255);
    }
    //----------------------------------------------------------
};
#endif
