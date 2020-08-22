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
        int qtPontos;
        float prec;
};

#endif