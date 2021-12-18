#include <stdio.h>
#include <ctype.h>

#define TAM_NOME 30

int main(){
    int i;
    char nome[TAM_NOME];

    printf("\nDigite o nome do aluno: ");

    fgets(nome, TAM_NOME, stdin);
    printf("\nNome ANTES da mudança: %s", nome);

    for (int i = 0; i < TAM_NOME    ; i++) {
        nome[i] = toupper(nome[i]);
    }
    
    printf("\nNome DEPOIS da mudança: %s", nome);

    return 0;
};