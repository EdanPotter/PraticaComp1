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
#include "include/InputUtils.h"
using namespace std;

float pontos[100][2];
int qt = 0;
int winh = 480, winw = 640;
void teste(int) {}
char s[100];
int qtLetras = 0;
char* c = "dalae";
Button b = Button("Triangulo", winw, winh, 0, teste);
Button d = Button("Quadrado", winw, winh, 55, teste);

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
    b.reDraw();
    d.reDraw();
    TextBar t = TextBar();
    t.reText(s);
    glPointSize(1);
    // Desenha um triângulo no centro da janela
    // glBegin(GL_POLYGON);
    //     switch (f.getForma()) {
    //         case TRIANGULO:
    //             break;
    //         case QUADRADO:
    //             break;
    //         case HEXAGONO:
    //             break;            
    //         default:
    //             break;
    //     }
    // glEnd();
	
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
            if(b.colision(x, y)) {
                cout << "X" << endl;
            } else if (d.colision(x, y)) cout << "D" << endl;
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
        s[qtLetras] = 0;
        qtLetras--;
    }
    else {
        s[qtLetras] = key;
        qtLetras++;
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