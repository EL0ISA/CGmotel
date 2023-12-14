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
    int id;
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
            if (cont_q()==0){
                    printf("Nao ha quartos ativas/cadastradas!");
            }else{
                do {
                    system("clear||cls");
                    list_quart('T');
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
            monitoramento();
            break;
        case 7:
            quart_cli();
            break;
        case 8:
            if (cont_q()==0){
                    printf("Nao ha quartos ativas/cadastradas!");
            }else{
                do {
                    system("clear||cls");
                    list_mais_reser();
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
void cad_quart(void){
    system("clear||cls");
    Quarto* quart;
    char ide[10];
    quart = (Quarto*) malloc(sizeof(Quarto));
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Cadastrando novo quarto   .......                     \n");
    printf("*-------------------------------------------------------------------------------*\n");
    w_identificacao(ide);
    strcpy(quart->identificacao,ide);
    w_descricao(quart->descricao);
    w_preco(&(quart->preco));
    printf("                    .......   Status do quarto   .......            \n");
    printf("|                             1. Disponivel                                     |\n");
    printf("|                             2. Manutencao                                     |\n");
    printf("|                             3. Limpando                                       |\n");
    w_status(&(quart->status));
    quart->id=criar_id_quar();
    grava_quart(quart);
    printf("*-------------------------------------------------------------------------------*\n");
    printf("\t>> Digite ENTER para prosseguir!");
    getchar();
}
void grava_quart(Quarto* quart){
    FILE* fp;
    fp = fopen("quartos.dat","ab");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo\n");
        return;
    }
    fwrite(quart, sizeof(Quarto), 1, fp);
    fclose(fp);
}
void list_quart(char ope){
    FILE* fp;
    Quarto* quart;
    quart = (Quarto*) malloc(sizeof(Quarto));
    fp = fopen("quartos.dat", "rb");
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
    bus_quart(ide);
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
        return;
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
            if (quart->id==reser->quarto && strcmp(reser->cliente, cli)==0) {
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
int cont_q(void){
    FILE* fp;
    Quarto* quart;
    quart = (Quarto*) malloc(sizeof(Quarto));
    fp = fopen("quartos.dat", "rb");
    int cont=0;
    if (fp == NULL) {
        return 0;
    }
    while(fread(quart,sizeof(Quarto), 1, fp)){
        if(quart->status!=0){
            cont++;
        }

    }
    return cont;
}
void bus_quart(char ide[]){
    FILE* fp;
    Quarto* quart;
    quart = (Quarto*) malloc(sizeof(Quarto));
    fp = fopen("quartos.dat", "rb");
    if (fp == NULL) {
        fp = fopen("quartos.dat","ab");
        return;
    }
    while(fread(quart,sizeof(Quarto), 1, fp)){
        if (strstr(quart->identificacao, ide) != NULL) {
            if(quart->status!=0){
                most_quart(quart);
            }
        }
    }
    free(quart);
    fclose(fp);
}
int encont_quart(int id, char ope){
    FILE* fp;
    Quarto* quart;
    int existe=0;
    quart = (Quarto*) malloc(sizeof(Quarto));
    fp = fopen("quartos.dat", "rb");
    if (fp == NULL) {
        fp = fopen("quartos.dat","ab");
    }
    while(fread(quart,sizeof(Quarto), 1, fp)){
        if (quart->id== id) {
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
    int opc;
    int id;
    FILE* fp;
    Quarto* quart;
    quart = (Quarto*) malloc(sizeof(Quarto));
    fp = fopen("quartos.dat", "r+b");
    system("clear||cls");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Atualizando dados de quarto   .......                 \n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("|            - Informe o ID do quarto:");
    scanf("%d",&id);
    if(encont_quart(id,'I')==2){
        if (fp == NULL) {
            printf("Não foi possivel abrir o arquivo!");
            exit(1);
        }
        while(fread(quart,sizeof(Quarto), 1, fp)){
            if (quart->id== id && quart->status!=0){
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
    int id;
    Quarto* quart;
    FILE* fp;
    quart = (Quarto*) malloc(sizeof(Quarto));
    system("clear||cls");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Deletando dados de quarto   .......                   \n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("|            - Informe o ID do quarto:");
    scanf("%d",&id);
    fp = fopen("quartos.dat", "r+b");
    if (fp == NULL) {
        printf("Não foi possivel abrir o arquivo!");
    }
    if(encont_quart(id,'I')==2){
        while(fread(quart,sizeof(Quarto), 1, fp)){
            if (quart->id== id) {
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
            if ((*list == NULL) || (cont_quart(quart->id)>cont_quart((*list)->id))) {
                quart->prox = *list;
                *list = quart;
            } else {
                Quarto* ant = *list;
                Quarto* at = (*list)->prox;
                while ((at != NULL) && (cont_quart(ant->id)>cont_quart(at->id))) {
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
int cont_quart(int quarto){
    FILE* fp;
    Quarto* quart;
    int existe=0;
    quart = (Quarto*) malloc(sizeof(Quarto));
    fp = fopen("quartos.dat", "rb");
    if (fp == NULL) {
        fp = fopen("quartos.dat","ab");
    }
    while(fread(quart,sizeof(Quarto), 1, fp)){
        if (quart->id==quarto) {
            FILE* fr;
            Reserva* reser;
            reser = (Reserva*) malloc(sizeof(Reserva));
            fr = fopen("reservas.dat", "rb");
            if (fr == NULL) {
                fr = fopen("reservas.dat","ab");
            }
            while(fread(reser,sizeof(Reserva), 1, fr)){
                if (reser->quarto==quarto) {
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
        printf("| %-15s - %-12.2f   -%-12d   |   \n", aux->identificacao, aux->preco,cont_quart(aux->id));
        aux =aux->prox;
	}
    getchar();
}
int criar_id_quar(void) {
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