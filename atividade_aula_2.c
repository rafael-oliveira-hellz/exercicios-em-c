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

    float salario_bruto, desc_ir, desc_inss, salario_liquido;

    wprintf(L"Cálculo de salário com desconto de IR e INSS");

    wprintf(L"\nDigite o salário bruto do funcionário: ");
    scanf("%f", &salario_bruto);

    // Cálculo de desconto do IR
    if (salario_bruto <= 1903.98){
        desc_ir = 0;
    } else if (salario_bruto <= 2826.65){
        desc_ir = salario_bruto * 0.075;
    } else if (salario_bruto <= 3751.05){
        desc_ir = salario_bruto * 0.15;
    } else if (salario_bruto <= 4664.68){
        desc_ir = salario_bruto * 0.225;
    } else {
        desc_ir = salario_bruto * 0.275;
    }

    // Cálculo de desconto do INSS
    if (salario_bruto <= 1045.0){
        desc_inss = salario_bruto * 0.075;
    } else if (salario_bruto <= 2089.60){
        desc_inss = salario_bruto * 0.09;
    } else if (salario_bruto <= 3134.40){
        desc_inss = salario_bruto * 0.12;
    } else {
        desc_inss = salario_bruto * 0.14;
    }

    salario_liquido = salario_bruto - desc_inss - desc_ir;

    wprintf(L"Desconto do INSS: %.2f", desc_inss);
    wprintf(L"\nDesconto do IR: %.2f", desc_ir);
    wprintf(L"\nSalário líquido: R$ %.2f", salario_liquido);

    return 0;
};