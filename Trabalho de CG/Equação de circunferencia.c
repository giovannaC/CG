/* Giovanna Cazelato Pires RA: 141151171
   Algoritimos de Geração de Circunferencia:
   - Equação da Circuncferencia.
*/
#include<windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include <gl/gl.h>
#define PI 3.1415926535897932


void EC(int xCentro, int yCentro, int raio){
    glClear(GL_COLOR_BUFFER_BIT);               // limpa a janela
    glColor3f (1.0, 1.0, 1.0);                  // cor da linha
    int x, y, i;
    for (i = 0; i < 100 + 1; i++){
    x = xCentro + raio * cos(2.0 * PI * i / 100);
    y = yCentro + raio * sin(2.0 * PI * i / 100);
    glBegin(GL_POINTS);
        glVertex2f(x*10,y*10);
    glEnd();
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
  glColor3f (1.0, 1.0, 1.0);                  // cor da linha
  EC(0,0,7);
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

