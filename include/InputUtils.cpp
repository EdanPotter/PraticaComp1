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
}
void TextBar::reText(char* s) {
    text = s;
    glColor3f(0, 0, 0);
    glRasterPos2f(0, 0.925);
    while (*text)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *text++);
}