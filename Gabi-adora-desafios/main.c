#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void derivada (int *coeficiente, int *expoente){
    *coeficiente = (*coeficiente) * (*expoente);
    (*expoente)--;
}

int main(){
    int entrada = -1;
    int coeficiente, expoente;
    char icognita;
    int contador;

    while (entrada != 0)
    {
        scanf("%d", &entrada);
        contador = 0;
        if (entrada == 0)
        {
            break;
        }
        
        
        for (int i = 0; i < entrada; i++)
        {
            scanf("%d %c %d", &coeficiente, &icognita, &expoente);
            if (i == 0)
            {
                printf("f'(%c)=", icognita);
            }
            
            derivada(&coeficiente, &expoente);
            if (coeficiente > 0)
            {
                printf("+");
            }
            
            if (expoente > 0)
            {
                printf("%d%c^%d", coeficiente, icognita, expoente);
                contador++;
            }
            else if (coeficiente != 0)
            {
                printf("%d", coeficiente, icognita, expoente);
                contador++;
            }
            else{
                if (contador == 0)
                {
                    printf("%d", coeficiente);
                }  
            }
                
        }
        printf("\n");
    }

    

    return 0;
}