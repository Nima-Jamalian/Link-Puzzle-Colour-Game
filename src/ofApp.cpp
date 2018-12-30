#include "ofApp.h"
#include "Board.hpp"
#include "Menu.hpp"
//Nima Jamalian
//04/12/2015
//Principles and applications of programming: C++
//Mini-Project final (Windows/Visual Studio)
/*
 How to play:
 Drag to conncet matching colours with pipe, creating a flow.
 Pair all colors, and cover the entire board with pipe to solve each puzzel.
 But watch out, pipes will not cross or overlap.
 If you need to disconnect just click on the circles.
 Good Luck :)
 */
//--------------------------------------------------------------
ofApp::ofApp() :
rectButtonBoard1(150, 230, 500, 145, "Play"),
rectButtonBoard2(150, 420, 500, 145, "How To Play!"),
rectButtonBoard3(150, 610, 500, 145, "Creadit"),
rectButtonBoard4(675, -10, 125, 60, "Back"),
//
easy(150, 150, 500, 145, "Easy"),
medium(150, 350, 500, 145, "Medium"),
hard(150, 550, 500, 145, "Hard"),
//
level1(250, 150, 270, 100, "Level 1"),
level2(250, 280, 270, 100, "Level 2"),
level3(250, 410, 270, 100, "Level 3"),
level4(250, 540, 270, 100, "Level 4"),
level5(250, 670, 270, 100, "Level 5"),
level6(250, 150, 270, 100, "Level 6"),
level7(250, 280, 270, 100, "Level 7"),
level8(250, 410, 270, 100, "Level 8"),
level9(250, 540, 270, 100, "Level 9"),
level10(250, 670, 270, 100, "Level 10"),
level11(250, 150, 270, 100, "Level 11"),
level12(250, 280, 270, 100, "Level 12"),
level13(250, 410, 270, 100, "Level 13"),
level14(250, 540, 270, 100, "Level 14"),
level15(250, 670, 270, 100, "Level 15")
{
    
}
//--------------------------------------------------------------
void ofApp::setup(){
    currentGame = 0;
    font.load(ofToDataPath("ScreenMatrix.ttf"), 100);
    font1.load(ofToDataPath("ScreenMatrix.ttf"), 60);
    font2.load(ofToDataPath("ScreenMatrix.ttf"), 24);
}
//--------------------------------------------------------------
void ofApp::handleStateShowWelcomeScreen() {
    ofSetColor(255,0,0);
    ofFill();
    font.drawString(strConstTitel, ofGetWidth() /5, 150);
    rectButtonBoard1.outputRect();
    rectButtonBoard2.outputRect();
    rectButtonBoard3.outputRect();
}
//--------------------------------------------------------------
void ofApp::update(){
    
}
//--------------------------------------------------------------
void ofApp::draw(){
    switch (currentGame) {
        case 0:
            ofBackground(0);
            // see tab States for handling the states
            handleStateShowWelcomeScreen();
            break;
        case 1:
            game.draw();
            rectButtonBoard4.outputRect();
            break;
        case 2:
            /*
             How to play:
             Drag to conncet matching colours with pipe, creating a flow.
             Pair all colors, and cover the entire board with pipe to solve each puzzel.
             But watch out, pipes will not cross or overlap.
             If you need to disconnect just click on the circles.
             Good Luck :)
             */
            font1.drawString("How to play:", ofGetWidth() / 6, 150);
            font2.drawString("Drag to conncet matching colours with pipe,", ofGetWidth() / 200, 250);
            font2.drawString("creating a flow. Pair all colors, and cover", ofGetWidth() / 200, 300);
            font2.drawString("the entire board with pipe to solve each", ofGetWidth() / 200, 350);
            font2.drawString("puzzel. But watch out, pipes will not cross", ofGetWidth() / 200, 400);
            font2.drawString("or overlap. If you need to disconnect just", ofGetWidth() / 200, 450);
            font2.drawString("click on the circles.", ofGetWidth() / 200, 500);
            rectButtonBoard4.outputRect();
            break;
        case 3:
            font1.drawString("Creadit", 250, 150);
            font2.drawString("Created by Nima Jamalian", ofGetWidth() / 200, 250);
            font2.drawString("In openframewroks(C++)", ofGetWidth() / 200, 300);
            rectButtonBoard4.outputRect();
            break;
        case 4:
            easy.outputRect();
            medium.outputRect();
            hard.outputRect();
            rectButtonBoard4.outputRect();
            break;
        case 5:
            level1.outputRect();
            level2.outputRect();
            level3.outputRect();
            level4.outputRect();
            level5.outputRect();
            rectButtonBoard4.outputRect();
            break;
        case 6:
            level6.outputRect();
            level7.outputRect();
            level8.outputRect();
            level9.outputRect();
            level10.outputRect();
            rectButtonBoard4.outputRect();
            break;
        case 7:
            level11.outputRect();
            level12.outputRect();
            level13.outputRect();
            level14.outputRect();
            level15.outputRect();
            rectButtonBoard4.outputRect();
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    mousePressedStateWelcomeScreen();
}
//--------------------------------------------------------------
void ofApp::mousePressedStateWelcomeScreen() {
    // Mouse pressed in state Welcome Screen / Main Screen.
    // Evaluate three main buttons.
    if (rectButtonBoard1.overRect() && currentGame == 0) {
        currentGame = 4;
    }
    else if (rectButtonBoard2.overRect() && currentGame == 0) {
        currentGame = 2;
    }
    else if (rectButtonBoard3.overRect() && currentGame == 0) {
        currentGame = 3;
    }
    else if (rectButtonBoard4.overRect()) {
        
        if (currentGame == 5 || currentGame == 6 || currentGame == 7 || currentGame == 1) {
            currentGame = 4;
        }
        else {
            currentGame = 0;
        }
        //setting levelChosen boolean in Board class false
        game.levelChosen = false;
        //setting won boolean in Board class false
        game.won = false;
    }
    else if (easy.overRect() && currentGame == 4) {
        currentGame = 5;
    }
    else if (medium.overRect() && currentGame == 4)
    {
        currentGame = 6;
    }
    else if (hard.overRect() && currentGame == 4)
    {
        currentGame = 7;
    }
    else if (level1.overRect() && currentGame == 5) {
        currentGame = 1;
        GameData::gameLevel = 1;
    }
    else if (level2.overRect() && currentGame == 5) {
        currentGame = 1;
        GameData::gameLevel = 2;
    }
    else if (level3.overRect() && currentGame == 5) {
        currentGame = 1;
        GameData::gameLevel = 3;
    }
    else if (level4.overRect() && currentGame == 5) {
        currentGame = 1;
        GameData::gameLevel = 4;
    }
    else if (level5.overRect() && currentGame == 5) {
        currentGame = 1;
        GameData::gameLevel = 5;
    }
    else if (level6.overRect() && currentGame == 6) {
        currentGame = 1;
        GameData::gameLevel = 6;
    }
    else if (level7.overRect() && currentGame == 6) {
        currentGame = 1;
        GameData::gameLevel = 7;
    }
    else if (level8.overRect() && currentGame == 6) {
        currentGame = 1;
        GameData::gameLevel = 8;
    }
    else if (level9.overRect() && currentGame == 6) {
        currentGame = 1;
        GameData::gameLevel = 9;
    }
    else if (level10.overRect() && currentGame == 6) {
        currentGame = 1;
        GameData::gameLevel = 10;
    }
    else if (level11.overRect() && currentGame == 7) {
        currentGame = 1;
        GameData::gameLevel = 11;
    }
    else if (level12.overRect() && currentGame == 7) {
        currentGame = 1;
        GameData::gameLevel = 12;
    }
    else if (level13.overRect() && currentGame == 7) {
        currentGame = 1;
        GameData::gameLevel = 13;
    }
    else if (level14.overRect() && currentGame == 7) {
        currentGame = 1;
        GameData::gameLevel = 14;
    }
    else if (level15.overRect() && currentGame == 7) {
        currentGame = 1;
        GameData::gameLevel = 15;
    }
}
//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
