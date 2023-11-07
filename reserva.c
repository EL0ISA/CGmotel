#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reserva.h"
#include "auxiliares.h"
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
        printf("|                             4. Deletar reserva                                |\n");
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
                del_reser();
                break;
            case 5:
                list_reser();
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
int bus_id_reser(int id){
    FILE* fp;
    Reserva* reser;

    reser= (Reserva*) malloc(sizeof(Reserva));
    fp = fopen("reservas.dat", "rb");
    if (fp == NULL) {
        printf("Não foi possivel abrir o arquivo!");
        exit(1);
    }
    while(fread(reser,sizeof(Reserva), 1, fp)){
        if (reser->id== id && reser->status=='A' && reser->status=='A' && (reser->func_out==NULL || strcmp(reser->func_out,"")==0)) {
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
    Reserva* reser;
    reser = (Reserva*) malloc(sizeof(Reserva));
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Cadastrando nova reserva   .......                    \n");
    printf("*-------------------------------------------------------------------------------*\n");
    w_cliente(reser->cliente);
    w_quarto(reser->quarto);
    w_horas(&(reser->horas));
    w_obs(reser->obs);
    w_padd(&(reser->padd));
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Realizando Check-in   .......                         \n");
    printf("*-------------------------------------------------------------------------------*\n");
    w_funcionario(reser->func_in);
    reser->status='A';
    reser->id=criar_id();
    data_hora(reser->hora_in, sizeof(reser->hora_in));
    printf("*-------------------------------------------------------------------------------*\n");
    printf("\t>> Digite ENTER para prosseguir!");
    grava_reser(reser);
    free(reser);
    getchar();
}
void grava_reser(Reserva* reser){
    FILE* fp;
    fp = fopen("reservas.dat","ab");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo\n");
        exit(1);
    }
    fwrite(reser, sizeof(Reserva), 1, fp);
    fclose(fp);
}
void list_reser(void){
    FILE* fp;
    Reserva* reser;
    reser = (Reserva*) malloc(sizeof(Reserva));
    fp = fopen("reservas.dat", "rb");
    if (fp == NULL) {
        printf("Não foi possivel abrir o arquivo!\n");
    }
    while(fread(reser,sizeof(Reserva), 1, fp)){
        if(reser->status!='I'){
            most_reser(reser);
        }
    }
    free(reser);
    fclose(fp);
}
void most_reser(Reserva* reser){
    printf("ID: %d\n", reser->id);
    printf("Cliente: %s\n", reser->cliente);
    printf("Quarto: %s\n", reser->quarto);
    printf("Observacao: %s\n", reser->obs);
    printf("Preco adicional: %f\n", reser->padd);
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
        exit(1);
    }
    if (bus_id_reser(id)==1){
        while(fread(reser,sizeof(Reserva), 1, fp)){
            if (reser->id== id && reser->status=='A') {
                printf("*-------------------------------------------------------------------------------*\n");
                w_funcionario(reser->func_out);
                data_hora(reser->hora_out, sizeof(reser->hora_out));
                fseek(fp, -1*(sizeof(Reserva)), SEEK_CUR);
                fwrite(reser, sizeof(Reserva), 1, fp);
            }
        }
    }else{
        printf("\nEssa reserva ja teve seu checkout realizado");
    }
    free(reser);
    fclose(fp);
    printf("*-------------------------------------------------------------------------------*\n");
    printf("\t>> Digite ENTER para prosseguir!");
    getchar();
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
    fflush(stdin);
    if (fp == NULL) {
        printf("Não foi possivel abrir o arquivo!");
        exit(1);
    }
    while(fread(reser,sizeof(Reserva), 1, fp)){
        if (reser->id== id && reser->status=='A') {
            reser->status='I';
            fseek(fp, -1*(sizeof(Reserva)), SEEK_CUR);
            fwrite(reser, sizeof(Reserva), 1, fp);
        }  
    }
    free(reser);
    fclose(fp);
    printf("*-------------------------------------------------------------------------------*\n");
    printf("\t>> Digite ENTER para prosseguir!");
    getchar();
}
//Feito com a ajuda do Chat Gpt e com Consultas no site StackOverflow 
//Adapatado por Maria Eloisa e Matheus Diniz 
int criar_id(void) {
    FILE *arquivo = fopen("reserva.dat", "rb");
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