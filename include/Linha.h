#ifndef Linha_H
#define Linha_H

#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

class Linha {
    public:
        Linha(int qt, float pontos[][3], float prec);
        Linha(int qt, vector<vector<float>> pontos, float prec);
        void Desenha();
    private:
        float pontos[9][3];
        vector<vector<float>> v;
        int qtPontos;
        float aresta;
        float transX, transY;
        float scaleX, scaleY;
        float rotaX, rotaY;
        float reflexX, reflexY;
        int refX, refY;
        bool trans, scale, rota, reflex, cis;
        float centerX, centerY;
        float angle;
        float prec;
        float mCis[4][4];
        float mT[4][4];
};

#endif