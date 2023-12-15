#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "cliente.h"
#include "reserva.h"
#include "auxiliares.h"
#include "uteis.h"

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
        printf("|                             5. Relatorios                                     |\n");
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
            system("clear||cls");
            printf("*-------------------------------------------------------------------------------*\n");
            printf("                 .......   Deletando cliente   .......                           \n");
            printf("*-------------------------------------------------------------------------------*\n");
            w_cpf(cpf);
            del_cli(cpf);
            break;
        case 5:
            relatorios_cli();
            break;
        }
    } while (opc!=0);
}
void relatorios_cli(void){
    int op;
    do
    {
        system("clear||cls");
        printf("*-------------------------------------------------------------------------------*\n");
        printf("*                               Relatorios Clientes                             *\n");
        printf("*-------------------------------------------------------------------------------*\n");
        printf("|                             1. Listar todos                                   |\n");
        printf("|                             2. Aniversariantes do mes                         |\n");
        printf("|                             3. Ordem Alfabetica                               |\n");
        printf("|                             4. Ordem por mais reservas                        |\n");
        printf("|                             0. Voltar                                         |\n");
        printf("*-------------------------------------------------------------------------------*\n");
        printf("-- Sua opc: ");
        scanf("%d", &op);
        getchar();
        fflush(stdin);
        switch (op)
        {
        case 1:
            system("clear||cls");
            printf("*-------------------------------------------------------------------------------*\n");
            printf("                     .......   Todos os clientes   .......                    \n");
            printf("*-------------------------------------------------------------------------------*\n");
            list_cli('T');
            break;
        case 2:
            system("clear||cls");
            printf("*-------------------------------------------------------------------------------*\n");
            printf("                .......   Clientes aniversarientes do mes  .......                    \n");
            printf("*-------------------------------------------------------------------------------*\n");
            list_cli('A');
            break;
        case 3:
            system("clear||cls");
            printf("*-------------------------------------------------------------------------------*\n");
            printf("                  .......   Clientes por ordem alfabetica   .......                    \n");
            printf("*-------------------------------------------------------------------------------*\n");
            list_alf();
            break;
        case 4:
            system("clear||cls");
            printf("*-------------------------------------------------------------------------------*\n");
            printf("                .......   Clientes por ordem de mais reservas   .......          \n");
            printf("*-------------------------------------------------------------------------------*\n");
            printf("|   -  CPF                  -  Nome                - Quant. de Reservas         |\n");
            printf("*-------------------------------------------------------------------------------*\n");
            list_cli_r();
            break;
        }
    } while (op!=0);
    
}
void list_alf(void){
    Cliente *list;
    list = NULL;
    gerar_list(&list);
    exibir_list_alf(list);
    del_list(&list);
}
void list_cli_r(void){
    Cliente *list;
    list = NULL;
    gerar_reser(&list);
    exibir_list(list);
    del_list(&list);
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
    }else if(encont_cli(cpf,'I')==1){
        int op=-1;
        printf("-- Um cliente desativado com esse ID ja cadastrado\n");
        printf("-- Deseja reativa-lo:\n");
        printf("1- Sim      2- Nao\n");
        printf("Sua opc:");
        scanf("%d",&op);
        if(op==1){
            FILE *fp;
            fp = fopen("clientes.dat", "r+b");
            if (fp == NULL)
            {
                printf("Não foi possivel abrir o arquivo!");
                getchar();
                return;
            }
            while (fread(cli, sizeof(Cliente), 1, fp) == 1){
                if ((strcmp(cli->cpf, cpf) == 0) && cli->status == 'I'){
                    cli->status = 'A';
                    fseek(fp, -1 * (sizeof(Cliente)), SEEK_CUR);
                    fwrite(cli, sizeof(Cliente), 1, fp);
                    break;
                }
            }
            fclose(fp);
        }
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
void list_cli(char ope){
    FILE* fp;
    Cliente* cli;
    cli = (Cliente*) malloc(sizeof(Cliente));
    fp = fopen("clientes.dat", "rb");
    if (fp == NULL) {
        printf("- Nao clientes cadastrados!");
        getchar();
        return;
    }
    int ani=0;
    printf("*-------------------------------------------------------------------------------*\n");
    printf("|      -    CPF                     -   Nome                                     |\n");
    printf("*-------------------------------------------------------------------------------*\n");
    while(fread(cli,sizeof(Cliente), 1, fp)){
        if(ope=='T'){
            if(cli->status!='I'){
                printf("| %-12s             - %-50s |   \n", cli->cpf,cli->nome);
            }
        }
        if(ope=='A'){
            time_t t = time(NULL);
            struct tm tm = *localtime(&t);
            int m=data(cli->nasc);
            if(m==(tm.tm_mon+1)){
                printf("| %-12s             - %-50s |   \n", cli->cpf,cli->nome);
                ani=1;
            }
        }
    }
    if(ope=='A' && ani==0){
        printf("- Nao ha aniversariantes esse mes.\n");
    }
    getchar();
    free(cli);
    fclose(fp);
}
void most_cli(Cliente* cli){
    printf("CPF: %s\n", cli->cpf);
    printf("Email: %s\n", cli->email);
    printf("Nome: %s\n", cli->nome);
    printf("Data de Nascimento: %s\n", cli->nasc);
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
        if (strcmp(cli->cpf, cpf)==0) {
            existe=1;
            if(cli->status == 'A'){
                if (ope == 'M') {
                    most_cli(cli);
                }
            existe = 2; //existe e esta ativo
            }
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
    if(encont_cli(cpf,'I')==2){
        while(fread(cli,sizeof(Cliente), 1, fp)){
            if (strcmp(cli->cpf, cpf)==0 && cli->status=='A') {
                do
                {
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
                }while (opc!=0);
                break;
            } 
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
    FILE* fp;
    Cliente* cli;
    cli = (Cliente*) malloc(sizeof(Cliente));
    fp = fopen("clientes.dat", "r+b");
    if (fp == NULL) {
        printf("Não foi possivel abrir o arquivo!");
        getchar();
        return;
    }
    if(encont_cli(cpf,'I')==2){
        while(fread(cli,sizeof(Cliente), 1, fp)){
            if ((strcmp(cli->cpf, cpf))==0) {
                cli->status = 'I';
                fseek(fp, -1*(sizeof(Cliente)), SEEK_CUR);
                fwrite(cli, sizeof(Cliente), 1, fp);
                break;
            }
        }
    }else{
        printf("\t\t- Cliente nao encontrado!");
    }
    fclose(fp);
    free(cli);
    printf("\n*-------------------------------------------------------------------------------*\n");
    printf("\t>> Digite ENTER para prosseguir!");
    getchar();
}
void gerar_list(Cliente **list){
    FILE *fp;
    Cliente *cli;
    del_list(&(*list));
    *list = NULL;
    fp = fopen("clientes.dat","rb");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo... \n");
        return;
    } else {
        cli = (Cliente *) malloc(sizeof(Cliente));
        while (fread(cli, sizeof(Cliente), 1, fp)) {
            if ((*list == NULL) || (strcmp(cli->nome, (*list)->nome) < 0)) {
                cli->prox = *list;
                *list = cli;
            } else {
                Cliente* ant = *list;
                Cliente* at = (*list)->prox;
                while ((at != NULL) && (strcmp(at->nome, cli->nome) < 0)) {
                    ant = at;
                    at = at->prox;
                }
                ant->prox = cli;
                cli->prox = at;
            }
            cli = (Cliente*) malloc(sizeof(Cliente));
        }
        free(cli);
        fclose(fp);
    } 
}
void gerar_reser(Cliente **list){
    FILE *fp;
    Cliente *cli;
    del_list(&(*list));
    *list = NULL;
    fp = fopen("clientes.dat","rb");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo... \n");
        return;
    } else {
        cli = (Cliente *) malloc(sizeof(Cliente));
        while (fread(cli, sizeof(Cliente), 1, fp)) {
            if ((*list == NULL) || (cont_reser(cli->cpf)>cont_reser((*list)->cpf))) {
                cli->prox = *list;
                *list = cli;
            } else {
                Cliente* ant = *list;
                Cliente* at = (*list)->prox;
                while ((at != NULL) && (cont_reser(ant->cpf)>cont_reser(at->cpf))) {
                    ant = at;
                    at = at->prox;
                }
                ant->prox = cli;
                cli->prox = at;
            }
            cli = (Cliente*) malloc(sizeof(Cliente));
        }
        free(cli);
        fclose(fp);
    } 
}
int cont_reser(char cliente[]){
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
                if (strcmp(reser->cliente, cliente)==0) {
                    existe=existe+1;
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
void del_list(Cliente **list){
    Cliente *cli;
    while (*list != NULL) {
        cli = *list;
        *list = (*list)->prox;
        free(cli);
    }  
}
void exibir_list(Cliente *aux){
    while (aux != NULL) {
        printf("| %-15s      -%-37s   - %-10d    |   \n",aux->cpf, aux->nome ,cont_reser(aux->cpf));
        aux =aux->prox;
	}
    getchar();
}
void exibir_list_alf(Cliente *aux){
    while (aux != NULL) {
        printf("| %-12s             - %-50s |   \n", aux->cpf,aux->nome);
        aux =aux->prox;
	}
    getchar();
}