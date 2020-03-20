#include "FormaGeometrica.h"
using namespace std;
FormaGeometrica::FormaGeometrica() {
    qtVertices = 0;
}

FormaGeometrica::FormaGeometrica(FORMA f, float **v) {
    switch (f){
        case TRIANGULO:
            qtVertices = 3;
            vertices[0][0] = v[0][0];
            cout << vertices[0][0] << "OI";
            break;
        case QUADRADO:
            qtVertices = 4;
            break;
        case HEXAGONO:
            qtVertices = 6;
            break;
        default:
            break;
    }
}

void FormaGeometrica::Desenha() {
    cout << "POG";
}

FORMA FormaGeometrica::getForma() {
    return forma;
}
void FormaGeometrica::setForma(FORMA f) {
    forma = f;
}