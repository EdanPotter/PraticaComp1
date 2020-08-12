//*****************************************************
// Prática 1 - Computação Gráfica - Eng. Comp. UTFPR-TD
// André Francisco Pastório e Pedro Baleroni
// 
//*****************************************************
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <stdlib.h>
#include <GL/glut.h>
#include <string>
#include <vector>
#include "include/InputUtils.h"

using namespace std;

int winh = 480, winw = 640;
Principal tela = Principal(winh, winw);
// void teste(int) {}

// asdasdasdasasds asniasdk

// string boxValue = "";

// Button triButton = Button("Triangulo", winw, winh, 0);
// Button quaButton = Button("Quadrado", winw, winh, 55);
// Button hexaButton = Button("Hexagono", winw, winh, 118);
// Button apagaButton = Button("Apagar", winw, winh, 180);
// Button transButton = Button("Translacao", winw, winh, 225);
// Button scaleButton = Button("Escala", winw, winh, 290);
// Button rotButton = Button("Rotacao", winw, winh, 330);
// Button reflexButton = Button("Reflexao", winw, winh, 380);
// Button cisButton = Button("Cisalhamento", winw, winh, 430);

// TextBar barText = TextBar();

void Desenha(void) {
	// Limpa a janela de visualização com a cor branca xd
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);
    // // Barra
	// glColor3f(190/255.0, 190/255.0, 190/255.0);
    // glBegin(GL_QUADS);
    //     glVertex2f(0, 0.95);
    //     glVertex2f(1, 0.95);
    //     glVertex2f(1, 1);
    //     glVertex2f(0, 1);
    // glEnd();
    // // Botoes
    // triButton.reDraw();
    // quaButton.reDraw();
    // hexaButton.reDraw();
    // apagaButton.reDraw();
    // transButton.reDraw();
    // scaleButton.reDraw();
    // rotButton.reDraw();
    // reflexButton.reDraw();
    // cisButton.reDraw();
    
    // barText.reText();

    tela.reDraw();
    // cout << t.getValue() << endl;
    // glPointSize(1);

	//Executa os comandos OpenGL 
	glFlush();
}

void Mouse(int rightkey, int release, int x, int y) {
    if(!rightkey) {
        if(release) {
            tela.clicked(x, y);
        }
    }
}

// Fun��o callback chamada para gerenciar eventos de teclas
void Teclado(unsigned char key, int x, int y) {
	tela.typed(key);
    // if (key == 27)
	// 	exit(0);
    // else if(key == 8) {
    //     barText.popChar();
    // } else if(key == 13) {
    //     barText.split();
    //     // Pega o selecionado e desenha // limpa sub // 
    //     cout << barText.getAt(0) << "/" << barText.getAt(2) << "/" << endl;
    // } else {
    //     barText.putChar(key);
    // }

    glutPostRedisplay();
}

// Função responsável por inicializar parametros e variaveis
void Inicializa(void) {
	// Define a janela de visualizaçao 2D
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 1, 1, 0);
	glMatrixMode(GL_MODELVIEW);
}
void reshape(int width, int height)
{
    winw = width;
    winh = height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 1, 1, 0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutPostRedisplay();
}

// Programa Principal
int main(int argc, char **argv)
{
    glutInit(&argc, argv); // Initialize GLUT

    // Especifica o tamanho inicial em pixels da janela GLUT
	glutInitWindowSize(winw, winh); 
    glutInitWindowPosition(600, 250);
    
    // Cria a janela passando como argumento o titulo da mesma
	glutCreateWindow("Primeiro Programa");
 
	// Registra a funçao callback de redesenho da janela de visualizaçao
	glutDisplayFunc(Desenha);
    glutReshapeFunc(reshape);

	// Registra a funçao callback para tratamento das teclas ASCII
	glutKeyboardFunc(Teclado);
    glutMouseFunc(Mouse);

    // Chama a funçao responsavel por fazer as inicializaçoes 
	Inicializa();
 
	// Inicia o processamento e aguarda intera��es do usu�rio
	glutMainLoop();
 
	return 0;
}

void DesenhaTriangulo() {}
void DesenhaQuadrado() {}
void DesenhaHexagono() {}