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
#define sgn(x) ((x<0)?-1:((x>0)?1:0)) //macro que retorna o sinal de um número

void desenha(int x, int y){
	glBegin(GL_POINT);
       glVertex2i(x,y);
    glEnd();
}

void ER(int x1, int y1, int x2, int y2){
	glClear(GL_COLOR_BUFFER_BIT);               // limpa a janela
    glColor3f (0.0, 0.0, 0.0);                  // cor da linha
	int dx,dy,sdx,sdy,px,py,dxabs,dyabs,i;
	float inclinacao;

	dx=x2-x1;      /* distância horizontal da linha */
	dy=y2-y1;      /* distância vertical da linha */
	dxabs=abs(dx);
	dyabs=abs(dy);
	sdx=sgn(dx);
	sdy=sgn(dy);

	if (dxabs>=dyabs) /* a linha é mais horizontal que vertical */
	{
		inclinacao=(float)dy / (float)dx;
		for(i=0;i!=dx;i+=sdx)
		{
		      px=i+x1;
		      py=inclinacao*i+y1;    // dy=slope*delta_x
		      desenha(px,py);

		}

	}
	else /* a linha é mais vertical que horizontal */
	{
		inclinacao=(float)dx / (float)dy;
		for(i=0;i!=dy;i+=sdy)
		{
		      px=inclinacao*i+x1;
		      py=i+y1;
		      glBegin(GL_POINT);
                glVertex2f(px,py);
              glEnd();
		}
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
  ER(20,20,14,14);
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
    glutInitWindowSize (400, 400);                          // especifica as dimensoes da janela
    glutInitWindowPosition (100, 100);                      // especifica aonde a janela aparece na tela
    glutCreateWindow ("Desenhando uma linha");              // cria a janela
    init();
    glutDisplayFunc(display);                               // funcao que sera redesenhada pelo GLUT
    glutKeyboardFunc(keyboard);                             // funcoes de teclado
    glutMainLoop();
    return 0;
}

