//
//  Menu.cpp
//  Mini_Project_test
//
//  Created by Nima Jamalian on 27/11/2018.
//
#include <stdio.h>
#include "ofApp.h"
#include "Menu.h"

Menu::Menu(int _x, int _y, int _w, int _h, string _text) : x(_x), y(_y), w(_w), h(_h), textRect(_text) {
    textRect = _text;
    font.load(ofToDataPath("ScreenMatrix.ttf"), 40);
    
}

void Menu::outputRect() {
    drawRectText();
    drawRect();
}

void Menu::drawRect() {
    noFillOrLightColorDependingOnMouseOver();
    ofDrawRectangle(x, y, w, h);
    ofSetColor(255);
    ofNoFill();
    ofDrawRectangle(x, y, w, h);
}

void Menu::drawRectText() {
    ofSetColor(255);
    ofFill();
    if (x == 675 && y == -10 && w == 125 & h == 60) {
        font.drawString(textRect, x, y + (h / 2) + 25);
    }
    else if (x == 250) {
        font.drawString(textRect, (x - font.stringWidth(textRect) / 2) + 130, y + (h / 2) + 25);
    }
    else {
        font.drawString(textRect, (x - font.stringWidth(textRect) / 2) + 250 , y + (h / 2) + 25);
    }
    
}
bool Menu::overRect() {
    if (ofGetAppPtr()->mouseX>x && ofGetAppPtr()->mouseX<x + w &&
        ofGetAppPtr()->mouseY>y && ofGetAppPtr()->mouseY<y + h)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Menu::noFillOrLightColorDependingOnMouseOver() {
    if (overRect()) {
        if (x == 150 && y == 230 && w == 500 && h == 145) {
            ofSetColor(0, 255, 0, 90);
            ofFill();
        }
        else if (x == 150 && y == 420 && w == 500 && h == 145) {
            ofSetColor(255, 0, 0, 90);
            ofFill();
        }
        if (x == 150 && y == 230 && w == 500 && h == 145) {
            ofSetColor(0, 255, 0, 90);
            ofFill();
        }
        else if (x == 150 && y == 610 && w == 500 && h == 145) {
            ofSetColor(0, 0, 255, 90);
            ofFill();
        }
        else if (x == 675 && y == -10 && w == 125 && h == 60) {
            ofSetColor(255, 0, 0, 90);
            ofFill();
        }
        else if (x == 150 && y == 150 && w == 500 && h == 145) {
            ofSetColor(0, 255, 0, 170);
            ofFill();
        }
        else if (x == 150 && y == 350 && w == 500 && h == 145) {
            ofSetColor(255, 255, 0, 170);
            ofFill();
        }
        else if (x == 150 && y == 550 && w == 500 && h == 145) {
            ofSetColor(255, 0, 0, 170);
            ofFill();
        }
        else {
            ofSetColor(255, 0, 0, 90);
            ofFill();
        }
    }
    else
    {
        if (x == 150 && y == 150 && w == 500 && h == 145) {
            ofSetColor(0, 255, 0, 90);
            ofFill();
        }
        else if (x == 150 && y == 350 && w == 500 && h == 145) {
            ofSetColor(255, 255, 0, 90);
            ofFill();
        }
        else if (x == 150 && y == 550 && w == 500 && h == 145) {
            ofSetColor(255, 0, 0, 90);
            ofFill();
        }
        else
        {
            ofNoFill();
        }
    }
}

