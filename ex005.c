#include <stdio.h>

int main(){
    int n;

    printf("Digite (1) para Saldo, (2) para extrato, (3) para Saque e (4) para Sair.");
    printf("Digite a opção desejada: ");

    scanf("%d", &n);

    switch (n)
    {
    case 1:
        printf("\nSaldo");
        break;
    case 2:
        printf("\nExtrato");
        break;
    case 3:
        printf("\nSaque");
        break;
    case 4:
        printf("\nSair");
        break;
    default:
        printf("\nInválido");
    }
return 0;
};