#pragma once
#include "ofMain.h"
#include "Board.hpp"
#include "Menu.hpp"
#include "GameData.hpp"
using std::vector;

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    //------------------------------------------------
    ofApp();
    //------------------------------------------------
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    //----------------------Game-----------------------
    Board game;
    //----------------------Menu-----------------------
    string strConstTitel = " Link! ";
    int currentGame;
    int textXPos;
    //Menu Buttons
    Menu rectButtonBoard1;
    Menu rectButtonBoard2;
    Menu rectButtonBoard3;
    Menu rectButtonBoard4;
    //Level Difficulty
    Menu easy;
    Menu medium;
    Menu hard;
    //Easy Levels
    Menu level1;
    Menu level2;
    Menu level3;
    Menu level4;
    Menu level5;
    //Medium Levels
    Menu level6;
    Menu level7;
    Menu level8;
    Menu level9;
    Menu level10;
    //Hard Levels
    Menu level11;
    Menu level12;
    Menu level13;
    Menu level14;
    Menu level15;
    //fonts
    ofTrueTypeFont font;
    ofTrueTypeFont font1;
    ofTrueTypeFont font2;
    //menu functions
    void handleStateShowWelcomeScreen();
    void mousePressedStateWelcomeScreen();
};
