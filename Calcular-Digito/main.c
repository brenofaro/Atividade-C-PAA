#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int parseInt(char character){
    return character - '0';
}

char parseChar(int number){
    return number + '0';
}

int max(int numbers[], int tam){
    int max = 0;
    for (int i = 0; i < tam; i++)
    {
        if (numbers[i] > max)
        {
            max = numbers[i];
        }
    }
    return max;
}

char calcular_digito(char *chave){
    int group1[3], group2[3], group3[3];
    int i,j;
      
    for (i = 0; i < 3; i++)
    {
        group1[i] = parseInt(chave[i]);
    }
    j = 0;
    for (i = 4; i < 7; i++)
    {
        group2[j] = parseInt(chave[i]);
        j++;
    }
    j = 0;
    for (i = 8; i < 11; i++)
    {
        group3[j] = parseInt(chave[i]);
        j++;
    }

    int verificador = (max(group1, 3) + max(group2, 3) + max(group3, 3)) % 10;
    return parseChar(verificador);
}

int main(){
    
    char string[] = "001.290.611-6";

    int digitoVerificador;
    int i, j;
    char entrada[20];


    while (strcmp(entrada, "FIM\n") != 0)
    {
        fgets(entrada, 20, stdin);
        if (strcmp(entrada, "FIM\n") == 0)
        {
            break;
        }
        digitoVerificador = parseInt(entrada[12]);
        if (parseInt(calcular_digito(entrada)) == digitoVerificador)
        {
            printf("VALIDO\n");
        }
        else
            printf("INVALIDO\n");
    }
}