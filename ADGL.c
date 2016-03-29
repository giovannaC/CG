/* Giovanna Cazelato Pires ra: 141151171
   Algoritimos de Gera��o de Linha:
   - Equa��o da Reta.
   - DDA.
   - BRESENHAM.
*/

#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

//Equa��o da Reta
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
        glVertex2f(i,yi);
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
    SetPixel(round(x),round(y));

    for(i=1; i<inter; i++){
        x = x + x_inc;
        y = y + y_inc;
        SetPixel(round(x),round(y));
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
    SetPixel(x, y);
    while(x < xFinal){
        x = x + 1;
        if(d < 0){
            d = d + const1;
        }else{
            y = y + 1;
            d = d + const2;
        }
        SetPixel(x, y);
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
    printf("1. Equac�o da Reta.\n");
    printf("2. Digital Diferential Analyzer\n");
    printf("3. Bresenham para Linhas\n");
    printf("0. Sair\n");
    scanf("%d",&op);
        return op;
}
