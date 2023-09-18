#include <stdio.h>
#include <stdlib.h>
#include "funcionario.h"

void menu_funcionarios(void){
    char opc;
    do
    {
        system("clear||cls");
        printf("*-------------------------------------------------------------------------------*\n");
        printf("*                               Menu Funcionarios                               *\n");
        printf("*-------------------------------------------------------------------------------*\n");
        printf("|                             1. Cadastrar novo                                 |\n");
        printf("|                             2. Pesquisar dados                                |\n");
        printf("|                             3. Atualizar dados                                |\n");
        printf("|                             4. Deletar funcionario                            |\n");
        printf("|                             0. Voltar                                         |\n");
        printf("*-------------------------------------------------------------------------------*\n");
        printf("-- Sua opc: ");
        scanf("%c",&opc);
        while (getchar() != '\n');
        switch (opc)
            {
            case '1':
                cad_func();
                break;
            
            case '2':
                pesq_func();
                break;
            case '3':
                edit_func();
                break;
            case '4':
                del_func();
                break;
            }
    } while (opc!='0');
}
void cad_func(void){
    system("clear||cls");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Cadastrando novo funcionario   .......                \n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("|            - CPF (apenas numeros):                                            |\n");
    printf("|            - Nome completo:                                                   |\n");
    printf("|            - E-mail:                                                          |\n");
    printf("|            - Data de Nascimento (dd/mm/aaaa):                                 |\n");
    printf("|            - Funcao:                                                          |\n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("\t>>");
    getchar();
}
void pesq_func(void){
    system("clear||cls");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Pesquisando dados de funcionario   .......            \n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("|            - Informe o CPF (apenas numeros):                                  |\n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("\t>> Digite ENTER para prosseguir!");
    getchar();
}
void edit_func(void){
    system("clear||cls");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Atualizando dados de funcionario   .......            \n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("|            - Informe o CPF (apenas numeros):                                  |\n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("\t>> Digite ENTER para prosseguir!");
    getchar();
}
void del_func(void){
    system("clear||cls");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Deletando funcionario   .......                       \n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("|            - Informe o CPF (apenas numeros):                                  |\n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("\t>> Digite ENTER para prosseguir!");
    getchar();
}