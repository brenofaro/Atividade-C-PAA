#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

float tracoMatrizN(float **matriz, int ordem){
    float soma = 0;
    int i,j = 0;
    printf("tr(A) = ");
    for (i = 0; i< ordem; i++){
        soma += matriz[i][j];
        printf("(%.2f)", matriz[i][j]);
        if(i != ordem -1)
            printf(" + ");
        j++;
    }
    return soma;
}




int main() {
    int ordem;
    int i,j;
    
    
    scanf("%d", &ordem);

    float **matriz = (float **)malloc (sizeof(float*) * ordem);
    for (i=0; i<ordem;i++){
        matriz[i] = (float *) malloc (sizeof(float) * ordem);
    }

    for (i=0; i < ordem; i++){
        for (j=0; j < ordem;j++){
            scanf("%f", &matriz[i][j]);
        }
    }
    printf(" = %.2f", tracoMatrizN(matriz, ordem));
    
    
	return 0;
}