/* Giovanna Cazelato Pires RA: 141151171
   Algoritimos de Geração de Linha:
   - BRESENHAM.
*/
#include<windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include <gl/gl.h>

void BRESENHAM_L(int x1, int y1, int x2, int y2){
    glClear(GL_COLOR_BUFFER_BIT);               // limpa a janela
    glColor3f (1.0, 1.0, 1.0);                  // cor da linha

    int dx, dy, d, const1, const2, x, y, xFinal;

    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    d = 2*dy - dx;
    const1 = 2*dy;
    const2 = 2*(dy - dx);

    if(x1 > x2){
        x = x2;
        y = y2;
        xFinal = x1;
    }else{
        x = x1;
        y = y1;
        xFinal = x2;
    }
    glBegin(GL_POINTS);
            glVertex2i(x*10,y*10); // glVertex2i(14*10,14*10);    // coordenadas inicial e final da linha
        glEnd();
    while(x < xFinal){
        x = x + 1;
        if(d < 0){
            d = d + const1;
        }else{
            y = y + 1;
            d = d + const2;
        }
        glBegin(GL_POINTS);
            glVertex2i(x*10,y*10); // glVertex2i(14*10,14*10);    // coordenadas inicial e final da linha
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
  glColor3f (0.0, 0.0, 0.0);                  // cor da linha
  BRESENHAM_L(4,7,14,14);
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
    glutCreateWindow ("Desenhando uma linha");              // cria a janela
    init();
    glutDisplayFunc(display);                               // funcao que sera redesenhada pelo GLUT
    glutKeyboardFunc(keyboard);                             // funcoes de teclado
    glutMainLoop();
    return 0;
}
