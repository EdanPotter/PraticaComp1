#include <GL/glut.h>
#include <vector>
#include <stdio.h>
#include "FormaGeometrica.h"
using namespace std;
FormaGeometrica::FormaGeometrica() {
    // qtVertices = 7;
}

FormaGeometrica::FormaGeometrica(int qtVertices, float v[][2]) {
    this->qtVertices = qtVertices;
    for(int i=0; i<qtVertices; i++) {
        vector<float> aux;
        aux.push_back(v[i][0]);
        aux.push_back(v[i][1]);
        this->v.push_back(aux);
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

    mCis[0][0] = 1.0; mCis[1][0] = 0.0;  mCis[2][0] = 0.0;  mCis[3][0] = 0.0;
    mCis[0][1] = 0.0; mCis[1][1] = 1.0;  mCis[2][1] = 0.0;  mCis[3][1] = 0.0;
    mCis[0][2] = 0.0; mCis[1][2] = 0.0;  mCis[2][2] = 1.0;  mCis[3][2] = 0.0;
    mCis[0][3] = 0.0; mCis[1][3] = 0.0;  mCis[2][3] = 0.0;  mCis[3][3] = 1.0;
    mT[0][0] = 1.0; mT[1][0] = 0.0;  mT[2][0] = 0.0;  mT[3][0] = 0.0;
    mT[0][1] = 0.0; mT[1][1] = 1.0;  mT[2][1] = 0.0;  mT[3][1] = 0.0;
    mT[0][2] = 0.0; mT[1][2] = 0.0;  mT[2][2] = 1.0;  mT[3][2] = 0.0;
    mT[0][3] = 0.0; mT[1][3] = 0.0;  mT[2][3] = 0.0;  mT[3][3] = 1.0;
}
FormaGeometrica::FormaGeometrica(int qtVertices, float x, float y) {
    this->qtVertices = qtVertices;
    this->transX = 0.0;
    this->transY = 0.0;
    this->scaleX = 1.0;
    this->scaleY = 1.0;
    this->reflexX = 1.0;
    this->reflexY = 1.0;
    this->centerX = x;
    this->centerY = y;
    this->angle = 0.0;
    this->trans = false;
    this->scale = false;
    this->rota = false;
    this->reflex = false;
    this->cis = false;
    mCis[0][0] = 1.0; mCis[1][0] = 0.0;  mCis[2][0] = 0.0;  mCis[3][0] = 0.0;
    mCis[0][1] = 0.0; mCis[1][1] = 1.0;  mCis[2][1] = 0.0;  mCis[3][1] = 0.0;
    mCis[0][2] = 0.0; mCis[1][2] = 0.0;  mCis[2][2] = 1.0;  mCis[3][2] = 0.0;
    mCis[0][3] = 0.0; mCis[1][3] = 0.0;  mCis[2][3] = 0.0;  mCis[3][3] = 1.0;
    mT[0][0] = 1.0; mT[1][0] = 0.0;  mT[2][0] = 0.0;  mT[3][0] = 0.0;
    mT[0][1] = 0.0; mT[1][1] = 1.0;  mT[2][1] = 0.0;  mT[3][1] = 0.0;
    mT[0][2] = 0.0; mT[1][2] = 0.0;  mT[2][2] = 1.0;  mT[3][2] = 0.0;
    mT[0][3] = 0.0; mT[1][3] = 0.0;  mT[2][3] = 0.0;  mT[3][3] = 1.0;
}
FormaGeometrica::FormaGeometrica(int qtVertices) {
    this->qtVertices = qtVertices;
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
    mCis[0][0] = 1.0; mCis[1][0] = 0.0;  mCis[2][0] = 0.0;  mCis[3][0] = 0.0;
    mCis[0][1] = 0.0; mCis[1][1] = 1.0;  mCis[2][1] = 0.0;  mCis[3][1] = 0.0;
    mCis[0][2] = 0.0; mCis[1][2] = 0.0;  mCis[2][2] = 1.0;  mCis[3][2] = 0.0;
    mCis[0][3] = 0.0; mCis[1][3] = 0.0;  mCis[2][3] = 0.0;  mCis[3][3] = 1.0;
    mT[0][0] = 1.0; mT[1][0] = 0.0;  mT[2][0] = 0.0;  mT[3][0] = 0.0;
    mT[0][1] = 0.0; mT[1][1] = 1.0;  mT[2][1] = 0.0;  mT[3][1] = 0.0;
    mT[0][2] = 0.0; mT[1][2] = 0.0;  mT[2][2] = 1.0;  mT[3][2] = 0.0;
    mT[0][3] = 0.0; mT[1][3] = 0.0;  mT[2][3] = 0.0;  mT[3][3] = 1.0;
}
void FormaGeometrica::Desenha() {
    // printf("aaa %d\n", this->v.size());
    // printf("qt: %d", this->qtVertices);
    // float m[4][4];
    // glGetFloatv(GL_MODELVIEW_MATRIX, &m[0][0]);
    // printf("moidel %f\n", m[0][0]);
    glPushMatrix();
    if(trans) {
        glTranslatef(transX, transY, 0);
        trans = false;
        // centerX += transX;
        // centerY += transY;
        // Desenha();
    }
    if(reflex) {
        glTranslatef(centerX, centerY, 0);
        // if (refX == 0)
        //     glScalef(reflexX, 1, 0);
        // else
        glScalef(reflexX, reflexY, 0);
        glScalef(1, 1, 0);
        glTranslatef(-centerX, -centerY, 0);
        reflex = false;
    }
    if(cis) {
        glTranslatef(centerX, centerY, 0);
        glMultMatrixf(&mCis[0][0]);
        glTranslatef(-centerX, -centerY, 0);
        cis = false;
    }
    if(scale) {
        glTranslatef(centerX, centerY, 0);
        glScalef(scaleX, scaleY, 0);
        glScalef(1, 1, 0);
        glTranslatef(-centerX, -centerY, 0);
        scale = false;
    }
    if(rota) {
        glTranslatef(centerX, centerY, 0);
        glRotatef(angle, 0, 0, 1);
        // glRotatef(-angle, 0, 0, 1);
        // glScalef(1, 1, 0);
        glTranslatef(-(centerX), -(centerY), 0);
        rota = false;
    }
    glMultMatrixf(&mT[0][0]);
    glBegin(GL_POLYGON);
        for(int i=0; i<qtVertices; i++) {
            glVertex2f(v.at(i).at(0), v.at(i).at(1));
        }
    glEnd();
    glGetFloatv(GL_MODELVIEW_MATRIX, &mT[0][0]);
    // glScalef(1, 1, 0);
    glPopMatrix();
}
int FormaGeometrica::getQtVertices(){
    return qtVertices;
}
void FormaGeometrica::setVertices(float v[][2]) {
    // this->qtVertices = qtVertices;
    for(int i=0; i<qtVertices; i++) {
        vector<float> aux;
        aux.push_back(v[i][0]);
        aux.push_back(v[i][1]);
        this->v.push_back(aux);
    }
}
void FormaGeometrica::setTranslada(float x, float y) {
    this->transX = x;
    this->transY = y;
    // centerX += transX;
    // centerY += transY;
    trans = true;
}
void FormaGeometrica::transladaDraw() {
    glPushMatrix();
    glTranslatef(transX, transY, 0);
    Desenha();
    glPopMatrix();
}
bool FormaGeometrica::getTransladaActive() {
    return trans;
}
void FormaGeometrica::setScale(float x, float y) {
    scale = true;
    scaleX = x;
    scaleY = y;
    // transX = -x;
    // transY = -y;
}
void FormaGeometrica::setScale(float x, float y, float cx, float cy) {
    scale = true;
    scaleX = x;
    scaleY = y;
    centerX = cx;
    centerY = cy;
}
void FormaGeometrica::scaleDraw() {
    glPushMatrix();
    glTranslatef(centerX, centerY, 0);
    glScalef(scaleX, scaleY, 0);
    glScalef(1, 1, 0);
    glTranslatef(-centerX, -centerY, 0);
    Desenha();
    glPopMatrix();
}
bool FormaGeometrica::getScaleActive() {
    return scale;
}

void FormaGeometrica::setRota(float angle) {
    rota = true;
    this->angle = angle;
    // centerX += transX;
    // centerY += transY;
}
void FormaGeometrica::setRota(float angle, float cx, float cy) {
    rota = true;
    this->angle = angle;
    // rotaX = x;
    // rotaY = y;
    centerX = cx;
    centerY = cy;
}
void FormaGeometrica::rotaDraw() {
    glPushMatrix();
    glTranslatef(centerX, centerY, 0);
    glRotatef(angle, 0, 0, 1);
    // glScalef(1, 1, 0);
    glTranslatef(-centerX, -centerY, 0);
    Desenha();
    glPopMatrix();
}
bool FormaGeometrica::getRotaActive() {
    return rota;
}

void FormaGeometrica::setReflex(float rx, float ry) {
    refX = rx;
    refY = ry;
    if (refX == 1)
        reflexX = -1;
    if (refY == 1)
        reflexY = -1;

    reflex = true;
}
void FormaGeometrica::setReflex(float rx, float ry, float x, float y) {
    refX = rx;
    refY = ry;
    if(refX == 1)
        reflexX = -1;
    if(refY == 1)
        reflexY = -1;
    reflex = true;
    centerX = x;
    centerY = y;
}
void FormaGeometrica::reflexDraw() {
    glPushMatrix();
    glTranslatef(centerX, centerY, 0);
    // if(ref == 0)
    //     glScalef(-1, 1, 0);
    // else
    //     glScalef(1, -1, 0);
    glScalef(reflexX, reflexY, 0);
    glTranslatef(-centerX, -centerY, 0);
    Desenha();
    glPopMatrix();
}
bool FormaGeometrica::getReflexActive() {
    return reflex;
}
void FormaGeometrica::setCis(float x, float y) {
    cis = true;
    mCis[0][1] = y;
    mCis[1][0] = x;
}
void FormaGeometrica::setCis(float x, float y, float cx, float cy) {
    cis = true;
    mCis[0][1] = y;
    mCis[1][0] = x;
    centerX = cx;
    centerY = cy;
}
void FormaGeometrica::cisDraw() {
    glPushMatrix();
    glTranslatef(centerX, centerY, 0);
    glMultMatrixf(&mCis[0][0]);
    glTranslatef(-centerX, -centerY, 0);
    Desenha();
    glPopMatrix();
}
bool FormaGeometrica::getCisActive() {
    return cis;
}
// Vertices
Quadrado::Quadrado(float v[][2]):FormaGeometrica(4) {
    // printf("OI %f\n", v[0][0]);
    setVertices(v);
}
// Centro + aresta
Quadrado::Quadrado(float x, float y, float aresta):FormaGeometrica(4, x, y) {
    float aux[4][2];
    aux[0][0] = x-aresta/2;
    aux[0][1] = y-aresta/2;
    aux[1][0] = x-aresta/2;
    aux[1][1] = y+aresta/2;
    aux[2][0] = x+aresta/2;
    aux[2][1] = y+aresta/2;
    aux[3][0] = x+aresta/2;
    aux[3][1] = y-aresta/2;
    setVertices(aux);
}

Triangulo::Triangulo(float v[][2]):FormaGeometrica(3) {
    setVertices(v);
}
Triangulo::Triangulo(float x, float y, float aresta):FormaGeometrica(3, x, y) {
    float aux[3][2];
    aux[0][0] = x-aresta/2;
    aux[0][1] = y-aresta*0.288675;
    aux[1][0] = x;
    aux[1][1] = y+aresta*0.57735;
    aux[2][0] = x+aresta/2;
    aux[2][1] = y-aresta*0.288675;
    setVertices(aux);
}

Hexagono::Hexagono(float v[][2]):FormaGeometrica(6) {
    setVertices(v);
}
Hexagono::Hexagono(float x, float y, float aresta):FormaGeometrica(6, x, y) {
    float aux[6][2];
    aux[0][0] = x-aresta/2;
    aux[0][1] = y-aresta*0.86602;
    aux[1][0] = x-aresta;
    aux[1][1] = y;
    aux[2][0] = x-aresta/2;
    aux[2][1] = y+aresta*0.86602;
    aux[3][0] = x+aresta/2;
    aux[3][1] = y+aresta*0.86602;
    aux[4][0] = x+aresta;
    aux[4][1] = y;
    aux[5][0] = x+aresta/2;
    aux[5][1] = y-aresta*0.86602;
    setVertices(aux);
}