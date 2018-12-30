//
//  Board.cpp
//  Mini_Project_test
//
//  Created by Nima Jamalian on 27/11/2018.
//

#include <stdio.h>
#include "Board.hpp"

Board::Board() : level(){
    font.load("ScreenMatrix.ttf", 50);
    font1.load("ScreenMatrix.ttf", 40);
}

void Board::timerandmoves() {
    if (!won) {
        milliseconds = ofGetElapsedTimeMillis();
        seconds = floor(milliseconds / 1000);
        millisecond10 = floorf(milliseconds / 10);
        millisecond10 = millisecond10 % 100;
        minutes = floor(seconds / 60);
        seconds = seconds % 60;
        if (ofGetMousePressed() == false && selected == true) {
            ++moves;
        }
    }
}

void Board::checkwin() {
    won = true;
    for (int j = 0; j<level.size(); j++) for (int i = 0; i<level[j].size(); i++) {
        bool foundpipe = false;
        if (level[j][i]>0) {
            for (int m = 0; m<level.size(); m++) for (int k = 0; k<level[m].size(); k++)
                if (level[m][k] == -level[j][i]) {
                    foundpipe = true;
                }
            if (foundpipe == false) won = false;
        }
    }
}

void Board::draw() {
    if (!levelChosen) {
        ofResetElapsedTimeCounter();
        millisecond10 = 0;
        seconds = 0;
        minutes = 0;
        moves = 0;
        switch (GameData::gameLevel) {
            case 1:
                level = {
                    {1,0,2,0,3},
                    {0,0,4,0,5},
                    {0,0,0,0,0},
                    {0,2,0,3,0},
                    {0,1,4,5,0}
                };
                grid = 160;
                ec = 80;
                break;
            case 2:
                level = {
                    { 7,0,0,0,0 },
                    { 0,0,0,0,0 },
                    { 0,0,1,0,0 },
                    { 2,1,4,0,7 },
                    { 4,0,0,0,2 }
                };
                grid = 160;
                ec = 80;
                break;
            case 3:
                level = {
                    { 0,1,2,3,0 },
                    { 0,0,0,4,0 },
                    { 0,0,4,0,0 },
                    { 1,0,0,5,0 },
                    { 2,0,5,3,0 }
                };
                grid = 160;
                ec = 80;
                break;
            case 4:
                level = {
                    { 0,0,0,0,0 },
                    { 1,4,0,4,0 },
                    { 0,0,0,3,0 },
                    { 3,0,0,2,0 },
                    { 2,0,1,0,0 }
                };
                grid = 160;
                ec = 80;
                break;
            case 5:
                level = {
                    { 0,0,0,0,0 },
                    { 1,2,0,2,1 },
                    { 5,0,0,0,0 },
                    { 0,3,0,4,0 },
                    { 5,4,0,3,0 }
                };
                grid = 160;
                ec = 80;
                break;
            case 6:
                level = {
                    { 4,0,6,0,0,0 },
                    { 2,0,0,0,0,0 },
                    { 0,0,0,0,4,6 },
                    { 0,0,0,2,1,7 },
                    { 0,7,0,0,0,0 },
                    { 1,0,0,0,0,0 }
                };
                grid = 134;
                ec = 68;
                break;
            case 7:
                level = {
                    { 0,0,0,1,2,3 },
                    { 0,0,0,4,0,0 },
                    { 1,0,2,0,0,0 },
                    { 5,0,0,4,5,0 },
                    { 0,0,0,0,0,0 },
                    { 3,0,0,0,0,0 }
                };
                grid = 134;
                ec = 68;
                break;
            case 8:
                level = {
                    { 1,0,0,0,0,0 },
                    { 0,6,0,0,5,6 },
                    { 0,5,0,2,0,0 },
                    { 1,0,0,3,4,0 },
                    { 2,3,4,0,0,0 },
                    { 0,0,0,0,0,0 }
                };
                grid = 134;
                ec = 68;
                break;
            case 9:
                level = {
                    { 0,0,0,0,0,0 },
                    { 0,1,0,0,0,2 },
                    { 2,3,0,3,1,5 },
                    { 0,0,0,0,0,0 },
                    { 0,7,0,7,4,0 },
                    { 0,0,0,0,5,4 }
                };
                grid = 134;
                ec = 68;
                break;
            case 10:
                level = {
                    { 1,2,3,0,0,0,5 },
                    { 0,0,4,0,4,3,0 },
                    { 0,0,0,0,0,2,0 },
                    { 0,0,0,0,0,0,0 },
                    { 0,0,6,0,0,0,0 },
                    { 0,0,0,0,0,5,0 },
                    { 0,0,0,0,0,1,6 }
                };
                grid = 115;
                ec = 58;
                break;
            case 11:
                level = {
                    { 0,0,0,0,0,0,0 },
                    { 0,0,0,0,0,0,0 },
                    { 0,0,0,0,0,0,0 },
                    { 0,0,0,4,5,0,0 },
                    { 0,0,5,0,0,0,0 },
                    { 0,0,0,3,4,3,0 },
                    { 0,1,2,0,2,1,0 }
                };
                grid = 115;
                ec = 58;
                break;
            case 12:
                level = {
                    { 0,0,0,0,0,0,0 },
                    { 1,2,0,0,0,0,0 },
                    { 0,0,0,0,6,0,0 },
                    { 0,4,5,6,0,0,1 },
                    { 0,0,0,0,0,7,3 },
                    { 0,2,4,5,7,0,0 },
                    { 3,0,0,0,0,0,0 }
                };
                grid = 115;
                ec = 58;
                break;
            case 13:
                level = {
                    { 0, 0, 0, 1, 0, 0, 0, 2 },
                    { 0, 8, 0, 0, 2, 4, 5, 0 },
                    { 0, 0, 6, 0, 0, 0, 0, 0 },
                    { 0, 0, 0, 0, 0, 1, 4, 0 },
                    { 0, 0, 7, 0, 0, 8, 6, 0 },
                    { 5, 0, 0, 0, 0, 7, 0, 0 },
                    { 0, 0, 0, 0, 0, 0, 0, 0 },
                    { 0, 0, 0, 0, 0, 0, 0, 0 }
                };
                grid = 100;
                ec = 50;
                break;
            case 14:
                level = {
                    { 1, 0, 0, 0, 0, 0, 0, 3 },
                    { 0, 0, 0, 0, 0, 0, 0, 4 },
                    { 0, 0, 0, 0, 0, 0, 0, 0 },
                    { 0, 0, 1, 0, 0, 0, 0, 0 },
                    { 0, 0, 0, 4, 2, 0, 0, 0 },
                    { 0, 0, 0, 0, 0, 0, 0, 0 },
                    { 0, 0, 3, 0, 0, 0, 0, 0 },
                    { 2, 0, 0, 0, 0, 0, 0, 0 }
                };
                grid = 100;
                ec = 50;
                break;
            case 15:
                level = {
                    { 0, 1, 0, 0, 0, 0, 0, 2 },
                    { 0, 3, 0, 0, 0, 0, 4, 0 },
                    { 0, 0, 0, 0, 5, 0, 6, 0 },
                    { 0, 0, 0, 6, 0, 0, 2, 0 },
                    { 0, 0, 0, 1, 7, 0, 0, 0 },
                    { 0, 3, 4, 0, 0, 0, 7, 0 },
                    { 0, 0, 0, 0, 5, 0, 0, 0 },
                    { 8, 0, 0, 0, 0, 0, 0, 8 }
                };
                grid = 100;
                ec = 50;
                break;
        }
        levelChosen = !levelChosen;
    }
    timerandmoves();
    //std::cout <<"Level = " <<  GameData::gameLevel<< std::endl;
    //std::cout << "Level = " << level[0][0] << std::endl;
    ofBackground(0);//background colour
    for (int j = 0; j < level.size(); j++) {//loop through each row
        for (int i = 0; i < level[j].size(); i++) {//loop through each column
            int x = i*grid;
            int    y = j*grid+50;
            //strock
            ofSetColor(255);
            ofNoFill();
            //draw the board
            ofDrawRectangle(x, y, grid, grid);
            //setting colour for ellipses
            ofSetColor(numToColor(level[j][i]));
            ofFill();
            //darw ellipses
            if (level[j][i]>0) {
                ofDrawEllipse(x + ec, y + ec, grid, grid);
                //------------------------------------------------------
                //shade for ellipse
                ofSetColor(numToColorPipe(level[j][i]));
                ofFill();
                ofDrawRectangle(x + grid / 60, y + grid / 60, grid, grid);
                //------------------------------------------------------
            }
            //draw the pipes
            if (level[j][i] < 0) {
                bool right = false;
                bool left = false;
                bool above = false;
                bool below = false;
                if (i < level.size() - 1 && abs(level[j][i]) == abs(level[j][i + 1])) {
                    right = true;
                }
                if (i > 0 && abs(level[j][i]) == abs(level[j][i - 1])) {
                    left = true;
                }
                if (j > 0 && abs(level[j][i]) == abs(level[j - 1][i])) {
                    above = true;
                }
                if (j < level.size() - 1 && abs(level[j][i]) == abs(level[j + 1][i])) {
                    below = true;
                }
                ofSetColor(numToColor(-level[j][i]));
                ofFill();
                ofDrawRectangle(x + grid / 4, y + grid / 4, grid / 2, grid / 2);
                
                if (above && below) {
                    ofDrawRectangle(x + grid / 4, y, grid / 2, grid);
                }
                if (left && right) {
                    ofDrawRectangle(x, y + grid / 4, grid, grid / 2);
                }
                if (above && left) {
                    ofDrawRectangle(x, y + grid / 4, grid / 2, grid / 2);
                    ofDrawRectangle(x + grid / 4, y, grid / 2, grid / 2);
                }
                if (above && right) {
                    ofDrawRectangle(x + grid / 2, y + grid / 4, grid / 2, grid / 2);
                    ofDrawRectangle(x + grid / 4, y, grid / 2, grid / 2);
                }
                if (below && left) {
                    ofDrawRectangle(x, y + grid / 4, grid / 2, grid / 2);
                    ofDrawRectangle(x + grid / 4, y + grid / 2, grid / 2, grid / 2);
                }
                
                if (below && right) {
                    ofDrawRectangle(x + grid / 2, y + grid / 4, grid / 2, grid / 2);
                    ofDrawRectangle(x + grid / 4, y + grid / 2, grid / 2, grid / 2);
                }
                //-------------------------------------------------------------
                ofSetColor(numToColorPipe(-level[j][i]));
                ofFill();
                ofDrawRectangle(x + grid / 60, y + grid / 60, grid, grid);
                //-------------------------------------------------------------
            }
        }
    }
    
    if (!won) {
        if (ofGetMousePressed() && !selected) {//if you click
            startx = int(ofGetAppPtr()->mouseX / grid);
            starty = int(((ofGetAppPtr()->mouseY )-50)/ grid);
            currentx = startx;
            currenty = starty;
            //std::cout << "startX = " << startx << " , " << "startY = " << starty << std::endl;
            std::cout << "X = " << ofGetAppPtr()->mouseX << " , " << "Y = " << ofGetAppPtr()->mouseY << std::endl;
            //select
            if (ofGetAppPtr()->mouseY > 50) selected = true;
            //if (level[starty][startx]) selected = true;
        }
        if (ofGetMousePressed() == false && selected == true) {
            selected = false;
            int endx = -1, endy = -1;
            for (auto j = 0; j<level.size(); j++) {
                for (auto i = 0; i<level[j].size(); i++) {
                    if (!(i == startx && j == starty) && level[j][i] == level[starty][startx]) {//connect the pipes
                        endx = i; endy = j;
                    }
                }
            }
            if ((currentx == endx && currenty == endy + 1) ||
                (currentx == endx && currenty == endy - 1) ||
                (currentx == endx + 1 && currenty == endy) ||
                (currentx == endx - 1 && currenty == endy)) {
                checkwin();
                
            }
            else {
                for (auto j = 0; j < level.size(); j++) {//check if it's the same colour
                    for (auto i = 0; i < level[j].size(); i++) {
                        if (level[j][i] == -level[starty][startx]) {
                            level[j][i] = 0;
                        }
                    }
                }
            }
        }
        
        if (ofGetMousePressed() == true && selected == true) {//for drawing the pipes
            int x = int(ofGetAppPtr()->mouseX / grid);//mouse position
            int    y = int(((ofGetAppPtr()->mouseY) - 50)/ grid);//mouse position
            if (x >= 0 && y >= 0 && y < level.size()&&x < level[0].size() && level[y][x] == 0) { //if it's on board fill it
                //make sure it's connected to last position
                if ((x == currentx + 1 && y == currenty) ||
                    (x == currentx - 1 && y == currenty) ||
                    (x == currentx && y == currenty + 1) ||
                    (x == currentx && y == currenty - 1)) {
                    level[y][x] = -level[starty][startx];
                    currentx = x; currenty = y;
                }
            }
        }
    }
    if(won){
        ofSetColor(0,255,0,200);
        ofDrawRectangle(0,50, 800, 800);
        ofSetColor(255);
        ofFill();
        font.drawString("Level complete!", ofGetWidth()/2 - 275, ofGetHeight()/2);
    }
    //timer
    ofSetColor(255);
    ofFill();
    string temp = "Time:" + to_string(minutes) + ":" + to_string(seconds) + "." + to_string(millisecond10) ;
    font1.drawString(temp, 2, 45);
    //moves
    string temp1 = "Moves:" + to_string(moves);
    font1.drawString(temp1, 370, 45);
}

