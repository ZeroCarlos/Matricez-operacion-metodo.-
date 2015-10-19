#include <stdio.h>
#include <stdlib.h>
#include "Metodos/gauss_jordan.h"
#include "Metodos/m_inversa.h"
#include "Operaciones/mat_op.h"
#include "Operaciones/suma_m.h"
#include "Operaciones/resta_m.h"
#include "man_dat.h"
#include "fun_datos.h"

int main(){
    int c,car;
    float sistema[100][100];
    int seleccion = 0;
    float **r_matriz = NULL;
    do{
        printf("Operaciones y metodos de resolucion de matrices\n\t1. Operaciones con matrices\n\t2. Metodos de resolucion de matrices\n\t3. Salir\n");
        scanf("%d", &seleccion);
        system("cls");
        switch(seleccion){
        case 1:
            puts("Operaciones de resolucion de matrices\n\t1. Multiplicacion\n\t2. Suma\n\t3. Resta");
            scanf("%d", &seleccion);
            switch(seleccion){
                case 1:
                r_matriz = Operacion_de_matriz(r_matriz);
                extern int dim_mat3[];
                puts("\tMatriz Resultante:");
                printp(r_matriz, dim_mat3);
                liberacion(dim_mat3, r_matriz);
                break;
                case 2:
                suma_matriz();
                break;
                case 3:
                resta_matriz();
                break;
                default:
                puts("La operacion especificada no esta definida");
                seleccion = 1;
            }
        case 2:
            puts("Metodos de resolucion de matrices\n\t1.Gauss Jordan\n\t2. Gauss\n\t3. Matriz inversa\n");
            scanf("%d", &seleccion);
            switch(seleccion){
                case 1:
                gauss_jordan();
                break;
                case 2:
                ing_igc(&car,sistema);
                printf("\n\n\nSistema introducido: \n\n");
                imp_sis(car,sistema);
                operador_metodo_gauss(car,sistema);
                printf("\n\n\nLas solucion es:\n");
                for(c=1;c<=car;c++){
                    printf("\n X%d=%f\n",c,sistema[c][car+1]);
                }
                break;
                case 3:
                inversa();
                break;
                default:
                break;
            }
        case 3:
            seleccion = 0;
            break;
        default:
            puts("No le he comprendido, acaso:");
            break;
    }
    if(seleccion != 0){
            printf("Desea realizar alguna otra operacion?[1/0]\t");
            scanf("%d", &seleccion);
            system("cls");
    }
    }while(seleccion != 0);
    scanf("");
    return 0;
}
