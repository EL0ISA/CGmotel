#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
            case 5:
                list_func();
                break;
            }
    } while (opc!=0);
}
void cad_func(void){
    system("clear||cls");
    char cpf[12];
    Funcionario* func;
    func = (Funcionario*) malloc(sizeof(Funcionario));
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Cadastrando novo funcionario   .......                \n");
    printf("*-------------------------------------------------------------------------------*\n");
    w_cpf(cpf);
    if(encont_func(cpf,'I')==0){
        strcpy(func->cpf,cpf);
        w_email(func->email);
        w_nome(func->nome);
        w_nasc(func->nasc);
        printf("                 .......   Funcao do funcionario   .......            \n");
        printf("|                             1. Gerente                                        |\n");
        printf("|                             2. Recepcao                                       |\n");
        printf("|                             3. Faxineiro(a)                                   |\n");
        w_funcao(&(func->funcao));
        func->status='A';
        grava_func(func);
    }else{
        printf("- Funcionario ja cadastrado com esse CPF!\n");
    }
    printf("*-------------------------------------------------------------------------------*\n");
    printf("\t>>");
    getchar();
    free(func);
}
void grava_func(Funcionario* func){
    FILE* fp;
    fp = fopen("funcionarios.dat","ab");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo\n");
        exit(1);
    }
    fwrite(func, sizeof(Funcionario), 1, fp);
    fclose(fp);
}
void list_func(void){
    FILE* fp;
    Funcionario* func;
    func = (Funcionario*) malloc(sizeof(Funcionario));
    fp = fopen("funcionarios.dat", "rb");
    if (fp == NULL) {
        printf("Não foi possivel abrir o arquivo!");
        getchar();
    }
    while(fread(func,sizeof(Funcionario), 1, fp)){
        if(func->status!='I'){
            most_func(func);
        }
    }
    free(func);
    fclose(fp);
}

void most_func(Funcionario* func){
    printf("CPF: %s\n", func->cpf);
    printf("Email: %s\n", func->email);
    printf("Nome: %s\n", func->nome);
    printf("Data de Nascimento: %s\n", func->nasc);
    printf("Status: %c\n", func->status);
    getchar();
}
void pesq_func(void){
    system("clear||cls");
    char cpf[12];
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Pesquisando dados de funcionario   .......            \n");
    printf("*-------------------------------------------------------------------------------*\n");
    w_cpf(cpf);
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Resultados Encontrados   .......                      \n");
    encont_func(cpf,'M');
    printf("*-------------------------------------------------------------------------------*\n");
    printf("\t>> Digite ENTER para prosseguir!");
    getchar();
}
int encont_func(char cpf[],char ope){
    FILE* fp;
    int existe=0;
    Funcionario* func;
    func = (Funcionario*) malloc(sizeof(Funcionario));
    fp = fopen("funcionarios.dat", "rb");
    if (fp == NULL) {
        fp = fopen("funcionarios.dat","ab");
    }
    while(fread(func,sizeof(Funcionario), 1, fp)){
        if (strcmp(func->cpf, cpf)==0 && func->status=='A') {
            if(ope=='M'){
                most_func(func);
            }
            existe=1;
        }
    }
    free(func);
    fclose(fp);
    return existe;
}
void edit_func(void){
    char cpf[12];
    int opc;
    FILE* fp;
    Funcionario* func;
    func = (Funcionario*) malloc(sizeof(Funcionario));
    fp = fopen("clientes.dat", "r+b");
    system("clear||cls");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Atualizando dados de funcionario   .......            \n");
    printf("*-------------------------------------------------------------------------------*\n");
    w_cpf(cpf);
    if (fp == NULL) {
        printf("Não foi possivel abrir o arquivo!");
        getchar();
    }
    if(encont_func(cpf,'I')==1){
        while(fread(func,sizeof(Funcionario), 1, fp)){
            do
            {
                if (strcmp(func->cpf, cpf)==0 && func->status=='A') {
                    printf("1 - Email: %s\n", func->email);
                    printf("2 - Nome: %s\n", func->nome);
                    printf("3 - Data de Nascimento: %s\n", func->nasc);
                    printf("0 - Finalizar alteracoes.");
                    printf("\n -Campo que deseja editar:");
                    scanf("%d",&opc);
                    fflush(stdin);
                    switch (opc)
                    {
                    case 1:
                        w_email(func->email);
                        break;
                    case 2:
                        w_nome(func->nome);
                        break;
                    case 3:
                        w_nasc(func->nasc);
                        break;
                    }
                    fseek(fp, -1*(sizeof(Funcionario)), SEEK_CUR);
                    fwrite(func, sizeof(Funcionario), 1, fp);
                }
            } while (opc!=0);
        }
    }else{
        printf("- Funcionario nao encontrado!\n");
    }
    free(func);
    fclose(fp);
    printf("*-------------------------------------------------------------------------------*\n");
    printf("\t>> Digite ENTER para prosseguir!");
    getchar();
}
void del_func(void){
    char cpf[12];
    Funcionario* func;
    FILE* fp;
    func = (Funcionario*) malloc(sizeof(Funcionario));
    system("clear||cls");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Deletando funcionario   .......                       \n");
    printf("*-------------------------------------------------------------------------------*\n");
    w_cpf(cpf);
    fp = fopen("clientes.dat", "r+b");
    if (fp == NULL) {
        printf("Não foi possivel abrir o arquivo!");
        getchar();
    }
    if(encont_func(cpf,'I')==1){
        while(fread(func,sizeof(Funcionario), 1, fp)){
            if (strcmp(func->cpf, cpf)==0) {
                func->status = 'I';
                fseek(fp, -1*(sizeof(Funcionario)), SEEK_CUR);
                fwrite(func, sizeof(Funcionario), 1, fp);
            }
        }
    }else{
        printf("- Funcionario nao encontrado!");
    }
    fclose(fp);
    free(func);
    printf("*-------------------------------------------------------------------------------*\n");
    printf("\t>> Digite ENTER para prosseguir!");
    getchar();
}