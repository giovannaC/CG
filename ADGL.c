/* Giovanna Cazelato Pires RA: 141151171
   Algoritimos de Geração de Linha:
   - Equação da Reta.
   - DDA.
   - BRESENHAM.
    Algoritimos de Geração de Circunferencia:
   - BRESENHAM.
----------------------------------------------
   Não consegui fazer o programa rodar do modo
esperado(gerando gráficos), mas está executando
sem nenhum erro ou warning.
*/
#include<windows.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <gl/gl.h>

//Equação da Reta
void ER(int x1, int y1, int x2, int y2){
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

    for(i = xi; i<=xii; i++){
        yf = (m * i) + b;
        yi = round(yf);
        glBegin(GL_POINTS);
            glVertex2f(i,yi);
        glEnd();
    }
}
// Digital Diferential Analyzer
void DDA(int x1, int y1, int x2, int y2){
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
    SetPixel(NULL,round(x),round(y),RGB(220,20,60));

    for(i=1; i<inter; i++){
        x = x + x_inc;
        y = y + y_inc;
        SetPixel(NULL,round(x),round(y),RGB(220,20,60));
    }
}
// Bresenham para Linhas
void BRESENHAM_L(int x1, int y1, int x2, int y2){
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
    SetPixel(NULL,x, y,RGB(220,20,60));
    while(x < xFinal){
        x = x + 1;
        if(d < 0){
            d = d + const1;
        }else{
            y = y + 1;
            d = d + const2;
        }
        SetPixel(NULL,x, y,RGB(220,20,60));
    }
}
//Bresenham para cirunferencias
void BRESENHAM_C(int xCentro, int yCentro, int raio){
    int x, y, d;
    x = 0;
    y = raio;
    d = 1 - raio;
    plotaPontosCicunferencia(xCentro, yCentro, x, y);
    while(x < y){
        if(d<0){
            d = d + 2 * x + 3;
        }else{
            d = d + 2 * (x - y) + 5;
            y = y - 1;
        }
    x = x + 1;
    plotaPontosCicunferencia(xCentro, yCentro, x, y);
    }
}
// Ler o x1, y1, x2, y2
void readxy(int x1, int y1, int x2, int y2){
    printf("\nDigite o x1: ");
    scanf("%d",&x1);
    printf("\nDigite o y1: ");
    scanf("%d",&y1);
    printf("\nDigite o x2: ");
    scanf("%d",&x2);
    printf("\nDigite o y2: ");
    scanf("%d",&y2);
}
// Menu do programa
int menu(){
    int op;
    printf("1. Equacão da Reta.\n");
    printf("2. Digital Diferential Analyzer\n");
    printf("3. Bresenham para Linhas\n");
    printf("0. Sair\n");
    scanf("%d",&op);
        return op;
}

int main(int argc, char *argv[]){
    int x1, x2, y1, y2, op;
    readxy(x1,y1,x2,y2);
    while(op > 0){
        op = menu();
        switch(op){
            case 1:
                ER(x1,y1,x2,y2);
                    break;
            case 2:
                DDA(x1,y1,x2,y2);
                    break;
            case 3:
                BRESENHAM_L(x1,y1,x2,y2);
                    break;
        }
    }
    return 0;
}
