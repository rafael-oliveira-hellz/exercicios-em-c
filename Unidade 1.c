#include <stdio.h>

/* 
**
**
**
 */

int main(){
   float valor1 = 0, valor2 = 0;

   printf("\nDigite o primeiro valor: ");
   scanf_s("%f", &valor1);
   printf("Digite o segundo valor: ");
   scanf_s("%f", &valor2);
   printf("\nVariável 1 = %.2f", valor1);
   printf("\nVariável 2 = %.2f", valor2);

   return 0;
}