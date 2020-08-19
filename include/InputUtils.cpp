#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include "InputUtils.h"
#include "FormaGeometrica.h"
#include "Linha.h"
using namespace std;
/*
Constrói tela principal e botões
*/
Principal::Principal(int winh, int winw) {
    Button triButton = Button("Triangulo", winw, winh, 0);
    Button quaButton = Button("Quadrado", winw, winh, 55);
    Button hexaButton = Button("Hexagono", winw, winh, 118);
    Button apagaButton = Button("Apagar", winw, winh, 180);
    Button transButton = Button("Translacao", winw, winh, 225);
    Button scaleButton = Button("Escala", winw, winh, 290);
    Button rotButton = Button("Rotacao", winw, winh, 330);
    Button reflexButton = Button("Reflexao", winw, winh, 380);
    Button cisButton = Button("Cisalhamento", winw, winh, 430);
    Button linhaButton = Button("Linha", winw, winh, 510);

    buttons.push_back(triButton);
    buttons.push_back(quaButton);
    buttons.push_back(hexaButton);
    buttons.push_back(apagaButton);
    buttons.push_back(transButton);
    buttons.push_back(scaleButton);
    buttons.push_back(rotButton);
    buttons.push_back(reflexButton);
    buttons.push_back(cisButton);
    buttons.push_back(linhaButton);

    barra = TextBar();

    altura = winh;
    largura = winw;
    // float *aux;
    // aux = map(1, 1, true);
    // Quadrado q = Quadrado(aux[0], aux[1], 0.05);
    // desenhos.push_back(q);
    // printf("Desenhos v: %d\n", q.getQtVertices());
}
/*
Redesenha elementos
*/
void Principal::reDraw() {
    // Desenha formas
    glColor3f(0.0, 0.0, 1.0);
    for(int i=0; i<desenhos.size(); i++) {
        desenhos.at(i).Desenha();
    }

    for(int i=0; i<linhas.size(); i++) {
        glColor3f(corRGB[0], corRGB[1], corRGB[2]);
        linhas.at(i).Desenha();
        corRGB[0]+=0.1;
        if(corRGB[0] > 1.0)
            corRGB[0] = 0.0;
        corRGB[1]+=0.2;
        if(corRGB[1] > 1.0)
            corRGB[1] = 0.0;
        corRGB[2]+=0.3;
        if(corRGB[2] > 1.0)
            corRGB[2] = 0.0;
    }
    corRGB[0] = 0.0;
    corRGB[1] = 0.0;
    corRGB[2] = 0.0;
    // float pontos[5][3] = {{mapX(0, true), mapY(10, true), 0.0},
    //                       {mapX(2, true), mapY(2, true), 0.0},
    //                       {mapX(6, true), mapY(6, true), 0.0},
    //                       {mapX(8, true), mapY(2, true), 0.0},
    //                       {mapX(9, true), mapY(9, true), 0.0}};

    // glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 5, &pontos[0][0]);
    // // Ativa geração de coordenadas
    // glEnable(GL_MAP1_VERTEX_3);
    // float delta = 1.0 / 10.0;
    // // Traça a curva
    // glBegin(GL_LINE_STRIP);
    // for (float f = 0; f <= 1.01; f += delta)
    //     glEvalCoord1f(f);
    // glEnd();

    // Barra
    glColor3f(190 / 255.0, 190 / 255.0, 190 / 255.0);
    glBegin(GL_QUADS);
        glVertex2f(0, 0.05);
        glVertex2f(1, 0.05);
        glVertex2f(1, 0);
        glVertex2f(0, 0);
    glEnd();
    // Botoes
    for(int i=0; i<buttons.size(); i++)
        buttons.at(i).reDraw();
    // Texto
    barra.reText();
    glColor3f(1, 0, 0);
    //Eixos
    glBegin(GL_LINES); //x
        glVertex2f(0.05, 0.55);
        glVertex2f(0.95, 0.55);
    glEnd();
    glBegin(GL_LINES); //y
        glVertex2f(0.5, 0.15);
        glVertex2f(0.5, 0.95);
    glEnd();
    //Marcações
    glBegin(GL_LINES);
        for(float j=0.05; j<0.95; j+=0.025) {
            glVertex2f(j, 0.54);
            glVertex2f(j, 0.56);
        }
    glEnd();
    glBegin(GL_LINES);
        for(float j=0.15; j<0.95; j+=0.025) {
            glVertex2f(0.49, j);
            glVertex2f(0.51, j);
        }
    glEnd();
    // Desenha números
    int k = -18;
    for(float j=0.05; j<0.95; j+=0.025) {
        glRasterPos2f(j, 0.53);
        int aux = k;
        int aux2 = k;
        if(aux == 0)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, '0' + aux);
        while(aux2 > 0) {
            aux2 = aux/10;
            aux = aux%10;
            if(aux2)
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, '0' + aux2);
            else
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, '0' + aux);
        }
        k++;
    }
    k = 1;
    for(float j=0.55; j<0.925; j+=0.025) {
        glRasterPos2f(0.46, j+0.025);
        int aux = k;
        int aux2 = k;
        if(aux == 0)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, '0' + aux);
        while(aux2 > 0) {
            aux2 = aux/10;
            aux = aux%10;
            if(aux2)
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, '0' + aux2);
            else
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, '0' + aux);
        }
        k++;
    }
    // // Desenha formas
    // glColor3f(0.0, 0.0, 1.0);
    // for(int i=0; i<desenhos.size(); i++) {
    //     desenhos.at(i).Desenha();
    // }
}
// Retorna o indice do primeiro botao ativo
int Principal::getActiveButton() {
    for(int i=0; i<buttons.size(); i++) {
        if(buttons.at(i).getState())
            return i;
    }
    return -1;
}
// Callback de clique
void Principal::clicked(int x, int y) {
    for(int i=0; i<buttons.size(); i++) {
        if(buttons.at(i).colision(x, y)) {
            switch (i) {
                case 0:
                    printf("Triangulo: [x y aresta] ou [x1 y1 x2 y2 x3 y3] ENTER\n");
                    break;
                case 1:
                    printf("Quadrado: [x y aresta] ou [x1 y1 x2 y2 x3 y3 x4 y4] ENTER\n");
                    break;
                case 2:
                    printf("Hexagono: [x y aresta] ou [x1 y1 x2 y2 x3 y3 x4 y4 x5 y5 x6 y6] ENTER\n");
                    break;
                case 3:
                    printf("Apaga: ENTER\n");
                    break;
                case 4:
                    printf("Translacao: [idObjeto x y] ENTER\n");
                    break;
                case 5:
                    printf("Escala: [idObjeto x y] ou [idObjeto x y refX refY] ENTER\n");
                    break;
                case 6:
                    printf("Rotacao: [idObjeto angulo] ou [idObjeto angulo refX refY] ENTER\n");
                    break;
                case 7:
                    printf("Reflexao: [idObjeto emX(1 ou 0) emY(1 ou 0)] ou [idObjeto emX(1 ou 0) emY(1 ou 0) refX refY] ENTER\n");
                    break;
                case 8:
                    printf("Cisalhamento: [idObjeto x y] ou [idObjeto x y refX refY] ENTER\n");
                    break;
                case 9:
                    printf("Linha: [x1 y1 ... xn yn(n <= 9) precisao] ENTER\n");
                default:
                    break;
            }
        }
    }
    float auxx = x, auxy = y;
    auxx = mapX(auxx, false);
    auxy = mapY(auxy, false);
    if(auxy >= -16 && auxy <= 16 && auxx >= -18 && auxx <= 18) {
        string aux = to_string(auxx);
        aux.append(" ");
        aux.append(to_string(auxy));
        barra.addTexto(aux);
    }
}
// Callback de teclado
void Principal::typed(unsigned char key) {
    if (key == 27)
    	exit(0);
    else if(key == 8) {
        barra.popChar();
    } else if(key == 13) {
        barra.split();
        int active = getActiveButton();
        if(active == 0) {
            if(barra.getSubCount() == 3) {
                Triangulo t = Triangulo(mapX(barra.getAt(0), true), mapY(barra.getAt(1), true), map(barra.getAt(2)));
                desenhos.push_back(t);
            } else if(barra.getSubCount() == 6) {
                float tv[3][2] = {{mapX(barra.getAt(0), true), mapY(barra.getAt(1), true)},
                                  {mapX(barra.getAt(2), true), mapY(barra.getAt(3), true)},
                                  {mapX(barra.getAt(4), true), mapY(barra.getAt(5), true)}};
                if(valida(tv, 3)) {
                    Triangulo t = Triangulo(tv);
                    desenhos.push_back(t);
                }
            }
        } else if(active == 1) {
            if(barra.getSubCount() == 3) {
                Quadrado q = Quadrado(mapX(barra.getAt(0), true), mapY(barra.getAt(1), true), map(barra.getAt(2)));
                desenhos.push_back(q);
            } else if(barra.getSubCount() == 8) {
                float qv[4][2] = {{mapX(barra.getAt(0), true), mapY(barra.getAt(1), true)},
                                  {mapX(barra.getAt(2), true), mapY(barra.getAt(3), true)},
                                  {mapX(barra.getAt(4), true), mapY(barra.getAt(5), true)},
                                  {mapX(barra.getAt(6), true), mapY(barra.getAt(7), true)}};
                if(valida(qv, 4)) {
                    Quadrado q = Quadrado(qv);
                    desenhos.push_back(q);
                }
            }
        } else if(active == 2) {
            if(barra.getSubCount() == 3) {
                Hexagono h = Hexagono(mapX(barra.getAt(0), true), mapY(barra.getAt(1), true), map(barra.getAt(2)));
                desenhos.push_back(h);
            } else if(barra.getSubCount() == 12) {
                float hv[6][2] = {{mapX(barra.getAt(0), true), mapY(barra.getAt(1), true)},
                                  {mapX(barra.getAt(2), true), mapY(barra.getAt(3), true)},
                                  {mapX(barra.getAt(4), true), mapY(barra.getAt(5), true)},
                                  {mapX(barra.getAt(6), true), mapY(barra.getAt(7), true)},
                                  {mapX(barra.getAt(8), true), mapY(barra.getAt(9), true)},
                                  {mapX(barra.getAt(10), true), mapY(barra.getAt(11), true)}};
                if(valida(hv, 6)) {
                    Hexagono h = Hexagono(hv);
                    desenhos.push_back(h);
                }
            }
        } else if(active == 3) {
            if(desenhos.size()>0)
                desenhos.clear();
            if(linhas.size()>0)
                linhas.clear();
        } else if(active == 4) {
            if(barra.getSubCount() == 3)
                desenhos.at(barra.getAt(0)).setTranslada(map(barra.getAt(1)), map(barra.getAt(2)));
        } else if(active == 5) {
            if(barra.getSubCount() == 3)
                desenhos.at(barra.getAt(0)).setScale(barra.getAt(1), barra.getAt(2));
            else if(barra.getSubCount() == 5)
                desenhos.at(barra.getAt(0)).setScale(barra.getAt(1), barra.getAt(2), mapX(barra.getAt(3), true), mapY(barra.getAt(4), true));
        } else if(active == 6) {
            if (barra.getSubCount() == 2)
                desenhos.at(barra.getAt(0)).setRota(barra.getAt(1));
            else if (barra.getSubCount() == 4)
                desenhos.at(barra.getAt(0)).setRota(barra.getAt(1), mapX(barra.getAt(2), true), mapY(barra.getAt(3), true));
        } else if(active == 7) {
            if (barra.getSubCount() == 3)
                desenhos.at(barra.getAt(0)).setReflex(barra.getAt(1), barra.getAt(2));
            else if (barra.getSubCount() == 5)
                desenhos.at(barra.getAt(0)).setReflex(barra.getAt(1), barra.getAt(2) , mapX(barra.getAt(3), true), mapY(barra.getAt(4), true));
        } else if(active == 8) {
            if (barra.getSubCount() == 3)
                desenhos.at(barra.getAt(0)).setCis(barra.getAt(1), barra.getAt(2));
            else if (barra.getSubCount() == 5)
                desenhos.at(barra.getAt(0)).setCis(barra.getAt(1), barra.getAt(2), mapX(barra.getAt(3), true), mapY(barra.getAt(4), true));
        } else if(active == 9) {
            int count = (barra.getSubCount()-1)/2;
            if(count >= 3) {
                // float lv[count][3];
                vector<vector<float>> lv;
                
                int i = 0;
                for(; i<count; i++) {
                    vector<float> aux;
                    aux.push_back(mapX(barra.getAt(0+i*2), true));
                    aux.push_back(mapY(barra.getAt(1+i*2), true));
                    lv.push_back(aux);
                    // lv[i][0] = mapX(barra.getAt(0+i*2), true);
                    // lv[i][1] = mapY(barra.getAt(1+i*2), true);
                    // lv[i][2] = 0.0;
                }
                printf("Count: %d\n", count);
                Linha l = Linha(count, lv, (int)barra.getAt(i*2));
                linhas.push_back(l);
                // system("PAUSE");
            }
        }

        barra.clear();
    } else {
        barra.putChar(key);
    }
}
// map converte os sistemas de coordenadas
// isAbs define se entrada é do sistema de coordenadas desenhado
float* Principal::map(float x, float y, bool isAbs) {
    float *aux = new float[2];
    aux[0] = x;
    aux[1] = 1-y;
    if(isAbs) {
        aux[0] = aux[0]*0.9/18+0.05;
        aux[1] = aux[1]*(0.8)/16+0.15;
    } else {
        aux[0] = (aux[0]-0.05)*(18)/(0.95-0.05);
        aux[1] = (aux[1]-0.15)*(16)/(0.95-0.15);
    }
    return aux;
    //return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
float Principal::mapX(float x, bool isAbs) {
    float aux;
    if(!isAbs) {
        aux = x/(float)this->largura;
        // aux = (aux-0.05)*(18)/(0.95-0.05);
        aux = (aux-0.05)*(36)/(0.95-0.05)-18;
    }
    else {
        aux = x;
        if (aux > 18.0) {
            printf("Coordenada X maior que limites, ajustado para 18\n");
            aux = 18.0;
        }
        else if (aux < -18.0) {
            printf("Coordenada X menor que limites, ajustado para 18\n");
            aux = -18.0;
        }
        // aux = aux*0.9/18+0.05;
        aux = (aux+18)*0.9/36+0.05;
    }
    return aux;
}
float Principal::mapY(float y, bool isAbs) {
    float aux;
    if(!isAbs) {
        aux = 1-y/(float)this->altura;
        // aux = (aux-0.15)*(16)/(0.95-0.15);
        aux = (aux-0.15)*(32)/(0.95-0.15)-16;
    }
    else {
        aux = y;
        if(aux > 16.0) {
            printf("Coordenada Y maior que limites, ajustado para 16\n");
            aux = 16.0;
        }
        else if(aux < -16.0) {
            printf("Coordenada Y menor que limites, ajustado para -16\n");
            aux = -16.0;
        }
        // aux = aux*(0.8)/16+0.15;
        aux = (aux+16)*(0.8)/32+0.15;
    }
    return aux;
}
// Proporção entre desenho e sistema de coordenadas
float Principal::map(float aresta) {
    return aresta/40;
}

bool Principal::valida(float v[][2], int qt) {
    float auxx=-20, auxy=-20;
    for(int i=0; i<qt; i++) {
        if(auxx == v[i][0] && auxy == v[i][1]) {
            printf("Pontos iguais... Pfvr tente novamente...\n");
            return false;
        }
        auxx = v[i][0];
        auxy = v[i][1];
    }
    return true;
}

Button::Button(const char *s, int w, int h, int start) {
    displayText = s;
    state = false;
    wwidth = w;
    wheigth = h;
    boundaries[0] = start;
    // int a = glutBitmapLength(GLUT_BITMAP_HELVETICA_12, (unsigned char*)displayText);
    // // cout << a;
    // float b = a/(float)w;
    // boundaries[0] = 0.0;
    // boundaries[1] = b;
}
void Button::reDraw() {
    int a = glutBitmapLength(GLUT_BITMAP_HELVETICA_12, (unsigned char*)displayText);
    // cout << a;
    float s = (float)boundaries[0]/(float)wwidth;
    float b = (float)a/(float)wwidth + s;
    boundaries[1] = a+boundaries[0];
    if(state) {
        // cout << state << endl;
        glColor3f(1, 0, 0);
    } else {
        glColor3f(190/255.0, 190/255.0, 190/255.0);
    }
    glBegin(GL_QUADS);
        glVertex2f(s, 0.05);
        glVertex2f(b, 0.05);
        glVertex2f(b, 0);
        glVertex2f(s, 0);
    glEnd();
    glColor3f(168/255.0, 168/255.0, 168/255.0);
    glLineWidth(1);
    glBegin(GL_LINES);
        glVertex2f(b, 0.05);
        glVertex2f(b, 0);
    glEnd();
    glColor3f(0, 0, 0);
    glRasterPos2f(s, 0.025);
    const char *write = displayText;
    while (*write)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *write++);
}
// Retorna se botão esta ativo
bool Button::getState() {
    return state;
}
// Ativa o botão quando colisao
bool Button::colision(int x, int y) {
    if(x > boundaries[0] && x < boundaries[1] && y < wheigth && y > 0.95*wheigth) {
        state = !state;
        return true;
    }
    else
        return false;
}

TextBar::TextBar() {
    value = 0.0;
    splitNum = 0;
}

void TextBar::reText() {
    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
        glVertex2f(0, 0.05);
        glVertex2f(0, 0.1);
        glVertex2f(1, 0.1);
        glVertex2f(0, 0.1);
    glEnd();
    glColor3f(190/255.0, 190/255.0, 190/255.0);
    glLineWidth(2);
    glBegin(GL_LINES);
        glVertex2f(0, 0.1);
        glVertex2f(1, 0.1);
    glEnd();

    glColor3f(0, 0, 0);
    glRasterPos2f(0, 0.075);

    if(texto.length() > 0) {
        glColor3f(0, 0, 0);
        glRasterPos2f(0, 0.075);
        for(int i = 0; i < texto.length(); i++)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, texto.at(i));
        // value = stof(texto);
    } else {
        value = 0.0;
    }
}

float TextBar::getValue() {
    return value;
}
// Quebra a string texto em segmentos de float separados por espaço
void TextBar::split() {
    if(!texto.empty()) {
        string aux;
        int index = 0;
        
        for(int i = 0; i < texto.length(); i++) {
            if(texto.at(i) == ' ') {
                aux = texto.substr(index, i-index);
                index = i;
                sub.push_back(stof(aux));
            }
        }
        aux = texto.substr(index, texto.length()-index);
        sub.push_back(stof(aux));
    }
}

void TextBar::clear() {
    if(!sub.empty())
        sub.clear();
    if(!texto.empty())
        texto.clear();
}
// Retorna um valor float quebrado da entrada, executado apos quebrar palavra
float TextBar::getAt(int i) {
    if(i < sub.size())
        return sub.at(i);
    return -1.0;
}

void TextBar::putChar(unsigned char key) {
    texto.push_back(key);
}
void TextBar::popChar() {
    if(texto.length() > 0)
        texto.pop_back();
}
void TextBar::addTexto(string t) {
    texto.append(t);
}
// Retorna quantidade de palavras quebradas
int TextBar::getSubCount() {
    return sub.size();
}