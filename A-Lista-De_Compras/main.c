#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_TAM 100

typedef enum {
    INSERIR,
    REMOVER,
    REMOVERGRUPO,
    CONSULTAR,
    PROCURAR
} OperacaoLista;

typedef struct
{
    char nome[50];
    double preco;
    int quantidade;
} Produto;

typedef struct
{
    Produto *produtos;
    int nProdutos;
    int capacidade;
} Carrinho;

void inicializar(Carrinho  *carrinho){
    carrinho->capacidade = 2;
    carrinho->nProdutos = 0;
    carrinho->produtos = (Produto *) malloc(carrinho->capacidade * sizeof(Produto));
}



OperacaoLista verificaOperacao(char *entrada){
    if (strcmp(entrada, "INSERIR") == 0)
    {
        return INSERIR;
    }
    else if (strcmp(entrada, "REMOVER") == 0)
    {
        return REMOVER;
    }
    else if (strcmp(entrada, "REMOVERGRUPO") == 0)
    {
        return REMOVERGRUPO;
    }
    else if (strcmp(entrada, "CONSULTAR") == 0)
    {
        return CONSULTAR;
    }
    else
    {
        return PROCURAR;
    }
}

void inserirProduto(Carrinho *carrinho, Produto produto){
    if (carrinho->nProdutos >= carrinho->capacidade)
    {
        carrinho->produtos = (Produto *)realloc(carrinho->produtos, sizeof(Produto) * carrinho->capacidade * 2);
        carrinho->capacidade *= 2;
    }
    carrinho->produtos[carrinho->nProdutos] = produto;
    (carrinho->nProdutos)++;
}

void removerProduto(Carrinho *carrinho, Produto produtoRemover){

    for (int i = 0; i < carrinho->nProdutos; i++)
    {
        if (strcmp(carrinho->produtos[i].nome, produtoRemover.nome) == 0)
        {
            carrinho->produtos[i].quantidade -= produtoRemover.quantidade;
            if (carrinho->produtos[i].quantidade == 0)
            {
                (carrinho->capacidade)--;
                (carrinho->nProdutos)--;
                return;
            }
        }
    }    
}

int main(){
    char entrada[MAX_TAM];
    int tam = 10;
    Carrinho carrinho;
    

    inicializar(&carrinho);

    

    while (1)
    {
        fgets(entrada, MAX_TAM, stdin);

        char *token;
        strcpy(token, entrada);
        strtok(token, " ");

        Produto produto;

        OperacaoLista operacao = verificaOperacao(token);
        switch (operacao)
        {
        case INSERIR:
            

            sscanf(entrada, "%*s %s %lf %d", produto.nome, &produto.preco, &produto.quantidade);
            inserirProduto(&carrinho, produto);
            break;

        case REMOVER:
            sscanf(entrada, "%*s %s %d", produto.nome, &produto.quantidade);
            removerProduto(&carrinho, produto);
            break;
        
        default:
            break;
        }
        
        
        
        
    }
    


    return 0;
}