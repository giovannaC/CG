
/* Giovanna Cazelato Pires RA: 141151171
   Algoritimos de Geração de Linha:
   - DDA.
*/
#include<windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include <gl/gl.h>

void DDA(int x1, int y1, int x2, int y2){
    glClear(GL_COLOR_BUFFER_BIT);               // limpa a janela
    glColor3f (1.0, 1.0, 1.0);                  // cor da linha

    int dx, dy, inter, i;
    float x_inc, y_inc, x, y;

    dx = x2 - x1;
    dy = y2 - y1;

    if (abs(dx) > abs(dy)){
        inter = abs(dx);
    }else{
        inter = abs(dy);
    }
    x_inc = dx/inter;
    y_inc = dy/inter;
    x = x1;
    y = y1;
    glBegin(GL_POINTS);
        glVertex2i(x*10,y*10);//  glVertex2i(14*10,14*10);    // coordenadas inicial e final da linha
    glEnd();

    for(i=1; i<inter; i++){
        x = x + x_inc;
        y = y + y_inc;
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
  DDA(4,7,14,14);
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

