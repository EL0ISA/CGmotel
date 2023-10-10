#include <stdio.h>
#include <stdlib.h>
#include "funcionario.h"
#include "auxiliares.h"

void menu_funcionarios(void){
    int opc;
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
        scanf("%d",&opc);
        fflush(stdin);
        switch (opc)
            {
            case 1:
                cad_func();
                break;
            
            case 2:
                pesq_func();
                break;
            case 3:
                edit_func();
                break;
            case 4:
                del_func();
                break;
            }
    } while (opc!=0);
}
void cad_func(void){
    system("clear||cls");
    char cpf[11],nome[50],email[255],nasc[10];
    int funcao=0;
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Cadastrando novo funcionario   .......                \n");
    printf("*-------------------------------------------------------------------------------*\n");
    w_cpf(cpf);
    w_email(email);
    w_nome(nome);
    w_nasc(nasc);
    printf("                 .......   Funcao do funcionario   .......            \n");
    printf("|                             1. Gerente                                        |\n");
    printf("|                             2. Recepcao                                       |\n");
    printf("|                             3. Faxineiro(a)                                   |\n");
    w_funcao(&funcao);
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