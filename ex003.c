#include <stdio.h>

#define TAM_NOME_CLIENTE 100
#define TAM_NOME_FILME 100

struct cliente
{
    char nome[TAM_NOME_CLIENTE];
    int idade;
};

struct cartaz
{
    int classificacao_filme;
    char nome_filme[TAM_NOME_FILME];
};

int main(void){
    struct cliente cli;
    struct cartaz filme;

    printf("Nome do cliente: ");
    scanf("%s", &cli.nome);

    printf("\nIdade do cliente: ");
    scanf("%d", &cli.idade);

    printf("\nNome do filme: ");
    scanf("%s", &filme.nome_filme);

    printf("\nClassificação indicativa: ");
    scanf("%d", &filme.classificacao_filme);

    printf("\nNome do Cliente: %s", cli.nome);
    printf("\nIdade do Cliente: %d", cli.idade);
    printf("\nClassificação indicativa: %d", filme.classificacao_filme);

    return 0;
};