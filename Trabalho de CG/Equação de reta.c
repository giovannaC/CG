/* Giovanna Cazelato Pires RA: 141151171
   Algoritimos de Geração de Linha:
   - Equação da Reta.
*/
#include<windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include <gl/gl.h>

void ER(int x1, int y1, int x2, int y2){
    glClear(GL_COLOR_BUFFER_BIT);               // limpa a janela
    glColor3f (1.0, 1.0, 1.0);                  // cor da linha
    int i, yi, xi, xii;
    float m, b, dx, dy, yf;

    if(x2 < x1){
        xi = x1;
        xii = x2;
    }else{
        xi = x2;
        xii = x1;
    }
    dx = (x2 - x1);
    dy = (y2 - y1);

    if(dx == 0){
        m = 0;
    }else{
        m = dy / dx;
    }
    b = y1 - (m*x1);
    i = xi;
    while(i < xii){
        yf = (m*i) + b;
        glBegin(GL_POINT);
            glVertex2f(i*,round(yf)*);
        glEnd();
        i++;
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
  ER(4,7,14,14);
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

