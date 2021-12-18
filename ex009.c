#include <stdlib.h>
#include <locale.h>
#include <stdio.h>
#include <wchar.h>

#define VET_TAM 5

int main(void){

    /* We wish to use the user's current locale. */
    setlocale(LC_ALL, "");

    /* We intend on using wide functions on standard output. */
    fwide(stdout, 1);

    /* For Windows compatibility, print out a Byte Order Mark.
     ** If you save the output to a file, this helps tell Windows
     ** applications that the file is Unicode.
     ** Other systems don't need it nor use it.
    */
    fputwc(L'\uFEFF', stdout);

    int vetor[VET_TAM];
    int num, i = 0, achou = 0;

    for (int i = 0; i < VET_TAM; i++){
        wprintf(L"\nEntre com um número: ");
        scanf("%d", &vetor[i]);
    }

    wprintf(L"\nInforme o número a ser encontrado: ");
    scanf("%d", &num);

    while (i < VET_TAM){
        if (vetor[i] == num) {
            achou = 1;
            break;
        }
        i++;
    }

    if (achou == 1){
        wprintf(L"\nO número %d foi encontrado na posição %d do vetor", num, i);
    } else {
        wprintf(L"O número %d não foi encontrado no vetor", num);
    }

    return 0;
};