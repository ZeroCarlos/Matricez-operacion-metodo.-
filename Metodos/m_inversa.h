#ifndef __m_inversa_h__
#ifndef __stdio_h__
#include <stdio.h>
#endif
#ifndef __stdio_h__
#include <stdio.h>
#endif
#define __m_inversa_h__

int inverza(){
    int i=0,n=0;
    float matriz [3][4], matriz_identidad[3][3];
    matriz_identidad[0][0]= 1;matriz_identidad[0][1]=0;matriz_identidad[0][2]=0,matriz_identidad[1][0]=0;matriz_identidad[1][1]=1;matriz_identidad[1][2]=0,matriz_identidad[2][0]=0;matriz_identidad[2][1]=0;matriz_identidad[2][2]=1;
    printf("ingrese los datos\n");
    while (i<4){
        printf("Introduzca la posicion:  [%d][%d]\n",n,i);
        scanf("%f",&matriz[n][i]);
        if(matriz[n][i]==0){
                printf("No puedes introducir un valor nulo en la matriz");}
        if (n==2){
                if (i<2){ printf(" Ahora vamos con la siguiente columna\n");}
        n-=3;
        i++;
        }
        if (i==3&&n<0){
            printf("Introduzca los terminos libres\n");
        }
        n++;
    }
printf("Sistema de Ecuaciones                   Matriz de identidad   \n");
printf("|%g|     |%g|    |%g|     |X|   =   %g    |%g|   |%g|   |%g| \n",matriz[0][0],matriz[0][1],matriz[0][2],matriz[0][3],matriz_identidad[0][0],matriz_identidad[0][1],matriz_identidad[0][2]);
printf("|%g|     |%g|    |%g|     |Y|   =   %g    |%g|   |%g|   |%g|\n",matriz[1][0],matriz[1][1],matriz[1][2],matriz[1][3],matriz_identidad[1][0],matriz_identidad[1][1],matriz_identidad[1][2]);
printf("|%g|     |%g|    |%g|     |Z|   =   %g    |%g|   |%g|   |%g|\n",matriz[2][0],matriz[2][1],matriz[2][2],matriz[2][3],matriz_identidad[2][0],matriz_identidad[2][1],matriz_identidad[2][2]);
float aux = matriz[0][0];
if(matriz[0][0] != 1){// R1/matriz[0][0]
        matriz[0][0]=matriz[0][0]/aux;
        matriz[0][1]=matriz[0][1]/aux;
        matriz[0][2]=matriz[0][2]/aux;
        matriz[0][3]=matriz[0][3]/aux;
matriz_identidad[0][0]=matriz_identidad[0][0]/aux;
}
aux=-matriz[1][0];//r1*-el valor actual de matriz[1][1]+r2
int aux2=-matriz[2][0];
 if(matriz[0][0] == 1){
    matriz[1][0]=(matriz[0][0]*aux)+matriz[1][0];
    matriz[1][1]=(matriz[0][1]*aux)+matriz[1][1];
    matriz[1][2]=(matriz[0][2]*aux)+matriz[1][2];
    matriz[1][3]=(matriz[0][3]*aux)+matriz[1][3];
matriz_identidad[1][0]=(matriz_identidad[0][0]*aux)+matriz_identidad[1][0];
matriz_identidad[1][1]=(matriz_identidad[0][1]*aux)+matriz_identidad[1][1];
matriz_identidad[1][2]=(matriz_identidad[0][2]*aux)+matriz_identidad[1][2];
   //r1*-el valor actual de matriz[1][1]+r2
matriz[2][0]=(matriz[0][0]*aux2)+matriz[2][0];
matriz[2][1]=(matriz[0][1]*aux2)+matriz[2][1];
matriz[2][2]=(matriz[0][2]*aux2)+matriz[2][2];
matriz[2][3]=(matriz[0][3]*aux2)+matriz[2][3];
matriz_identidad[2][0]=(matriz_identidad[0][0]*aux2)+matriz_identidad[2][0];
matriz_identidad[2][1]=(matriz_identidad[0][1]*aux2)+matriz_identidad[2][1];
matriz_identidad[2][2]=(matriz_identidad[0][2]*aux2)+matriz_identidad[2][2];
}
aux = matriz[1][1];
if(matriz[1][1]==0){
    printf("LA MATRIZ NO TIENE INVERZA");
}
else if(matriz[1][1] != 1){// R2/matriz[1][1]
        matriz[1][1]=matriz[1][1]/aux;
        matriz[1][2]=matriz[1][2]/aux;
        matriz[1][3]=matriz[1][3]/aux;
matriz_identidad[1][0]=matriz_identidad[1][0]/aux;
matriz_identidad[1][1]=matriz_identidad[1][1]/aux;
matriz_identidad[1][2]=matriz_identidad[1][2]/aux;
}
aux=-matriz[0][1];//r2*-el valor actual de matriz[0][1]+r1
aux2=-matriz[2][1];
 if(matriz[1][1] == 1){
    matriz[0][1]=(matriz[1][1]*aux)+matriz[0][1];
    matriz[0][2]=(matriz[1][2]*aux)+matriz[0][2];
    matriz[0][3]=(matriz[1][3]*aux)+matriz[0][3];
matriz_identidad[0][0]=(matriz_identidad[1][0]*aux)+matriz_identidad[0][0];
matriz_identidad[0][1]=(matriz_identidad[1][1]*aux)+matriz_identidad[0][1];
matriz_identidad[0][2]=(matriz_identidad[1][2]*aux)+matriz_identidad[0][2];
   //r2*-el valor actual de matriz[2][1]+r3
matriz[2][1]=(matriz[1][1]*aux2)+matriz[2][1];
matriz[2][2]=(matriz[1][2]*aux2)+matriz[2][2];
matriz[2][3]=(matriz[1][3]*aux2)+matriz[2][3];
matriz_identidad[2][0]=(matriz_identidad[1][0]*aux2)+matriz_identidad[2][0];
matriz_identidad[2][1]=(matriz_identidad[1][1]*aux2)+matriz_identidad[2][1];
matriz_identidad[2][2]=(matriz_identidad[1][2]*aux2)+matriz_identidad[2][2];
}
if(matriz[2][2]==0){
    printf("LA MATRIZ NO TIENE INVERZA");
}
aux=matriz[2][2];
 if(matriz[2][2] != 1){// R3/matriz[2][2]
        matriz[2][2]=matriz[2][2]/aux;
        matriz[2][3]=matriz[2][3]/aux;
matriz_identidad[2][0]=matriz_identidad[2][0]/aux;
matriz_identidad[2][1]=matriz_identidad[2][1]/aux;
matriz_identidad[2][2]=matriz_identidad[2][2]/aux;
}
aux=-matriz[0][2];//r3*-el valor actual de matriz[0][2]+r1
aux2=-matriz[1][2];
 if(matriz[2][2] == 1){
matriz[0][2]=(matriz[2][2]* aux)+matriz[0][2];
matriz[0][3]=(matriz[2][3]* aux)+matriz[0][3];
matriz_identidad[0][0]=(matriz_identidad[2][0]*aux)+matriz_identidad[0][0];
matriz_identidad[0][1]=(matriz_identidad[2][1]*aux)+matriz_identidad[0][1];
matriz_identidad[0][2]=(matriz_identidad[2][2]*aux)+matriz_identidad[0][2];
   //r2*-el valor actual de matriz[2][1]+r3
matriz[1][2]=(matriz[2][2]* aux2)+ matriz[1][2];
matriz[1][3]=(matriz[2][3]* aux2)+ matriz[1][3];
matriz_identidad[1][0]=(matriz_identidad[2][0]*aux2)+matriz_identidad[1][0];
matriz_identidad[1][1]=(matriz_identidad[2][1]*aux2)+matriz_identidad[1][1];
matriz_identidad[1][2]=(matriz_identidad[2][2]*aux2)+matriz_identidad[1][2];
}

printf("Sistema de Ecuaciones            solucion   Matriz de identidad   \n");
printf("|%g|     |%g|    |%g|     |X|   =   %g       |%g|   |%g|   |%g| \n",matriz[0][0],matriz[0][1],matriz[0][2],matriz[0][3],matriz_identidad[0][0],matriz_identidad[0][1],matriz_identidad[0][2]);
printf("|%g|     |%g|    |%g|     |Y|   =   %g       |%g|   |%g|   |%g|\n",matriz[1][0],matriz[1][1],matriz[1][2],matriz[1][3],matriz_identidad[1][0],matriz_identidad[1][1],matriz_identidad[1][2]);
printf("|%g|     |%g|    |%g|     |Z|   =   %g       |%g|   |%g|   |%g|\n",matriz[2][0],matriz[2][1],matriz[2][2],matriz[2][3],matriz_identidad[2][0],matriz_identidad[2][1],matriz_identidad[2][2]);
return 0;}
#endif
