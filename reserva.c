#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reserva.h"
#include "auxiliares.h"
#include "quarto.h"
#include "funcionario.h"
#include "cliente.h"
#include "uteis.h"
void menu_reservas(void){
    int opc;
    do
    {
        system("clear||cls");
        printf("\n*-------------------------------------------------------------------------------*\n");
        printf("*                               Menu Reservas                                   *\n");
        printf("*-------------------------------------------------------------------------------*\n");
        printf("|                             1. Check-in                                       |\n");
        printf("|                             2. Pesquisar                                      |\n");
        printf("|                             3. Check-out                                      |\n");
        printf("|                             4. Listar tudo                                    |\n");
        printf("|                             5. Reservas sem Checkout                          |\n");
        printf("|                             0. Voltar                                         |\n");
        printf("*-------------------------------------------------------------------------------*\n");
        printf("-- Sua opc: ");
        scanf("%d",&opc);
        getchar();
        fflush(stdin);
        switch (opc)
            {
            case 1:
                checkin();
                break;
            case 2:
                pesq_reser();
                break;
            case 3:
                checkout();
                break;
            case 4:
                list_reser('T');
                break;
            case 5:
                list_reser('A');
                break;
            }
    } while (opc!=0);
    
}
void pesq_reser(void){
    system("clear||cls");
    char cliente[12];
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Pesquisando dados de reserva   .......                \n");
    printf("*-------------------------------------------------------------------------------*\n");
    w_cliente(cliente);
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Resultados Encontrados   .......                      \n");
    encont_reser(cliente);
    printf("\t>> Digite ENTER para prosseguir!");
    getchar();
}
void encont_reser(char cliente[]){
    FILE* fp;
    Reserva* reser;
    reser= (Reserva*) malloc(sizeof(Reserva));
    fp = fopen("reservas.dat", "rb");
    if (fp == NULL) {
        printf("Não foi possivel abrir o arquivo!");
        exit(1);
    }
    while(fread(reser,sizeof(Reserva), 1, fp)){
        if (strcmp(reser->cliente, cliente)==0 && reser->status=='A') {
            most_reser(reser);
        }
    }
    free(reser);
    fclose(fp);
}
int bus_id_reser(int id, char ope){
    FILE* fp;
    Reserva* reser;
    reser= (Reserva*) malloc(sizeof(Reserva));
    fp = fopen("reservas.dat", "rb");
    if (fp == NULL) {
        printf("Não foi possivel abrir o arquivo!");
    }
    while(fread(reser,sizeof(Reserva), 1, fp)){
        if (reser->id== id && reser->status=='A' && reser->status=='A' && (reser->func_out==NULL || strcmp(reser->func_out,"")==0)) {
            if(ope=='M'){
                most_reser(reser);
            }
            free(reser);
            fclose(fp);
            return 1;
        }
    }
    free(reser);
    fclose(fp);
    return 0;
}
void checkin(void){
    system("clear||cls");
    char cliente[12];
    char quarto[10];
    char funcionario[12];
    int quart_dis=0;
    Reserva* reser;
    reser = (Reserva*) malloc(sizeof(Reserva));
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Cadastrando nova reserva   .......                    \n");
    printf("*-------------------------------------------------------------------------------*\n");
    w_cliente(cliente);
    if(encont_cli(cliente,'I')==1){
        if(cli_out(cliente)==0){
            strcpy(reser->cliente,cliente);
            w_quarto(quarto);
            if(encont_quart(quarto,'I')==1){
                FILE* fp;
                Quarto* quart;
                quart = (Quarto*) malloc(sizeof(Quarto));
                fp = fopen("quartos.dat", "rb");
                    while(fread(quart,sizeof(Quarto), 1, fp)){
                        if (strcmp(quart->identificacao,quarto)==0 && quart->status==1) {
                            strcpy(reser->quarto,quarto);
                            quart_dis=1;
                            w_horas(&(reser->horas));
                            w_obs(reser->obs);
                            w_padd(&(reser->padd));
                            reser->ptotal= ((quart->preco)*(reser->horas))+ reser->padd;
                            printf("*-------------------------------------------------------------------------------*\n");
                            printf("                 .......   Realizando Check-in   .......                         \n");
                            printf("*-------------------------------------------------------------------------------*\n");
                            w_funcionario(funcionario);
                            if(encont_func(funcionario,'I')==1){
                                strcpy(reser->func_in,funcionario);
                                reser->status='A';
                                reser->id=criar_id();
                                data_hora(reser->hora_in, sizeof(reser->hora_in));
                                status_quart(quarto,4);
                                grava_reser(reser);
                            }else{
                                printf("- Funcionario nao encontrado!");
                            }
                            break;
                        }
                    }
                free(quart);
                if(quart_dis==0){
                    printf("- Quarto nao disponivel!");
                }
            }else{
                printf("- Quarto nao encontrado!");
            }
        }
    }else{
        printf("- Cliente nao encontrado!");
    }
    printf("\n*-------------------------------------------------------------------------------*\n");
    printf("\t>> Digite ENTER para prosseguir!");
    free(reser);
    getchar();
}
void grava_reser(Reserva* reser){
    FILE* fp;
    fp = fopen("reservas.dat","ab");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo\n");
        return;
    }
    fwrite(reser, sizeof(Reserva), 1, fp);
    fclose(fp);
}
void list_reser(char ope){
    int id;
    FILE* fp;
    Reserva* reser;
    reser = (Reserva*) malloc(sizeof(Reserva));
    fp = fopen("reservas.dat", "rb");
    if (fp == NULL) {
        printf("Nao ha reservas cadastradas!\n");
        getchar();
        return;
    }
    printf("*-------------------------------------------------------------------------------*\n");
    printf("| ID      - Quarto               -    Cliente               - Custo total       |\n");
    printf("*-------------------------------------------------------------------------------*\n");
    while(fread(reser,sizeof(Reserva), 1, fp)){
        if(ope=='T'){
            if(reser->status!='I'){
                printf("| %-6d - %-10s        -%-15s           -%-20.2f |   \n", reser->id,reser->quarto,reser->cliente,reser->ptotal);
            }
        }
        if(ope=='A'){
            if(reser->func_out==NULL || strcmp(reser->func_out,"")==0){
                printf("| %-6d - %-10s        -%-15s           -%-20.2f |   \n", reser->id,reser->quarto,reser->cliente,reser->ptotal);
            }
        }
    }
    do
    {
        printf("- Digite o ID que deseja ver mais infor ou 0 p/voltar:\n");
        scanf("%d",&id);
        getchar();
        fflush(stdin);
        if(bus_id_reser(id,'I')==1){
            bus_id_reser(id,'M');
        }else{
            printf("Identificacao invalida!");
            getchar();
        }
    } while (id!=0);
    free(reser);
    fclose(fp);
}
void most_reser(Reserva* reser){
    printf("\n*-------------------------------------------------------------------------------*\n");
    printf("ID: %d\n", reser->id);
    printf("Cliente: %s\n", reser->cliente);
    printf("Quarto: %s\n", reser->quarto);
    printf("Observacao: %s\n", reser->obs);
    printf("Preco adicional: %.2f\n", reser->padd);
    printf("Horas de reserva: %d\n", reser->horas);
    printf("Total a pagar: %.2f\n", reser->ptotal);
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Informacoes Check-in   .......                        \n");
    printf("Funcionario: %s\n", reser->func_in);
    printf("Data e horario: %s\n", reser->hora_in);
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Informacoes Check-out   .......                        \n");
    printf("Funcionario: %s\n", reser->func_out);
    printf("Data e horario: %s\n",reser->hora_out);
    getchar();
}
void checkout(void){
    int id;
    FILE* fp;
    char funcionario[12];
    Reserva* reser;
    reser = (Reserva*) malloc(sizeof(Reserva));
    fp = fopen("reservas.dat", "r+b");
    system("clear||cls");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Realizando Check-out   .......                        \n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("|            - Informe o ID da reserva:");
    scanf("%d",&id);
    getchar();
    fflush(stdin);
    if (fp == NULL) {
        printf("Não foi possivel abrir o arquivo!");
    }
    if (bus_id_reser(id,'I')==1){
        while(fread(reser,sizeof(Reserva), 1, fp)){
            if (reser->id== id && reser->status=='A') {
                printf("*-------------------------------------------------------------------------------*\n");
                w_funcionario(funcionario);
                if(encont_func(funcionario,'I')==1){
                    strcpy(reser->func_out,funcionario);
                    data_hora(reser->hora_out, sizeof(reser->hora_out));
                    fseek(fp, -1*(sizeof(Reserva)), SEEK_CUR);
                    fwrite(reser, sizeof(Reserva), 1, fp);
                    status_quart(reser->quarto,3);
                }else{
                    printf("\n-Funcionario nao encontrado!");
                }
                break;
            }
        }
    }else{
        printf("\n-Essa reserva ja teve seu checkout realizado!");
    }
    free(reser);
    fclose(fp);
    printf("*-------------------------------------------------------------------------------*\n");
    printf("\t>> Digite ENTER para prosseguir!");
    getchar();
}
int cli_out(char cliente[]){
    FILE* fp;
    Cliente* cli;
    int existe=0;
    cli = (Cliente*) malloc(sizeof(Cliente));
    fp = fopen("clientes.dat", "rb");
    if (fp == NULL) {
        fp = fopen("clientes.dat","ab");
    }
    while(fread(cli,sizeof(Cliente), 1, fp)){
        if (strcmp(cli->cpf,cliente)==0 && cli->status=='A') {
            FILE* fr;
            Reserva* reser;
            reser = (Reserva*) malloc(sizeof(Reserva));
            fr = fopen("reservas.dat", "rb");
            if (fr == NULL) {
                fr = fopen("reservas.dat","ab");
            }
            while(fread(reser,sizeof(Reserva), 1, fr)){
                if (strcmp(reser->cliente, cliente)==0 && (reser->func_out==NULL || strcmp(reser->func_out,"")==0)) {
                    printf("- Esse cliente ainda conta com checkin ativo");
                    existe=1;
                }
            }
            free(reser);
            fclose(fr);
        }
    }
    free(cli);
    fclose(fp);
    return existe;
}
void del_reser(void){
    int id;
    FILE* fp;
    Reserva* reser;
    reser = (Reserva*) malloc(sizeof(Reserva));
    fp = fopen("reservas.dat", "r+b");
    system("clear||cls");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Deletando dados de reserva   .......                  \n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("|            - Informe o ID da reserva:");
    scanf("%d",&id);
    getchar();
    fflush(stdin);
    if (fp == NULL) {
        printf("Não foi possivel abrir o arquivo!");
        exit(1);
    }
    if(bus_id_reser(id,'I')==1){
        while(fread(reser,sizeof(Reserva), 1, fp)){
            if (reser->id== id && reser->status=='A') {
                reser->status='I';
                fseek(fp, -1*(sizeof(Reserva)), SEEK_CUR);
                fwrite(reser, sizeof(Reserva), 1, fp);
            }
        }
    }
    free(reser);
    fclose(fp);
    printf("*-------------------------------------------------------------------------------*\n");
    printf("\t>> Digite ENTER para prosseguir!");
    getchar();
}
void status_quart(char ide[],int ope){
    Quarto* quart;
    FILE* fp;
    quart = (Quarto*) malloc(sizeof(Quarto));
    fp = fopen("quartos.dat", "r+b");
        while(fread(quart,sizeof(Quarto), 1, fp)){
            if (strcmp(quart->identificacao, ide)==0) {
                quart->status = ope;
                fseek(fp, -1*(sizeof(Quarto)), SEEK_CUR);
                fwrite(quart, sizeof(Quarto), 1, fp);
                break;
            }
        }
    fclose(fp);
    free(quart);
}
//Feito com a ajuda do Chat Gpt e com Consultas no site StackOverflow 
//Adapatado por Maria Eloisa e Matheus Diniz 
int criar_id(void) {
    FILE *arquivo = fopen("reservas.dat", "rb");
    if (arquivo == NULL){
        return 1;
    }
    fseek(arquivo, 0, SEEK_END);
    if ((long)ftell(arquivo)==0){
        fclose(arquivo);
        return 1;
    } else {
        fseek(arquivo, -((long)sizeof(Reserva)), SEEK_END);
        Reserva ultstruct;
        fread(&ultstruct, sizeof(Reserva), 1, arquivo);
        int id = ultstruct.id + 1; 
        fclose(arquivo);
        return id;
    } 
} 