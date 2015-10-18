#ifndef __gauss_jordan_h__
#ifndef __stdio_h__
#include <stdio.h>
#endif
#define __gauss_jordan_h__

static float sistema[3][4];
static int sucecion[] = {1, 2, 2, 0, 0, 1}, *dimr = sucecion;
static void div_x_inver(int colum), print();
static int i = 0, j = 0;
void gauss_jordan(){
    static char *incognitas[] = {"x","y","z", "Libre"};
    puts("Digame porfavor el cociente de las incognitas y el termino libre:");
    for (i = 0;i < 3; i++){
        printf("\t Fila %d\t\n", (i+1));
        for (j = 0; j < 4; j++){
            printf("%s = ", incognitas[j]);
            scanf("%f", &sistema[i][j]);
        }
    }
    system("cls");
    puts("Matriz dada:");
    print();
    div_x_inver(i);/**Creé una sola función para acelerar la velocidad de ejecución*/
    puts("Matriz resultante:");
    (sistema[0][0] == 1 && sistema[1][1] == 1 && sistema[2][2] == 1)?  print(): puts("El sistema no tiene solucion");
}

static void div_x_inver(int colum){
    float inval, divisor;
    int k;
    for(i = 0; i < 3; i++){
        divisor = sistema[i][i];
        for (j = 0; j < 4; j++){
            sistema[i][j] /= divisor;
        }
        for (k = 0; k < 2; k++, dimr++){
            inval = -sistema[dimr[0]][colum]; /**Creo el valor inverso, utilizo el puntero dimr y avanzo con su indice*/
            for (j = 0; j < 4; j++){
                sistema[dimr[0]][j] += (inval * sistema[colum][j]);
            }
        }
    }
}
static void print(){
    for (i = 0; i < 3; i++){
        for(j = 0; j < 4; j++){
            printf("%.2f\t", sistema[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
#endif
