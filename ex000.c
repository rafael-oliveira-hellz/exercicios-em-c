#include <stdio.h>

#define PI 3.14

int main() {
    char nome[100];
    int idade[3] = {0, 0, 0};

    fflush(stdin);
    fgets(nome, 100, stdin);

    printf("\nDigite seu nome: %s", nome);
    scanf("%s", &nome);

    printf("\nDigite sua idade: ");
    scanf("%d", &idade);

    return 0;
};