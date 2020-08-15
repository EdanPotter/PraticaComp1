#ifndef InputUtils_h
#define InputUtils_h

#include <iostream>
#include <string>
#include <vector>
#include "FormaGeometrica.h"

using namespace std;

class Button {
    public:
        Button(const char *s, int w, int h, int start);
        void reDraw();
        void setState(bool s);
        bool getState();
        bool colision(int x, int y);
    private:
        const char* displayText;
        bool state;
        int boundaries[2];
        int wwidth, wheigth, begin;
};

class TextBar {
    public:
        TextBar();
        void reText();
        float getValue();
        void split();
        void clear();
        float getAt(int i);
        void putChar(unsigned char key);
        void popChar();
        void addTexto(string t);
        int getSubCount();
    private:
        string texto;
        float value;
        vector<float> sub;
        int splitNum;
};

class Principal {
    public:
        Principal(int winh, int winw);
        void reDraw();
        int getActiveButton();
        Button getButtonAt(int i);
        TextBar getBarra();
        void clicked(int x, int y);
        void typed(unsigned char key);
        float* map(float x, float y, bool isAbs);
        float mapX(float x, bool isAbs);
        float mapY(float y, bool isAbs);
        float map(float aresta);
        bool valida(float v[][2], int qt);
    private:
        vector<Button> buttons;
        TextBar barra;
        int largura, altura;
        vector<FormaGeometrica> desenhos;
};

#endif