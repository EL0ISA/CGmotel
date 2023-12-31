#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "reserva.h"
#include "auxiliares.h"
#include "quarto.h"
#include "funcionario.h"
#include "cliente.h"
#include "uteis.h"
void menu_reservas(void){
    int opc;
    int id;
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
        printf("|                             6. Reservas ordenas das mais recentes             |\n");
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
                if (reser_cont()==0){
                    printf("Nao ha reservas ativas/cadastradas!");
                }else{
                    do {
                        system("clear||cls");
                        printf("*-------------------------------------------------------------------------------*\n");
                        printf("                .......   Todas as reservas ativas   .......                      \n");
                        printf("*-------------------------------------------------------------------------------*\n");
                        list_reser('T');
                        printf("- Digite o ID que deseja ver mais infor ou 0 p/voltar:\n");
                        scanf("%d",&id);
                        getchar();
                        fflush(stdin);
                        if(bus_id_reser(id,'I')==1){
                            bus_id_reser(id,'M');
                        }else if(id!=0){
                            printf("Identificacao invalida!");
                            getchar();
                        }
                    } while (id!=0);
                }
                break;
            case 5:
                if (reser_cont()==0){
                    printf("Nao ha reservas ativas/cadastradas!");
                }else{
                    do {
                        system("clear||cls");
                        printf("*-------------------------------------------------------------------------------*\n");
                        printf("         .......   Todas as reservas que estao sem checkout   .......            \n");
                        printf("*-------------------------------------------------------------------------------*\n");
                        list_reser('A');
                        printf("- Digite o ID que deseja ver mais infor ou 0 p/voltar:\n");
                        scanf("%d",&id);
                        getchar();
                        fflush(stdin);
                        if(bus_id_reser(id,'I')==1){
                            bus_id_reser(id,'M');
                        }else if(id!=0){
                            printf("Identificacao invalida!");
                            getchar();
                        }
                    } while (id!=0);
                }
                break;
            case 6:
                if (reser_cont()==0){
                    printf("Nao ha reservas ativas/cadastradas!");
                }else{
                    do {
                        system("clear||cls");
                        printf("*-------------------------------------------------------------------------------*\n");
                        printf("       .......   Reservas ordenas a partir da mais recentes   .......            \n");
                        printf("*-------------------------------------------------------------------------------*\n");
                        list_mais_rec();
                        printf("- Digite o ID que deseja ver mais infor ou 0 p/voltar:\n");
                        scanf("%d",&id);
                        getchar();
                        fflush(stdin);
                        if(bus_id_reser(id,'I')==1){
                            bus_id_reser(id,'M');
                        }else if(id!=0){
                            printf("Identificacao invalida!");
                            getchar();
                        }
                    } while (id!=0);
                }
                break;
            case 7:
                if (reser_cont()==0){
                        printf("Nao ha reservas ativas/cadastradas!");
                    }else{
                        do {
                            system("clear||cls");
                            printf("*-------------------------------------------------------------------------------*\n");
                            printf("       .......   Reservas do dia   .......            \n");
                            printf("*-------------------------------------------------------------------------------*\n");
                            list_reser('D');
                            printf("- Digite o ID que deseja ver mais infor ou 0 p/voltar:\n");
                            scanf("%d",&id);
                            getchar();
                            fflush(stdin);
                            if(bus_id_reser(id,'I')==1){
                                bus_id_reser(id,'M');
                            }else if(id!=0){
                                printf("Identificacao invalida!");
                                getchar();
                            }
                        } while (id!=0);
                    }
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
        if (reser->id==id && reser->status=='A' && (reser->func_out==NULL || strcmp(reser->func_out,"")==0)) {
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
    int quarto;
    char funcionario[12];
    int quart_dis=0;
    Reserva* reser;
    reser = (Reserva*) malloc(sizeof(Reserva));
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Cadastrando nova reserva   .......                    \n");
    printf("*-------------------------------------------------------------------------------*\n");
    w_cliente(cliente);
    if(encont_cli(cliente,'I')==2){
        if(cli_out(cliente)==0){
            strcpy(reser->cliente,cliente);
            printf("|            - Informe o ID do quarto:");
            scanf("%d",&quarto);
            getchar();
            fflush(stdin);
            if(encont_quart(quarto,'I')==2){
                FILE* fp;
                Quarto* quart;
                quart = (Quarto*) malloc(sizeof(Quarto));
                fp = fopen("quartos.dat", "rb");
                    while(fread(quart,sizeof(Quarto), 1, fp)){
                        if (quart->id==quarto && quart->status==1) {
                            reser->quarto=quarto;
                            quart_dis=1;
                            w_horas(&(reser->horas));
                            w_obs(reser->obs);
                            w_padd(&(reser->padd));
                            reser->ptotal= ((quart->preco)*(reser->horas))+ reser->padd;
                            printf("*-------------------------------------------------------------------------------*\n");
                            printf("                 .......   Realizando Check-in   .......                         \n");
                            printf("*-------------------------------------------------------------------------------*\n");
                            w_funcionario(funcionario);
                            if(encont_func(funcionario,'I')==2){
                                strcpy(reser->func_in,funcionario);
                                reser->status='A';
                                reser->id=criar_id();
                                data_hora(reser->hora_in, sizeof(reser->hora_in));
                                status_quart(quarto,4);
                                strcpy(reser->func_out,"");
                                // reser->hora_out=NULL;
                                grava_reser(reser);
                            }else{
                                printf("- Funcionario nao encontrado!\n");
                            }
                            break;
                        }
                    }
                free(quart);
                if(quart_dis==0){
                    printf("- Quarto nao disponivel!\n");
                }
            }else{
                printf("- Quarto nao encontrado!\n");
            }
        }
    }else{
        printf("- Cliente nao encontrado!\n");
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
int reser_cont(void){
    FILE* fp;
    Reserva* reser;
    reser = (Reserva*) malloc(sizeof(Reserva));
    fp = fopen("reservas.dat", "rb");
    int cont=0;
    if (fp == NULL) {
        return 0;
    }
    while(fread(reser,sizeof(Reserva), 1, fp)){
        if(reser->status!='I'){
            cont++;
        }

    }
    return cont;
}
void list_reser(char ope){
    FILE* fp;
    Reserva* reser;
    reser = (Reserva*) malloc(sizeof(Reserva));
    fp = fopen("reservas.dat", "rb");
    int day,month,year;
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
                FILE* fp;
                Cliente* cli;
                cli = (Cliente*) malloc(sizeof(Cliente));
                fp = fopen("clientes.dat", "rb");
                while(fread(cli,sizeof(Cliente), 1, fp)){
                    if (strcmp(reser->cliente,cli->cpf)==0) {
                        FILE* fp;
                        Quarto* quart;
                        quart = (Quarto*) malloc(sizeof(Quarto));
                        fp = fopen("quartos.dat", "rb");
                        while(fread(quart,sizeof(Quarto), 1, fp)){
                            if (reser->quarto==quart->id) {
                                printf("| %-6d - %-15s        -%-15s           -%-17.2f |   \n", reser->id,quart->identificacao,cli->nome,reser->ptotal);
                            }
                        }
                    }
                }
            }
        }
        if(ope=='A'){
            if(reser->func_out==NULL || strcmp(reser->func_out,"")==0){
                FILE* fp;
                Cliente* cli;
                cli = (Cliente*) malloc(sizeof(Cliente));
                fp = fopen("clientes.dat", "rb");
                while(fread(cli,sizeof(Cliente), 1, fp)){
                    if (strcmp(reser->cliente,cli->cpf)==0) {
                        FILE* fp;
                        Quarto* quart;
                        quart = (Quarto*) malloc(sizeof(Quarto));
                        fp = fopen("quartos.dat", "rb");
                        while(fread(quart,sizeof(Quarto), 1, fp)){
                            if (reser->quarto==quart->id) {
                                printf("| %-6d - %-15s        -%-15s           -%-17.2f |   \n", reser->id,quart->identificacao,cli->nome,reser->ptotal);
                            }
                        }
                    }
                }
            }
        }
        if(ope=='D'){
            sscanf(reser->hora_in,"%d-%*d-%*d", &day);
            sscanf(reser->hora_in,"%*d-%d", &month);
            sscanf(reser->hora_in,"%*d-%*d-%d", &year);
            time_t t = time(NULL);
            struct tm tm = *localtime(&t);
            if(day==(tm.tm_mday) && month==(tm.tm_mon+1)&&year==(tm.tm_year+1900)){
                FILE* fp;
                Cliente* cli;
                cli = (Cliente*) malloc(sizeof(Cliente));
                fp = fopen("clientes.dat", "rb");
                while(fread(cli,sizeof(Cliente), 1, fp)){
                    if (strcmp(reser->cliente,cli->cpf)==0) {
                        FILE* fp;
                        Quarto* quart;
                        quart = (Quarto*) malloc(sizeof(Quarto));
                        fp = fopen("quartos.dat", "rb");
                        while(fread(quart,sizeof(Quarto), 1, fp)){
                            if (reser->quarto==quart->id) {
                                printf("| %-6d - %-15s        -%-15s           -%-17.2f |   \n", reser->id,quart->identificacao,cli->nome,reser->ptotal);
                            }
                        }
                    }
                }
            }
        }
    }
    free(reser);
    fclose(fp);
}
void most_reser(Reserva* reser){
    printf("\n*-------------------------------------------------------------------------------*\n");
    printf("ID: %d\n", reser->id);
    printf("Cliente: %s\n", reser->cliente);
    printf("Quarto: %d\n", reser->quarto);
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
                if(encont_func(funcionario,'I')==2){
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
        return;
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
void status_quart(int id,int ope){
    Quarto* quart;
    FILE* fp;
    quart = (Quarto*) malloc(sizeof(Quarto));
    fp = fopen("quartos.dat", "r+b");
        while(fread(quart,sizeof(Quarto), 1, fp)){
            if (quart->id== id) {
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
time_t data_form(char *data){
    struct tm tm_result;
    int day, month, year, hour, min, sec;
    sscanf(data,"%d-%*d-%*d", &day);
    sscanf(data,"%*d-%d", &month);
    sscanf(data,"%*d-%*d-%d", &year);
    sscanf(data,"%*d-%*d-%*d %d:%d:%d", &hour, &min, &sec);
    tm_result.tm_mday = day;
    tm_result.tm_mon = month - 1;  // Mês é indexado de 0 a 11
    tm_result.tm_year = year - 1900;  // Ano é contado a partir de 1900
    tm_result.tm_hour = hour;
    tm_result.tm_min = min;
    tm_result.tm_sec = sec;
    return mktime(&tm_result);
}
void list_mais_rec(void){
    Reserva *list;
    list = NULL;
    gerar_mais_rec(&list);
    exibir_mais_rec(list);
    del_mais_rec(&list);
}
void gerar_mais_rec(Reserva **list){
    FILE *fp;
    Reserva *reser;
    del_mais_rec(&(*list));
    *list = NULL;
    fp = fopen("reservas.dat","rb");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo... \n");
        return;
    } else {
        reser = (Reserva*) malloc(sizeof(Reserva));
        
        while (fread(reser, sizeof(Reserva), 1, fp)) {
            if ((*list == NULL) || reser->id> (*list)->id) {
                reser->prox = *list;
                *list = reser;
            } else {
                Reserva* ant = *list;
                Reserva* at = (*list)->prox;
                while ((at != NULL) && ant->id > at->id) {
                    ant = at;
                    at = at->prox;
                }
                ant->prox = reser;
                reser->prox = at;
            }
            reser = (Reserva*) malloc(sizeof(Reserva));
        }
        free(reser);
        fclose(fp);
    } 
}
void del_mais_rec(Reserva **list){
    Reserva*reser;
    while (*list != NULL) {
        reser = *list;
        *list = (*list)->prox;
        free(reser);
    }  
}
void exibir_mais_rec(Reserva *aux){
    printf("*-------------------------------------------------------------------------------*\n");
    printf("| ID      - Quarto               -    Cliente               - Data de checkin   |\n");
    printf("*-------------------------------------------------------------------------------*\n");
    while (aux != NULL) {
        FILE* fp;
        Cliente* cli;
        cli = (Cliente*) malloc(sizeof(Cliente));
        fp = fopen("clientes.dat", "rb");
        while(fread(cli,sizeof(Cliente), 1, fp)){
            if (strcmp(aux->cliente,cli->cpf)==0) {
                FILE* fp;
                Quarto* quart;
                quart = (Quarto*) malloc(sizeof(Quarto));
                fp = fopen("quartos.dat", "rb");
                while(fread(quart,sizeof(Quarto), 1, fp)){
                    if (aux->quarto==quart->id) {
                        printf("| %-6d - %-15s     -%-15s           -%-20s |   \n", aux->id,quart->identificacao,cli->nome,aux->hora_in);
                    }
                }
            }
        }
        aux =aux->prox;
	}
}