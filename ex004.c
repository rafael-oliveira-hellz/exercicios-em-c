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

    int idade;

    wprintf(L"Digite sua idade: ");
    scanf("%d", &idade);

    if (idade >= 18) {
        wprintf(L"Você já pode tirar carteira de habilitação.");
    } else {
        wprintf(L"Você é dimenó");
    }

    return 0;
};