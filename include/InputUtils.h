#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Button {
    public:
        Button(char *s, int w, int h, int start, void (*f)(int));
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
        void clearSub();
        float getAt(int i);
        void putChar(unsigned char key);
        void popChar();
    private:
        string texto;
        float value;
        vector<float> sub;
        int splitNum;
};