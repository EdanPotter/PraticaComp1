#include <GL/glut.h>
#include <vector>
#include <stdio.h>
#include "Linha.h"
using namespace std;

Linha::Linha(int qt, float pontos[][3], float prec) {
    this->qtPontos = qt;
    this->prec = prec;
    for(int i = 0; i<qt; i++) {
        this->pontos[i][0] = pontos[i][0];
        this->pontos[i][1] = pontos[i][1];
        this->pontos[i][2] = pontos[i][2];
    }
    this->transX = 0.0;
    this->transY = 0.0;
    this->scaleX = 1.0;
    this->scaleY = 1.0;
    this->reflexX = 1.0;
    this->reflexY = 1.0;
    this->centerX = 0.0;
    this->centerY = 0.0;
    this->angle = 0.0;
    this->trans = false;
    this->scale = false;
    this->rota = false;
    this->reflex = false;
    this->cis = false;

    mCis[0][0] = 1.0;
    mCis[1][0] = 0.0;
    mCis[2][0] = 0.0;
    mCis[3][0] = 0.0;
    mCis[0][1] = 0.0;
    mCis[1][1] = 1.0;
    mCis[2][1] = 0.0;
    mCis[3][1] = 0.0;
    mCis[0][2] = 0.0;
    mCis[1][2] = 0.0;
    mCis[2][2] = 1.0;
    mCis[3][2] = 0.0;
    mCis[0][3] = 0.0;
    mCis[1][3] = 0.0;
    mCis[2][3] = 0.0;
    mCis[3][3] = 1.0;
    mT[0][0] = 1.0;
    mT[1][0] = 0.0;
    mT[2][0] = 0.0;
    mT[3][0] = 0.0;
    mT[0][1] = 0.0;
    mT[1][1] = 1.0;
    mT[2][1] = 0.0;
    mT[3][1] = 0.0;
    mT[0][2] = 0.0;
    mT[1][2] = 0.0;
    mT[2][2] = 1.0;
    mT[3][2] = 0.0;
    mT[0][3] = 0.0;
    mT[1][3] = 0.0;
    mT[2][3] = 0.0;
    mT[3][3] = 1.0;
}
Linha::Linha(int qt, vector<vector<float>> pontos, float prec) {
    this->qtPontos = qt;
    this->prec = prec;
    for(int i = 0; i<qt; i++) {
        this->pontos[i][0] = pontos.at(i).at(0);
        this->pontos[i][1] = pontos.at(i).at(1);
        this->pontos[i][2] = 0.0;
    }
    this->transX = 0.0;
    this->transY = 0.0;
    this->scaleX = 1.0;
    this->scaleY = 1.0;
    this->reflexX = 1.0;
    this->reflexY = 1.0;
    this->centerX = 0.0;
    this->centerY = 0.0;
    this->angle = 0.0;
    this->trans = false;
    this->scale = false;
    this->rota = false;
    this->reflex = false;
    this->cis = false;

    mCis[0][0] = 1.0;
    mCis[1][0] = 0.0;
    mCis[2][0] = 0.0;
    mCis[3][0] = 0.0;
    mCis[0][1] = 0.0;
    mCis[1][1] = 1.0;
    mCis[2][1] = 0.0;
    mCis[3][1] = 0.0;
    mCis[0][2] = 0.0;
    mCis[1][2] = 0.0;
    mCis[2][2] = 1.0;
    mCis[3][2] = 0.0;
    mCis[0][3] = 0.0;
    mCis[1][3] = 0.0;
    mCis[2][3] = 0.0;
    mCis[3][3] = 1.0;
    mT[0][0] = 1.0;
    mT[1][0] = 0.0;
    mT[2][0] = 0.0;
    mT[3][0] = 0.0;
    mT[0][1] = 0.0;
    mT[1][1] = 1.0;
    mT[2][1] = 0.0;
    mT[3][1] = 0.0;
    mT[0][2] = 0.0;
    mT[1][2] = 0.0;
    mT[2][2] = 1.0;
    mT[3][2] = 0.0;
    mT[0][3] = 0.0;
    mT[1][3] = 0.0;
    mT[2][3] = 0.0;
    mT[3][3] = 1.0;
}
void Linha::Desenha() {
    // printf("Ponto: %d\n", qtPontos);
    // system("PAUSE");
    // glColor3f(0.0, 0.0, 1.0);
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, (GLint)qtPontos, &pontos[0][0]);
    // Ativa geração de coordenadas
    glEnable(GL_MAP1_VERTEX_3);
    float delta = 1.0 / prec;
    glLineWidth(1);
    // Traça a curva
    glBegin(GL_LINE_STRIP);
    for (float f = 0; f <= 1.01; f += delta)
        glEvalCoord1f(f);
    glEnd();
}