//criar id.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "quarto.h"
#include "reserva.h"
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
        printf("|                             6. Monitoramento                                  |\n");
        printf("|                             7. Quartos por cliente                            |\n");
        printf("|                             8. Quartos ordenados por mais reservas            |\n");
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
            list_quart('T');
            break;
        case 6:
            monitoramento();
            break;
        case 7:
            quart_cli();
            break;
        case 8:
            list_mais_reser();
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
    }else if(encont_quart(ide,'I')==1){
        int op=-1;
        printf("-- Um quarto desativado com esse ID ja cadastrado\n");
        printf("-- Deseja reativa-lo:");
        printf("1- Sim");
        printf("2- Nao");
        scanf("%d",&op);
        if(op==1){
            status_quart(ide,1);
        }
    }
    else{
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
void list_quart(char ope){
    FILE* fp;
    Quarto* quart;
    quart = (Quarto*) malloc(sizeof(Quarto));
    fp = fopen("quartos.dat", "rb");
    char ide[10];
    if (fp == NULL) {
        printf("Não foi possivel abrir o arquivo!");
        getchar();
        return;
    }
    if(ope=='T'){
        printf("*-------------------------------------------------------------------------------*\n");
        printf("                     .......   Todos os quartos   .......                     \n");
    }
    printf("*-------------------------------------------------------------------------------*\n");
    printf("|   Identificacao               -    Preco por Hora                             |\n");
    printf("*-------------------------------------------------------------------------------*\n");
    while(fread(quart,sizeof(Quarto), 1, fp)){
        if(ope=='T'){
            if(quart->status!=0){
                printf("|        %-20s -      %-42.2f |   \n", quart->identificacao, quart->preco);
            }
        }
        if(ope=='D'){
            if(quart->status==1){
                printf("|        %-20s -      %-42.2f |   \n", quart->identificacao, quart->preco);
            }
        }
        if(ope=='M'){
            if(quart->status==2){
                printf("|        %-20s -      %-42.2f |   \n", quart->identificacao, quart->preco);
            }
        }
        if(ope=='L'){
            if(quart->status==3){
                printf("|        %-20s -      %-42.2f |   \n", quart->identificacao, quart->preco);
            }
        }
    }
    do
    {
        printf("- Digite a identificacao do quarto que deseja ver mais infor ou 0 p/voltar:\n");
        scanf("%[^\n]",ide);
        getchar();
        fflush(stdin);
        if(encont_quart(ide,'I')==2){
            encont_quart(ide,'M');
        }else{
            printf("Identificacao invalida!");
            getchar();
        }
    } while (strcmp(ide,"0")!=0);
    free(quart);
    fclose(fp);
}
void most_quart(Quarto* quart){
    printf("                 .......   Dados do Quarto   .......                 \n");
    printf("Identificacao: %s\n", quart->identificacao);
    printf("Descricacao: %s\n", quart->descricao);
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
void quart_cli(void){
    char cli[12];
    system("clear||cls");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("              .......   Listar quartos alugados por cliente   .......            \n");
    printf("*-------------------------------------------------------------------------------*\n");
    w_cliente(cli);
    printf("                 .......   Resultados Encontrados   .......                      \n");
    FILE* fp;
    Quarto* quart;
    quart = (Quarto*) malloc(sizeof(Quarto));
    fp = fopen("quartos.dat", "rb");
    if (fp == NULL) {
        fp = fopen("quartos.dat","ab");
    }
    FILE* fr;
    Reserva* reser;
    reser = (Reserva*) malloc(sizeof(Reserva));
    fr = fopen("reservas.dat", "rb");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("| ID reserva                  - Quarto                  - Data                  |\n");
    printf("*-------------------------------------------------------------------------------*\n");
    while(fread(quart,sizeof(Quarto), 1, fp)){
        while (fread(reser, sizeof(Reserva), 1, fr)){
            if (strcmp(quart->identificacao, reser->quarto)==0 && strcmp(reser->cliente, cli)==0) {
                printf("|   %-6d                    - %-10s          -%-10s        |   \n", reser->id,quart->identificacao,reser->hora_in);
            }
        }
    }
    free(quart);
    fclose(fp);
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
        if (strcmp(quart->identificacao, ide)==0) {
            existe=1;
            if(quart->status!=0){
                if(ope=='M'){
                    most_quart(quart);
                }
                existe=2; //existe e esta ativo   
            }
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
    if(encont_quart(ide,'I')==2){
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
    if(encont_quart(ide,'I')==2){
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
                list_quart('D');
                printf("\t>> Digite ENTER para prosseguir!");
                getchar();
                break;
            case 2:
                system("clear||cls");
                printf("*-------------------------------------------------------------------------------*\n");
                printf("                 .......   Listando quartos em manutencao   .......              \n");
                list_quart('M');
                printf("\t>> Digite ENTER para prosseguir!");
                getchar();
                break;
            case 3:
                system("clear||cls");
                printf("*-------------------------------------------------------------------------------*\n");
                printf("                 .......   Listando quartos para limpeza   .......              \n");
                list_quart('L');
                printf("\t>> Digite ENTER para prosseguir!");
                getchar();
                break;
            }
    } while (opc!=0);
    
}
void list_mais_reser(void){
    Quarto *list;
    list = NULL;
    gerar_mais_reser(&list);
    exibir_mais_reser(list);
    del_mais_reser(&list);
}
void gerar_mais_reser(Quarto **list){
    FILE *fp;
    Quarto *quart;
    del_mais_reser(&(*list));
    *list = NULL;
    fp = fopen("quartos.dat","rb");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo... \n");
        return;
    } else {
        quart = (Quarto*) malloc(sizeof(Quarto));
        while (fread(quart, sizeof(Quarto), 1, fp)) {
            if ((*list == NULL) || (cont_quart(quart->identificacao)>cont_quart((*list)->identificacao))) {
                quart->prox = *list;
                *list = quart;
            } else {
                Quarto* ant = *list;
                Quarto* at = (*list)->prox;
                while ((at != NULL) && (cont_quart(ant->identificacao)>cont_quart(at->identificacao))) {
                    ant = at;
                    at = at->prox;
                }
                ant->prox = quart;
                quart->prox = at;
            }
            quart = (Quarto*) malloc(sizeof(Quarto));
        }
        free(quart);
        fclose(fp);
    } 
}
int cont_quart(char quarto[]){
    FILE* fp;
    Quarto* quart;
    int existe=0;
    quart = (Quarto*) malloc(sizeof(Quarto));
    fp = fopen("quartos.dat", "rb");
    if (fp == NULL) {
        fp = fopen("quartos.dat","ab");
    }
    while(fread(quart,sizeof(Quarto), 1, fp)){
        if (strcmp(quart->identificacao,quarto)==0) {
            FILE* fr;
            Reserva* reser;
            reser = (Reserva*) malloc(sizeof(Reserva));
            fr = fopen("reservas.dat", "rb");
            if (fr == NULL) {
                fr = fopen("reservas.dat","ab");
            }
            while(fread(reser,sizeof(Reserva), 1, fr)){
                if (strcmp(reser->quarto, quarto)==0) {
                    existe=existe+1;
                }
            }
            free(reser);
            fclose(fr);
        }
    }
    free(quart);
    fclose(fp);
    return existe;
}
void del_mais_reser(Quarto **list){
    Quarto*quart;
    while (*list != NULL) {
        quart = *list;
        *list = (*list)->prox;
        free(quart);
    }  
}
void exibir_mais_reser(Quarto *aux){
    while (aux != NULL) {
        printf("| %-15s - %-12.2f   -%-12d   |   \n", aux->identificacao, aux->preco,cont_quart(aux->identificacao));
        aux =aux->prox;
	}
    getchar();
}