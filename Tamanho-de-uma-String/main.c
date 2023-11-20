#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int tamstr(char *texto){
    char *ponteiro;
    ponteiro = texto;

    while (*ponteiro != '\0')
    {
        ponteiro++;
    }
    return (ponteiro - texto) - 1;
}


int main(){
    char str[10];
    int cont = 0;
    while (strcmp(str, "FIM") != 0)
    {
        fgets(str, 10, stdin);
        if (strcmp(str, "FIM") == 0)
        {
            break;
        }
        else
        {
            if (cont != 0)
            {
                printf("\n");
            }
            
        }
        
        printf("%d", tamstr(str));
        cont++;
    }


    return 0;
}