#include <stdlib.h>
#include <locale.h>
#include <stdio.h>
#include <wchar.h>

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

    float nota;

    do {
        wprintf(L"\nDigite a nota final do aluno: ");
        scanf("%f", &nota);

        if (nota < 0 || nota > 10){
            wprintf(L"\nNota inválida!");
        }
        
    } while (nota < 0 || nota > 10);
    return 0;
};