#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
        printf("|                             5. Listar todos                                   |\n");
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
        case 5:
            list_cli();
            break;
        }
    } while (opc!=0);
}

void cad_cli(void){
    system("clear||cls");
    char cpf[12];
    Cliente* cli;
    cli = (Cliente*) malloc(sizeof(Cliente));
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Cadastrando novo cliente   .......                    \n");
    printf("*-------------------------------------------------------------------------------*\n");
    w_cpf(cpf);
    strcpy(cli->cpf,cpf);
    w_email(cli->email);
    w_nome(cli->nome);
    w_nasc(cli->nasc);
    printf("*-------------------------------------------------------------------------------*\n");
    printf("\t>> Digite ENTER para prosseguir!");
    getchar();
    grava_cli(cli);
    free(cli);
}
void grava_cli(Cliente* cli){
    FILE* fp;
    fp = fopen("clientes.dat","ab");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo\n");
        exit(1);
    }
    fwrite(cli, sizeof(Cliente), 1, fp);
    fclose(fp);
}
void list_cli(void){
    FILE* fp;
    Cliente* cli;
    cli = (Cliente*) malloc(sizeof(Cliente));
    fp = fopen("clientes.dat", "rb");
    if (fp == NULL) {
        printf("Não foi possivel abrir o arquivo!");
        exit(1);
    }
    while(fread(cli,sizeof(Cliente), 1, fp)){
        most_cli(cli);
    }
    free(cli);
    fclose(fp);
}
void most_cli(Cliente* cli){
    printf("CPF: %s\n", cli->cpf);
    printf("Email: %s\n", cli->email);
    printf("Nome: %s\n", cli->nome);
    printf("Data de Nascimento: %s\n", cli->nasc);
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