#include <stdlib.h>
#include <locale.h>
#include <stdio.h>
#include <wchar.h>

int main(){
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

    int linha, coluna;
    int matriz[3][3];
    int diagonal = 1;

    for (linha = 0; linha < 3; linha++) {
        for (coluna = 0; coluna < 3; coluna++) {
            printf("\nDigitar os valores da matriz para [linha %d, coluna %d]: ", linha + 1, coluna + 1);
            scanf("%d", &matriz[linha][coluna]);
        }
    }
    
    for (linha = 0; linha < 3; linha++) {
        for (coluna = 0; coluna < 3; coluna++) {
           if (coluna != linha && matriz[linha][coluna] != 0) {
               diagonal = 0;
           }
        }
    }

    if (diagonal == 1) {
        wprintf(L"\n\nSua matriz é diagonal!");
    } else {
        wprintf(L"\n\nSua matriz não é diagonal!");
    }
    
    return 0;
};