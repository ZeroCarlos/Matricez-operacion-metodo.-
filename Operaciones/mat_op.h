#ifndef __mat_op_h__
#ifndef __stdio_h__
#include <stdio.h>
#endif
#ifndef __man_dat_h__
#include "man_dat.h"
#endif
#define __mat_op_h__

int dim_mat2[0], dim_mat1[0];
static int i, j, k, m;
static float **matriz1 = NULL, **matriz2 = NULL;
int dim_mat3[2];
void lectura_val(float **matriz, int dim[]);

float** producto(float **matriz1, float **matriz2, float **r_matriz, int mat1[], int mat2[]){
	static float r_mult;
	lectura_val(matriz1, mat1);
	lectura_val(matriz2, mat2);
	system("cls");
	puts("Matrices dadas:");
	printp(matriz1, mat1);
	puts("");
	printp(matriz2, mat2);
	m = 0;
         for(i = 0; i < mat1[1]; i++){
            for(j = 0; j < mat2[0]; j++){
                r_mult = 0;
                for(k = 0; k < mat1[0]; k++){
                    r_mult += matriz1[i][k] * matriz2[k][j];
                    }
                r_matriz[i][j] = r_mult;
            }
            m = 0;
        }
    return r_matriz;
}

void lectura_dim(int dimensiones[],const int i){
        printf("Tamano la matriz %d:\n\tFilas = ", i);
        scanf("%d", &dimensiones[1]);
        printf("\tColumnas = ");
        scanf("%d", &dimensiones[0]);
}

void lectura_val(float **matriz, int dim[]){
    for(i = 0; i < dim[1]; i++){
        printf("Fila %d:\n", (i + 1));
        for(j = 0; j < dim[0]; j++){
            scanf("%f", &matriz[i][j]);
        }
    }
}

float** Operacion_de_matriz(float **r_matriz){
	system("cls");
	puts("Multiplicacion");
	int dim_mat1[2], dim_mat2[2];
	lectura_dim(dim_mat1, 1);
	lectura_dim(dim_mat2, 2);
	if(dim_mat1[0] == dim_mat2[1]){
		matriz1 = reserva(dim_mat1, matriz1);
		matriz2 = reserva(dim_mat2, matriz2);
		dim_mat3[0] = dim_mat2[0];
		dim_mat3[1] = dim_mat1[1];
		r_matriz = reserva(dim_mat3, r_matriz);
		return producto(matriz1, matriz2, r_matriz, dim_mat1, dim_mat2);
	}
		else{
            printf("La matriz no es adecuada para este proceso, el numero de filas de la matriz 1 debe concordar con las columnas de la matriz 2\n");
            return 0;
		}
	}
}
#endif
