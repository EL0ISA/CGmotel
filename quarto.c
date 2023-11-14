#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "quarto.h"
#include "auxiliares.h"

void menu_quartos(void){
    int opc;
    do
    {
        system("clear||cls");
        printf("\n*-------------------------------------------------------------------------------*\n");
        printf("*                               Menu Quartos                                    *\n");
        printf("*-------------------------------------------------------------------------------*\n");
        printf("|                             1. Cadastrar novo                                 |\n");
        printf("|                             2. Pesquisar dados                                |\n");
        printf("|                             3. Atualizar dados                                |\n");
        printf("|                             4. Deletar quarto                                 |\n");
        printf("|                             5. Listar tudo                                    |\n");
        printf("|                             0. Voltar                                         |\n");
        printf("*-------------------------------------------------------------------------------*\n");
        printf("-- Sua opc: ");
        scanf("%d",&opc);
        getchar();
        fflush(stdin);
        switch (opc)
        {
        case 1:
            cad_quart();
            break;
        case 2:
            pesq_quart();
            break;
        case 3:
            edit_quart();
            break;
        case 4:
            del_quart();
            break;
        case 5:
            list_quart();
            break;
        case 6:
            monitoramento();
            break;
        }
    } while (opc!=0);
    
}
void cad_quart(void){
    system("clear||cls");
    Quarto* quart;
    char ide[10];
    quart = (Quarto*) malloc(sizeof(Quarto));
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Cadastrando novo quarto   .......                     \n");
    printf("*-------------------------------------------------------------------------------*\n");
    w_identificacao(ide);
    if(encont_quart(ide,'I')==0){
        strcpy(quart->identificacao,ide);
        w_descricao(quart->descricao);
        w_preco(&(quart->preco));
        printf("                    .......   Status do quarto   .......            \n");
        printf("|                             1. Disponivel                                     |\n");
        printf("|                             2. Manutencao                                     |\n");
        printf("|                             3. Limpando                                       |\n");
        w_status(&(quart->status));
        grava_quart(quart);
    }else{
        printf("- Quarto já cadastrado com essa identificacao!\n");
    }
    printf("*-------------------------------------------------------------------------------*\n");
    printf("\t>> Digite ENTER para prosseguir!");
    getchar();
}
void grava_quart(Quarto* quart){
    FILE* fp;
    fp = fopen("quartos.dat","ab");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo\n");
        exit(1);
    }
    fwrite(quart, sizeof(Quarto), 1, fp);
    fclose(fp);
}
void list_quart(void){
    FILE* fp;
    Quarto* quart;
    quart = (Quarto*) malloc(sizeof(Quarto));
    fp = fopen("quartos.dat", "rb");
    if (fp == NULL) {
        printf("Não foi possivel abrir o arquivo!");
        exit(1);
    }
    while(fread(quart,sizeof(Quarto), 1, fp)){
        if(quart->status!=0){
            most_quart(quart);
        }
    }
    free(quart);
    fclose(fp);
}
void most_quart(Quarto* quart){
    printf("Identificacao: %s\n", quart->identificacao);
    printf("Descrica: %s\n", quart->descricao);
    printf("Preco: %.2f\n", quart->preco);
    if(quart->status==1){
        printf("Status: Disponivel \n");
    }else if(quart->status==2){
        printf("Status: Manutencao \n");
    }else if(quart->status==3){
        printf("Status: Limpando \n");
    }else if(quart->status==4){
        printf("Status: Ocupado \n");
    }
    getchar();
}
void pesq_quart(void){
    char ide[10];
    system("clear||cls");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Pesquisando dados de quarto   .......                 \n");
    printf("*-------------------------------------------------------------------------------*\n");
    w_identificacao(ide);
    printf("                 .......   Resultados Encontrados   .......                      \n");
    encont_quart(ide,'M');
    printf("*-------------------------------------------------------------------------------*\n");
    printf("\t>> Digite ENTER para prosseguir!");
    getchar();
}
int encont_quart(char ide[], char ope){
    FILE* fp;
    Quarto* quart;
    int existe=0;
    quart = (Quarto*) malloc(sizeof(Quarto));
    fp = fopen("quartos.dat", "rb");
    if (fp == NULL) {
        fp = fopen("quartos.dat","ab");
    }
    while(fread(quart,sizeof(Quarto), 1, fp)){
        if (strcmp(quart->identificacao, ide)==0 && quart->status!=0) {
            if(ope=='M'){
                most_quart(quart);
            }
            existe=1;
        }
    }
    free(quart);
    fclose(fp);
    return existe;
}
void edit_quart(void){
    char ide[12];
    int opc;
    FILE* fp;
    Quarto* quart;
    quart = (Quarto*) malloc(sizeof(Quarto));
    fp = fopen("quartos.dat", "r+b");
    system("clear||cls");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Atualizando dados de quarto   .......                 \n");
    printf("*-------------------------------------------------------------------------------*\n");
    w_identificacao(ide);
    if(encont_quart(ide,'I')==1){
        if (fp == NULL) {
            printf("Não foi possivel abrir o arquivo!");
            exit(1);
        }
        while(fread(quart,sizeof(Quarto), 1, fp)){
            if (strcmp(quart->identificacao, ide)==0 && quart->status!=0){
                do {
                    printf("1 - Descricao: %s\n", quart->descricao);
                    printf("2 - Preco p/hora: %2.f\n", quart->preco);
                    printf("3 - Status: %d\n", quart->status);
                    printf("0 - Finalizar alteracoes.");
                    printf("\n -Campo que deseja editar:");
                    scanf("%d",&opc);
                    getchar();
                    fflush(stdin);
                    switch (opc)
                    {
                    case 1:
                        w_descricao(quart->descricao);
                        break;
                    case 2:
                        w_preco(&(quart->preco));
                        break;
                    case 3:
                        printf("                    .......   Status do quarto   .......            \n");
                        printf("|                             1. Disponivel                                     |\n");
                        printf("|                             2. Manutencao                                     |\n");
                        printf("|                             3. Limpando                                       |\n");
                        w_status(&(quart->status));
                        break;
                    }
                    fseek(fp, -1*(sizeof(Quarto)), SEEK_CUR);
                    fwrite(quart, sizeof(Quarto), 1, fp);
                }while (opc!=0);
                break;
            } 
        }
        free(quart);
        fclose(fp);
    }else{
        printf("- Quarto não encontrado!\n");
    }
    printf("*-------------------------------------------------------------------------------*\n");
    printf("\t>> Digite ENTER para prosseguir!");
    getchar();
}
void del_quart(void){
    system("clear||cls");
    char ide[10];
    Quarto* quart;
    FILE* fp;
    quart = (Quarto*) malloc(sizeof(Quarto));
    system("clear||cls");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Deletando dados de quarto   .......                   \n");
    printf("*-------------------------------------------------------------------------------*\n");
    w_identificacao(ide);
    fp = fopen("quartos.dat", "r+b");
    if (fp == NULL) {
        printf("Não foi possivel abrir o arquivo!");
    }
    if(encont_quart(ide,'I')==1){
        while(fread(quart,sizeof(Quarto), 1, fp)){
            if (strcmp(quart->identificacao, ide)==0) {
                quart->status = 0;
                fseek(fp, -1*(sizeof(Quarto)), SEEK_CUR);
                fwrite(quart, sizeof(Quarto), 1, fp);
                break;
            }
        }
    }else{
        printf("-Quarto nao encontrado");
    }
    fclose(fp);
    free(quart);
    printf("*-------------------------------------------------------------------------------*\n");
    printf("\t>> Digite ENTER para prosseguir!");
    getchar();
}
void monitoramento(void){
    int opc;
    do
    {
        system("clear||cls");
        printf("\n*-------------------------------------------------------------------------------*\n");
        printf("*                            Monitoramento(Ainda a ser desenvolvido)            *\n");
        printf("*-------------------------------------------------------------------------------*\n");
        printf("|                             1. Quartos disponiveis                            |\n");
        printf("|                             2. Quartos em manutencao                          |/\n");
        printf("|                             3. Quartos para limpar                            |\n");
        printf("|                             0. Voltar                                         |\n");
        printf("*-------------------------------------------------------------------------------*\n");
        printf("-- Sua opc: ");
        scanf("%d",&opc);
        getchar();
        fflush(stdin);
        switch (opc)
            {
            case 1:
                system("clear||cls");
                printf("*-------------------------------------------------------------------------------*\n");
                printf("                 .......   Listando quartos os disponiveis   .......                \n");
                printf("*-------------------------------------------------------------------------------*\n");
                printf("|   Identificacao           -    Preco por Hora                                 |\n");
                printf("*-------------------------------------------------------------------------------*\n");
                printf("|   27E                     -    R$ 55                                          |\n");
                printf("*-------------------------------------------------------------------------------*\n");
                printf("\t>> Digite ENTER para prosseguir!");
                getchar();
                break;
            case 2:
                system("clear||cls");
                printf("*-------------------------------------------------------------------------------*\n");
                printf("                 .......   Listando quartos em manutencao   .......              \n");
                printf("*-------------------------------------------------------------------------------*\n");
                printf("|   Identificacao           -    Preco por Hora                                 |\n");
                printf("*-------------------------------------------------------------------------------*\n");
                printf("|   27E                     -    R$ 55                                          |\n");
                printf("*-------------------------------------------------------------------------------*\n");
                printf("\t>> Digite ENTER para prosseguir!");
                getchar();
                break;
            case 3:
                system("clear||cls");
                printf("*-------------------------------------------------------------------------------*\n");
                printf("                 .......   Listando quartos para limpeza   .......              \n");
                printf("*-------------------------------------------------------------------------------*\n");
                printf("|   Identificacao           -    Preco por Hora                                 |\n");
                printf("*-------------------------------------------------------------------------------*\n");
                printf("|   27E                     -    R$ 55                                          |\n");
                printf("*-------------------------------------------------------------------------------*\n");
                printf("\t>> Digite ENTER para prosseguir!");
                getchar();
                break;
            }
    } while (opc!=0);
    
}