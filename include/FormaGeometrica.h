#ifndef FormaGeometrica_h
#define FormaGeometrica_h

#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

// enum FORMA {
//     TRIANGULO,
//     QUADRADO,
//     HEXAGONO
// };

class FormaGeometrica {
    public:
        FormaGeometrica();
        // FormaGeometrica(FORMA f, float **v);
        FormaGeometrica(int qtVertices, float v[][2]);
        FormaGeometrica(int qtVertices, float x, float y);
        FormaGeometrica(int qtVertices);
        void Desenha();
        int getQtVertices();
        void setVertices(float v[][2]);
        void setTranslada(float x, float y);
        void transladaDraw();
        void setScale(float x, float y);
        void setScale(float x, float y, float cx, float cy);
        void scaleDraw();
        void setRota(float angle, float x, float y);
        void setRota(float angle, float x, float y, float cx, float cy);
        void rotaDraw();
        void setReflex(float xouy);
        void setReflex(float xouy, float x, float y);
        void reflexDraw();
        void setCis(float x, float y);
        void setCis(float x, float y, float cx, float cy);
        void cisDraw();
        bool getTransladaActive();
        bool getScaleActive();
        bool getRotaActive();
        bool getReflexActive();
        bool getCisActive();
        // FORMA getForma();
        // void setForma(FORMA f);
    private:
        // FORMA forma;
        float vertices[6][2];
        vector<vector<float>> v;
        int qtVertices;
        float aresta;
        float transX, transY;
        float scaleX, scaleY;
        float rotaX, rotaY;
        int ref;
        bool trans, scale, rota, reflex, cis;
        float centerX, centerY;
        float angle;
        float mCis[4][4];
};

class Quadrado : public FormaGeometrica {
    public:
        Quadrado(float v[][2]);
        Quadrado(float x, float y, float aresta);
};

class Triangulo : public FormaGeometrica {
    public:
        Triangulo(float v[][2]);
        Triangulo(float x, float y, float aresta);
};

class Hexagono : public FormaGeometrica {
    public:
        Hexagono(float v[][2]);
        Hexagono(float x, float y, float aresta);
};
#endif