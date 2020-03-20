#include <iostream>
#include <stdlib.h>

enum FORMA {
    TRIANGULO,
    QUADRADO,
    HEXAGONO
};

class FormaGeometrica {
    public:
        FormaGeometrica();
        FormaGeometrica(FORMA f, float **v);
        void Desenha();
        FORMA getForma();
        void setForma(FORMA f);
    private:
        FORMA forma;
        float vertices[6][2];
        int qtVertices;
};
