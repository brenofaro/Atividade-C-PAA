#include <stdio.h>
#include <stdlib.h>

int **lerMatriz(int nLinhas, int nColunas){
    int **matriz = NULL;
    
    // Alocação inicial da matriz para as linhas
    matriz = (int **) malloc (nLinhas * sizeof(int *));

    for (int i = 0; i < nLinhas; i++)
    {   
        // Alocando as colunas de cada linha
        matriz[i] = (int *) malloc (sizeof(int) * nColunas);
        
        for (int j = 0; j < nColunas; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
        
    }
    return matriz;
}

int verificaMatrizGlobal(int **matriz, int tam){
    int somaLinhas = 0;
    int somaColunas = 0;
    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            somaLinhas += matriz[i][j];
            somaColunas += matriz[j][i];
        }
        if (somaLinhas != 45 || somaColunas != 45)
        {
            return 1;
            break;
        }
        somaLinhas = 0;
        somaColunas = 0;
    }
    return 0;
}

int verificaMatrizInterna(int **matriz){
    int somaMatrizInterna = 0;
    int x, y;

    for (int y = 0; y < 9; y += 3)
    {
        for (int x = 0; x < 9; x += 3)
        {
            // For para olhar cada matriz individual
            for (int i = x; i < x + 3; i++)
            {
                for (int j = y; j < y + 3; j++)
                {
                    somaMatrizInterna += matriz[i][j];
                }
            }
            if (somaMatrizInterna != 45)
                {
                    return 1;
                }
            somaMatrizInterna = 0;
        }
        
    }
    
    return 0;
}


int main(){

    int **matriz = NULL;
    int resultadoGlobal = 0, resultadoInterna = 0;

    matriz = lerMatriz(9,9);
    resultadoGlobal += verificaMatrizGlobal(matriz, 9);
    resultadoInterna += verificaMatrizInterna(matriz);

    if (resultadoGlobal == 0 && resultadoInterna == 0)
        printf("YES");
    else if (resultadoGlobal != 0)
    {
        printf("NO\n");
        printf("GLOBAL");
    }
    else
    {
        printf("NO\n");
        printf("INTERNA");
    }
    
    free(matriz);

    return 0;
}