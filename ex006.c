#include <stdio.h>

int main(){
    float nota_final = 0.0;

    printf("Digite a nota final do aluno: ");
    scanf("%f", &nota_final);

    if (nota_final >= 60){
        printf("\nAprovado");
    } else if (nota_final >= 50) {
        printf("\n Em recuperação");
    } else {
        printf("\nReprovado");
    }
    return 0;
};