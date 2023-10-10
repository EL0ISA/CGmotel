#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "auxiliares.h"

void menu_clientes(void){
    int opc;
    do
    {
        system("clear||cls");
        printf("\n*-------------------------------------------------------------------------------*\n");
        printf("*                               Menu Clientes                                   *\n");
        printf("*-------------------------------------------------------------------------------*\n");
        printf("|                             1. Cadastrar novo                                 |\n");
        printf("|                             2. Pesquisar dados                                |\n");
        printf("|                             3. Atualizar dados                                |\n");
        printf("|                             4. Deletar cliente                                |\n");
        printf("|                             0. Voltar                                         |\n");
        printf("*-------------------------------------------------------------------------------*\n");
        printf("-- Sua opc: ");
        scanf("%d",&opc);
        fflush(stdin);
        switch (opc)
        {
        case 1:
            cad_cli();
            break;
        
        case 2:
            pesq_cli();
            break;
        case 3:
            edit_cli();
            break;
        case 4:
            del_cli();
            break;
        }
    } while (opc!=0);
}
void cad_cli(void){
    system("clear||cls");
    char cpf[11],nome[50],email[255],nasc[10];
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Cadastrando novo cliente   .......                    \n");
    printf("*-------------------------------------------------------------------------------*\n");
    w_cpf(cpf);
    w_email(email);
    w_nome(nome);
    w_nasc(nasc);
    printf("*-------------------------------------------------------------------------------*\n");
    printf("\t>> Digite ENTER para prosseguir!");
    getchar();
}
void pesq_cli(void){
    system("clear||cls");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Pesquisando dados de cliente   .......                \n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("|            - Informe o CPF (apenas numeros):                                  |\n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("\t>> Digite ENTER para prosseguir!");
    getchar();
}
void edit_cli(void){
    system("clear||cls");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Atualizando dados de cliente   .......                \n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("|            - Informe o CPF (apenas numeros):                                  |\n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("\t>> Digite ENTER para prosseguir!");
    getchar();
}
void del_cli(void){
    system("clear||cls");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Deletando cliente   .......                           \n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("|            - Informe o CPF (apenas numeros):                                  |\n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("\t>> Digite ENTER para prosseguir!");
    getchar();
}