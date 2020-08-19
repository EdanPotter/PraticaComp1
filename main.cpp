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

int winh = 640, winw = 640;
Principal tela = Principal(winh, winw);

void Desenha(void) {
	// Limpa a janela de visualização com a cor branca xd
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);

    tela.reDraw();

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

// Função callback chamada para gerenciar eventos de teclas
void Teclado(unsigned char key, int x, int y) {
	tela.typed(key);

    glutPostRedisplay();
}

// Função responsável por inicializar parametros e variaveis
void Inicializa(void) {
	// Define a janela de visualizaçao 2D
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 1, 1, 0);
	glMatrixMode(GL_MODELVIEW);
}
void reshape(int width, int height) {
    winw = width;
    winh = height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 1, 0, 1);
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
    glutInitWindowPosition(550, 150);
    
    // Cria a janela passando como argumento o titulo da mesma
	glutCreateWindow("Pratica Transformacoes");
 
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