/* Giovanna Cazelato Pires RA: 141151171
   Algoritimos de Geração de Circunferencia:
   - BRESENHAM.
*/
#include<windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include <gl/gl.h>

void plotaPontosCircunferencia(int xCentro,int yCentro,int x,int y){
    glBegin(GL_POINTS);
        glVertex2i((xCentro+x)*10,(yCentro+y)*10);
    glEnd();
    glBegin(GL_POINTS);
        glVertex2i((xCentro+y)*10,(yCentro+x)*10);
    glEnd();
    glBegin(GL_POINTS);
        glVertex2i((xCentro+y)*10,(yCentro-x)*10);
    glEnd();
    glBegin(GL_POINTS);
        glVertex2i((xCentro+x)*10,(yCentro-y)*10);
    glEnd();
    glBegin(GL_POINTS);
        glVertex2i((xCentro-x)*10,(yCentro-y)*10);
    glEnd();
    glBegin(GL_POINTS);
        glVertex2i((xCentro-y)*10,(yCentro-x)*10);
    glEnd();
    glBegin(GL_POINTS);
        glVertex2i((xCentro-y)*10,(yCentro+x)*10);
    glEnd();
    glBegin(GL_POINTS);
        glVertex2i((xCentro-x)*10,(yCentro+y)*10);
    glEnd();
}
void BRESENHAM_C(int xCentro, int yCentro, int raio){
    glClear(GL_COLOR_BUFFER_BIT);               // limpa a janela
    glColor3f (1.0, 1.0, 1.0);                  // cor da linha

    int x, y, d;
    x = 0;
    y = raio;
    d = 1 - raio;
    plotaPontosCircunferencia(xCentro, yCentro, x, y);
    while(x < y){
        if(d<0){
            d = d + 2 * x + 3;
        }else{
            d = d + 2 * (x - y) + 5;
            y = y - 1;
        }
    x = x + 1;
    plotaPontosCircunferencia(xCentro, yCentro, x, y);
    }
    glFlush();
}
// prototipos das funcoes
void init(void){
  glClearColor(0.0, 0.0, 0.0, 0.0);    // cor de fundo
  glOrtho (0, 256, 0, 256, -1 ,1);     // modo de projecao ortogonal
}

void display(void){
  glClear(GL_COLOR_BUFFER_BIT);               // limpa a janela
  glColor3f (0.0, 0.0, 0.0);                  // cor da linha
  BRESENHAM_C(0,0,7);
  glFlush();
}

void keyboard(unsigned char key, int x, int y){
  switch (key) {
  case 27:                                         // tecla Esc (encerra o programa)
	exit(0);
	break;
  }
}

int main(int argc, char *argv[]){
    glutInit(&argc, argv);                              // inicializa o glut
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);           // especifica o uso de cores e buffers
    glutInitWindowSize (256, 256);                          // especifica as dimensoes da janela
    glutInitWindowPosition (100, 100);                      // especifica aonde a janela aparece na tela
    glutCreateWindow ("Desenhando um arco");              // cria a janela
    init();
    glutDisplayFunc(display);                               // funcao que sera redesenhada pelo GLUT
    glutKeyboardFunc(keyboard);                             // funcoes de teclado
    glutMainLoop();
    return 0;
}
