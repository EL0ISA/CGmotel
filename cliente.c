#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "auxiliares.h"

void menu_clientes(void){
    int opc;
    char cpf[12];
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
        getchar();
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
            printf("*-------------------------------------------------------------------------------*\n");
            printf("                 .......   Deletando cliente   .......                           \n");
            printf("*-------------------------------------------------------------------------------*\n");
            w_cpf(cpf);
            del_cli(cpf);
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
    if(encont_cli(cpf,'I')==0){
        strcpy(cli->cpf,cpf);
        w_email(cli->email);
        w_nome(cli->nome);
        w_nasc(cli->nasc);
        cli->status = 'A';
        grava_cli(cli);
    }else{
        printf("- Cliente já cadastrado com esse CPF!\n");
    }
    printf("*-------------------------------------------------------------------------------*\n");
    printf("\t>> Digite ENTER para prosseguir!");
    getchar();
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
        getchar();
    }
    while(fread(cli,sizeof(Cliente), 1, fp)){
        if(cli->status!='I'){
            most_cli(cli);
        }
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
    char cpf[12];
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Pesquisando dados de cliente   .......                \n");
    printf("*-------------------------------------------------------------------------------*\n");
    w_cpf(cpf);
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Resultados Encontrados   .......                      \n");
    encont_cli(cpf,'M');
    printf("*-------------------------------------------------------------------------------*\n");
    printf("\t>> Digite ENTER para prosseguir!");
    getchar();
}
int encont_cli(char cpf[], char ope){
    FILE* fp;
    Cliente* cli;
    int existe=0;
    cli = (Cliente*) malloc(sizeof(Cliente));
    fp = fopen("clientes.dat", "rb");
    if (fp == NULL) {
        fp = fopen("clientes.dat","ab");
    }
    while(fread(cli,sizeof(Cliente), 1, fp)){
        if (strcmp(cli->cpf, cpf)==0 && cli->status=='A') {
            if(ope=='M'){
                most_cli(cli);
            }
            existe=1;
        }
    }
    free(cli);
    fclose(fp);
    return existe;
}
void edit_cli(void){
    char cpf[12];
    int opc;
    FILE* fp;
    Cliente* cli;
    cli = (Cliente*) malloc(sizeof(Cliente));
    fp = fopen("clientes.dat", "r+b");
    system("clear||cls");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Atualizando dados de cliente   .......                \n");
    printf("*-------------------------------------------------------------------------------*\n");
    w_cpf(cpf);
    if(encont_cli(cpf,'I')==1){
        while(fread(cli,sizeof(Cliente), 1, fp)){
            do
            {
                if (strcmp(cli->cpf, cpf)==0 && cli->status=='A') {
                    printf("1 - Email: %s\n", cli->email);
                    printf("2 - Nome: %s\n", cli->nome);
                    printf("3 - Data de Nascimento: %s\n", cli->nasc);
                    printf("0 - Finalizar alteracoes.");
                    printf("\n -Campo que deseja editar:");
                    scanf("%d",&opc);
                    getchar();
                    fflush(stdin);
                    switch (opc)
                    {
                    case 1:
                        w_email(cli->email);
                        break;
                    case 2:
                        w_nome(cli->nome);
                        break;
                    case 3:
                        w_nasc(cli->nasc);
                        break;
                    }
                    fseek(fp, -1*(sizeof(Cliente)), SEEK_CUR);
                    fwrite(cli, sizeof(Cliente), 1, fp);
                }
            } while (opc!=0);
        }
    }else{
        printf("- Cliente não encontrado!\n");
    }
    free(cli);
    fclose(fp);
    printf("*-------------------------------------------------------------------------------*\n");
    printf("\t>> Digite ENTER para prosseguir!");
    getchar();
}
void del_cli(char cpf[]){
    system("clear||cls");
    FILE* fp;
    Cliente* cli;
    cli = (Cliente*) malloc(sizeof(Cliente));
    fp = fopen("clientes.dat", "r+b");
    if (fp == NULL) {
        printf("Não foi possivel abrir o arquivo!");
        getchar();
    }
    if(encont_cli(cpf,'I')==1){
        while(fread(cli,sizeof(Cliente), 1, fp)){
            if (strcmp(cli->cpf, cpf)==0) {
                cli->status = 'I';
                fseek(fp, -1*(sizeof(Cliente)), SEEK_CUR);
                fwrite(cli, sizeof(Cliente), 1, fp);
            }
        }
    }
    fclose(fp);
    free(cli);
    printf("*-------------------------------------------------------------------------------*\n");
    printf("\t>> Digite ENTER para prosseguir!");
    getchar();
}