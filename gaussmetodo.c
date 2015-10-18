#include"fun_datos.h"



void ing_igc(int *num,float Sist[][100]){
    int a,b;
    printf("\n\n ||Metodo gaussiano, sistemas de ecuaciones||");
    printf("\n\n\n Introduce el numero de incognitas:(menor que 100)\n");
    scanf("%d",&*num);
    printf("\n\n Introduzca los coeficientes:");
    printf("\n\n Matriz:\n");
    printf("\n\n coeficiente:\n");
    for(a=1;a<=*num;a++){
            for(b=1;b<=*num;b++){
    printf("\n Termino(%d,%d):",a,b);
    scanf("%f",&Sist[a][b]);}
    printf("\n\n\n Termino:\n");
    }
    for(a=1;a<=*num;a++){
        printf("\n igualdad(%d):",a);
        scanf("%f",&Sist[a][*num+1]);
    }}

void imp_sis(int Dim, float Sist[][100])
{
    int a,b;
    for(a=1;a<=Dim;a++){
        for(b=1;b<=(Dim+1);b++){
            printf("%7.2f",Sist[a][b]);
            if(b==Dim) printf("   |");}
        printf("\n");
    }}

void operador_metodo_gauss(int Dim, float Sist[][100])
{
    int nc,Col,c1,c2,a;
    float cambio,Vectr1;

    for(Col=1;Col<=Dim;Col++){
        nc=0;a=Col;
        while(nc==0){
            if(Sist[a][Col]!=0){
                nc=1;}
            else a++;}
        cambio=Sist[a][Col];
        for(c1=1;c1<=(Dim+1);c1++){
            Vectr1=Sist[a][c1];
            Sist[a][c1]=Sist[Col][c1];
            Sist[Col][c1]=Vectr1/cambio;}
        for(c2=Col+1;c2<=Dim;c2++){
            Vectr1=Sist[c2][Col];
            for(c1=Col;c1<=(Dim+1);c1++){
                Sist[c2][c1]=Sist[c2][c1]-Vectr1*Sist[Col][c1];}
    }}

    for(Col=Dim;Col>=1;Col--) for(c1=(Col-1);c1>=1;c1--){
        Sist[c1][Dim+1]=Sist[c1][Dim+1]-Sist[c1][Col]*Sist[Col][Dim+1];
        Sist[c1][Col]=0;
    }
}
