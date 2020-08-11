#include <iostream>
<<<<<<< HEAD
#include <string>
#include <vector>

using namespace std;
=======
>>>>>>> cef82a0441bb4e54b2908f6d21394db71e911694

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
<<<<<<< HEAD
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
=======
        void reText(char* s);
    private:
        char* text;
        
>>>>>>> cef82a0441bb4e54b2908f6d21394db71e911694
};