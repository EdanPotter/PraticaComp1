#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include "InputUtils.h"

using namespace std;

Principal::Principal(int winh, int winw) {
    Button triButton = Button("Triangulo", winw, winh, 0);
    Button quaButton = Button("Quadrado", winw, winh, 55);
    Button hexaButton = Button("Hexagono", winw, winh, 118);
    Button apagaButton = Button("Apagar", winw, winh, 180);
    Button transButton = Button("Translacao", winw, winh, 225);
    Button scaleButton = Button("Escala", winw, winh, 290);
    Button rotButton = Button("Rotacao", winw, winh, 330);
    Button reflexButton = Button("Reflexao", winw, winh, 380);
    Button cisButton = Button("Cisalhamento", winw, winh, 430);
    
    buttons.push_back(triButton);
    buttons.push_back(quaButton);
    buttons.push_back(hexaButton);
    buttons.push_back(apagaButton);
    buttons.push_back(transButton);
    buttons.push_back(scaleButton);
    buttons.push_back(rotButton);
    buttons.push_back(reflexButton);
    buttons.push_back(cisButton);

    barra = TextBar();

    altura = winh;
    largura = winw;
}

void Principal::reDraw() {
    // Barra
    glColor3f(190 / 255.0, 190 / 255.0, 190 / 255.0);
    glBegin(GL_QUADS);
        glVertex2f(0, 0.95);
        glVertex2f(1, 0.95);
        glVertex2f(1, 1);
        glVertex2f(0, 1);
    glEnd();
    // Botoes
    for(int i=0; i<buttons.size(); i++)
        buttons.at(i).reDraw();
    // Texto
    barra.reText();
    glColor3f(1, 0, 0);
    //Eixos
    glBegin(GL_LINES); //x
        glVertex2f(0.05, 0.85);
        glVertex2f(0.95, 0.85);
    glEnd();
    glBegin(GL_LINES); //y
        glVertex2f(0.05, 0.85);
        glVertex2f(0.05, 0.05);
    glEnd();
    //Marcações
    glBegin(GL_LINES);
        for(float j=0.1; j<0.95; j+=0.05) {
            glVertex2f(j, 0.86);
            glVertex2f(j, 0.84);
        }
    glEnd();
    glBegin(GL_LINES);
        for(float j=0.1; j<0.85; j+=0.05) {
            glVertex2f(0.04, j);
            glVertex2f(0.06, j);
        }
    glEnd();
    int k = 0;
    for(float j=0.1; j<0.95; j+=0.05) {
        glRasterPos2f(j-0.05, 0.88);
        int aux = k;
        int aux2 = k;
        if(aux == 0)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, '0' + aux);
        while(aux2 > 0) {
            aux2 = aux/10;
            aux = aux%10;
            if(aux2)
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, '0' + aux2);
            else
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, '0' + aux);
        }
        k++;
    }
    k = 0;
    for(float j=0.80; j>0.05; j-=0.05) {
        glRasterPos2f(0.01, j+0.05);
        int aux = k;
        int aux2 = k;
        if(aux == 0)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, '0' + aux);
        while(aux2 > 0) {
            aux2 = aux/10;
            aux = aux%10;
            if(aux2)
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, '0' + aux2);
            else
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, '0' + aux);
        }
        k++;
    }
}

int Principal::getActiveButton() {
    for(int i=0; i<buttons.size(); i++) {
        if(buttons.at(i).getState())
            return i;
    }
    return -1;
}
void Principal::clicked(int x, int y) {
    for(int i=0; i<buttons.size(); i++) {
        buttons.at(i).colision(x, y);
    }
}
void Principal::typed(unsigned char key) {
    if (key == 27)
    	exit(0);
    else if(key == 8) {
        barra.popChar();
    } else if(key == 13) {
        barra.split();
        // getActiveButton();
        // Pega o selecionado e desenha // limpa sub //
        // cout << barText.getAt(0) << "/" << barText.getAt(2) << "/" << endl;
        barra.clear();
    } else {
        barra.putChar(key);
    }
}
Button::Button(char *s, int w, int h, int start) {
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
        // cout << state << endl;
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

bool Button::getState() {
    return state;
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

void TextBar::clear() {
    if(!sub.empty())
        sub.clear();
    if(!texto.empty())
        texto.clear();
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