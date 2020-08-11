#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include "InputUtils.h"

using namespace std;

Button::Button(char *s, int w, int h, int start, void (*f)(int))
{
    displayText = s;
    state = false;
    wwidth = w;
    wheigth = h;
    boundaries[0] = start;
    // int a = glutBitmapLength(GLUT_BITMAP_HELVETICA_12, (unsigned char*)displayText);
    // // cout << a;
    // float b = a/(float)w;
    // boundaries[0] = 0.0;
    // boundaries[1] = b;
}
void Button::reDraw() {
    int a = glutBitmapLength(GLUT_BITMAP_HELVETICA_12, (unsigned char*)displayText);
    // cout << a;
    float s = (float)boundaries[0]/(float)wwidth;
    float b = (float)a/(float)wwidth + s;
    boundaries[1] = a+boundaries[0];
    if(state) {
        cout << state << endl;
        glColor3f(1, 0, 0);
    } else {
        glColor3f(190/255.0, 190/255.0, 190/255.0);
    }
    glBegin(GL_QUADS);
        glVertex2f(s, 0.95);
        glVertex2f(b, 0.95);
        glVertex2f(b, 1);
        glVertex2f(s, 1);
    glEnd();
    glColor3f(168/255.0, 168/255.0, 168/255.0);
    glLineWidth(1);
    glBegin(GL_LINES);
        glVertex2f(b, 0.95);
        glVertex2f(b, 1);
    glEnd();
    glColor3f(0, 0, 0);
    glRasterPos2f(s, 0.975);
    char *write = displayText;
    while (*write)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *write++);
}
bool Button::colision(int x, int y) {
    printf("b %d - %d - %d\n", boundaries[0], boundaries[1], x);
    if(x > boundaries[0] && x < boundaries[1] && y < wheigth && y > 0.95*wheigth) {
        state = !state;
        return true;
    }
    else
        return false;
}

TextBar::TextBar() {
    

    value = 0.0;
    splitNum = 0;
}

void TextBar::reText() {
    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
        glVertex2f(0, 0.95);
        glVertex2f(0, 0.90);
        glVertex2f(1, 0.90);
        glVertex2f(0, 0.90);
    glEnd();
    glColor3f(0, 0, 0);
    glLineWidth(2);
    glBegin(GL_LINES);
        glVertex2f(0, 0.90);
        glVertex2f(1, 0.90);
    glEnd();

    glColor3f(0, 0, 0);
    glRasterPos2f(0, 0.925);

    if(texto.length() > 0) {
        glColor3f(0, 0, 0);
        glRasterPos2f(0, 0.925);
        for(int i = 0; i < texto.length(); i++)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, texto.at(i));
        value = stof(texto);
    } else {
        value = 0.0;
    }
}

float TextBar::getValue() {
    return value;
}

void TextBar::split() {
    if(!texto.empty()) {
        string aux;
        int index = 0;
        
        for(int i = 0; i < texto.length(); i++) {
            if(texto.at(i) == ' ') {
                aux = texto.substr(index, i-index);
                index = i;
                sub.push_back(stof(aux));
            }
        }
        aux = texto.substr(index, texto.length()-index);
        sub.push_back(stof(aux));
    }
}

void TextBar::clearSub() {
    if(!sub.empty())
        sub.clear();
}

float TextBar::getAt(int i) {
    if(i < sub.size())
        return sub.at(i);
    return -1.0;
}

void TextBar::putChar(unsigned char key) {
    texto.push_back(key);
}
void TextBar::popChar() {
    if(texto.length() > 0)
        texto.pop_back();
}