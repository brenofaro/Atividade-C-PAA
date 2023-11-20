#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int nMoradores;
    int consumo;
    double consumoMedio;
    int removido; // Se for -1 foi removido, se for 0 não foi
    
} Imovel;


typedef struct
{
    Imovel *imoveis;
    double consumoTotal;
    int nCasas;
} Cidade;

void inicializar(Cidade *cidade){
    cidade->consumoTotal = 0;
    for (int i = 0; i < cidade->nCasas; i++)
    {
        cidade->imoveis[i].removido = 0;
    }
}


void ordenarImoveisPorConsumo(Cidade *cidade){
    int i,j;
    for (int i = 0; i < cidade->nCasas; i++)
    {
        for (int j = i; j < cidade->nCasas; j++)
        {
            if (cidade->imoveis[j].consumoMedio < cidade->imoveis[i].consumoMedio)
            {
                Imovel aux = cidade->imoveis[i];
                cidade->imoveis[i] = cidade->imoveis[j];
                cidade->imoveis[j] = aux;
            }
        } 
    }
}

Cidade agruparImoveisPorConsumo(Cidade *cidade){
    Cidade aux;
    aux.nCasas = 0;
    aux.imoveis = (Imovel *) malloc(sizeof(Imovel) * cidade->nCasas);
    int nPessoas;
    int consumoMedio;
    for (int i = 0; i < cidade->nCasas; i++)
    {
        for (int j = i; j < cidade->nCasas; j++)
        {
            if (cidade->imoveis[i].removido != -1)
            {
               if (j == i)
                {
                    nPessoas = cidade->imoveis[j].nMoradores;
                    consumoMedio = cidade->imoveis[j].consumoMedio;
                }
                
                if (cidade->imoveis[j].consumoMedio == cidade->imoveis[i].consumoMedio && i != j)
                {
                    nPessoas += cidade->imoveis[j].nMoradores;
                    cidade->imoveis[j].removido = -1;
                }
            }
            else
                break;
        }
        if (cidade->imoveis[i].removido != -1){
            
            Imovel imovel;
            imovel.consumo = consumoMedio* nPessoas;
            imovel.consumoMedio = consumoMedio;
            imovel.nMoradores = nPessoas;
            imovel.removido = 0;
            aux.imoveis[aux.nCasas] = imovel;
            aux.nCasas ++;
        }
    }
    aux.consumoTotal = cidade->consumoTotal;
    return aux;
}

void imprimirCidades(Cidade *cidade){
    int nPessoasTotal = 0;
    for (int i = 0; i < cidade->nCasas; i++)
    {
        printf("%d-%.0lf", cidade->imoveis[i].nMoradores,cidade->imoveis[i].consumoMedio);
        if (i != cidade->nCasas -1)
        {
            printf(" ");
        }
        nPessoasTotal += cidade->imoveis[i].nMoradores;
    }
        printf("\n");
        printf("Consumo medio: %.2lf m3.", cidade->consumoTotal / nPessoasTotal);
        printf("\n");
        printf("\n");

    

}

int main(){
    int numCasas = -1;
    int cidadeAtual = 1;
    Imovel imovel;
    Cidade cidade;
    while (numCasas != 0)
    {
        scanf("%d", &numCasas);
        if (numCasas == 0)
        {
            break;
        }
        
        cidade.nCasas = numCasas;
        Imovel *imoveis = (Imovel *) malloc(sizeof(imovel) * numCasas);
        cidade.imoveis =  imoveis;
        inicializar(&cidade);

        for (int i = 0; i < numCasas; i++)
        {
            scanf("%d %d", &imovel.nMoradores, &imovel.consumo);
            imovel.consumoMedio = imovel.consumo / imovel.nMoradores;
            cidade.imoveis[i] = imovel;
            cidade.consumoTotal += imovel.consumo;
        }
        cidade = agruparImoveisPorConsumo(&cidade);
        ordenarImoveisPorConsumo(&cidade);
        printf("Cidade# %d:\n", cidadeAtual);
        imprimirCidades(&cidade);
        cidadeAtual++;      
    }
    

    return 0;
}