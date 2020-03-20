//*****************************************************
// Prática 1 - Computação Gráfica - Eng. Comp. UTFPR-TD
// André Francisco Pastório
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
void teste(int) {}
char s[100];
string boxValue = "";
int qtLetras = 0;
Button triButton = Button("Triangulo", winw, winh, 0, teste);
Button quaButton = Button("Quadrado", winw, winh, 55, teste);
Button hexaButton = Button("Hexagono", winw, winh, 118, teste);
Button apagaButton = Button("Apagar", winw, winh, 180, teste);

TextBar barText = TextBar();

void Desenha(void) {
	// Limpa a janela de visualização com a cor branca
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(190/255.0, 190/255.0, 190/255.0);
    glBegin(GL_QUADS);
        glVertex2f(0, 0.95);
        glVertex2f(1, 0.95);
        glVertex2f(1, 1);
        glVertex2f(0, 1);
    glEnd();
    triButton.reDraw();
    quaButton.reDraw();
    hexaButton.reDraw();
    apagaButton.reDraw();
    
    barText.reText();
    // cout << t.getValue() << endl;
    glPointSize(1);

	//Executa os comandos OpenGL 
	glFlush();
}
// Gerenciamento do menu com as opções de cores
void MenuCor(int op)
{
    switch (op)
    {
    default:
        break;
    }
    glutPostRedisplay();
}
// Gerenciamento do menu com as opções de cores
void MenuPrimitiva(int op)
{
    switch (op)
    {
        default:
            break;
    }
    glutPostRedisplay();
}

// Gerenciamento do menu principal
// void MenuPrincipal(int op)
// {
//     f.setForma((FORMA)op);
//     return;
// }

// Criacao do Menu
void CriaMenu()
{
    int menu, submenu1, submenu2;

    // menu = glutCreateMenu(MenuPrincipal);
    // glutAddMenuEntry("Triângulo", TRIANGULO);
    // glutAddMenuEntry("Quadrado", QUADRADO);
    // glutAddMenuEntry("Hexágono", HEXAGONO);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void Mouse(int rightkey, int release, int x, int y) {
    if(!rightkey) {
        if(release) {
            if(triButton.colision(x, y)) {
                cout << "TRI" << endl;
            } else if (quaButton.colision(x, y)) {
                cout << "QUAD" << endl;
            } else if (hexaButton.colision(x, y)) {
                cout << "HEXA" << endl;
            } else if(apagaButton.colision(x, y)) {
                cout << "APAGA" << endl;
            }
        }
    } else {
        CriaMenu();
    }
}

// Fun��o callback chamada para gerenciar eventos de teclas
void Teclado(unsigned char key, int x, int y)
{
	if (key == 27)
		exit(0);
    else if(key == 8) {
        barText.popChar();
    } else if(key == 13) {
        barText.split();
        cout << barText.getAt(0) << "/" << barText.getAt(2) << "/" << endl;
    } else {
        barText.putChar(key);
    }

    glutPostRedisplay();
}

// Fun��o respons�vel por inicializar par�metros e vari�veis
void Inicializa(void)
{
	// Define a janela de visualiza��o 2D
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
    
    // Cria a janela passando como argumento o t�tulo da mesma
	glutCreateWindow("Primeiro Programa");
 
	// Registra a fun��o callback de redesenho da janela de visualiza��o
	glutDisplayFunc(Desenha);
    glutReshapeFunc(reshape);

	// Registra a fun��o callback para tratamento das teclas ASCII
	glutKeyboardFunc(Teclado);
    glutMouseFunc(Mouse);

    // Chama a fun��o respons�vel por fazer as inicializa��es 
	Inicializa();
 
	// Inicia o processamento e aguarda intera��es do usu�rio
	glutMainLoop();
 
	return 0;
}

void DesenhaTriangulo() {}
void DesenhaQuadrado() {}
void DesenhaHexagono() {}