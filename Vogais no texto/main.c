#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_TAM 255



void zeraArray(int *array, int tam){
    for (int i = 0; i < tam - 1; i++){
        array[i] = 0;
    }
}

void lerArray(int array[], int tam){
    for (int i = 0; i < tam; i++){
        char letra = (i + '0') + 49;
        printf("%c = %d\n",letra, array[i]);

    }
}

void lerQuantidadeVogais(int *array){

    printf("a %d\n", array[0]);
    printf("e %d\n", array[4]);
    printf("i %d\n", array[8]);
    printf("o %d\n", array[14]);
    printf("u %d", array[20]);
}

void numberOfLetters(char *texto, int *array){
    int i = 0;
    while (texto[i] != '\0')
    {
        int index = (texto[i] - '0') - 49;
        if (index >= 0 && index <= 25)
        {
            array[index] ++;
        }
        i++;
    }
}

int main(){
    char entrada[MAX_TAM];
    int letterCounts[26];
    zeraArray(letterCounts, 26);
    fgets(entrada, MAX_TAM, stdin);
    numberOfLetters( entrada, letterCounts);
    lerQuantidadeVogais(letterCounts);

    return 0;
}