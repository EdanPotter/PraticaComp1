#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Button {
    public:
        Button(char *s, int w, int h, int start);
        void reDraw();
        void setState(bool s);
        bool getState();
        bool colision(int x, int y);
    private:
        char* displayText;
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
    private:
        vector<Button> buttons;
        TextBar barra;
        int largura, altura;
        // vector<FormaGeometrica> desenhos;
};