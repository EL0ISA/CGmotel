#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funcionario.h"
#include "reserva.h"
#include "auxiliares.h"
#include "uteis.h"

void menu_funcionarios(void)
{
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
        printf("|                             5. Listar todos                                   |\n");
        printf("|                             6. Aniversariantes do mes                         |\n");
        printf("|                             7. Ordem Alfabetica                               |\n");
        printf("|                             8. Ordem por mais reservas                        |\n");
        printf("|                             0. Voltar                                         |\n");
        printf("*-------------------------------------------------------------------------------*\n");
        printf("-- Sua opc: ");
        scanf("%d", &opc);
        getchar();
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
            list_func('T');
            break;
        case 6:
            list_func('A');
            break;
        case 7:
            list_fun_alf();
            break;
        case 8:
            list_fun_r();
            break;
        }
    } while (opc != 0);
}
void cad_func(void)
{
    system("clear||cls");
    char cpf[12];
    Funcionario *func;
    func = (Funcionario *)malloc(sizeof(Funcionario));
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Cadastrando novo funcionario   .......                \n");
    printf("*-------------------------------------------------------------------------------*\n");
    w_cpf(cpf);
    if (encont_func(cpf, 'I') == 0)
    {
        strcpy(func->cpf, cpf);
        w_email(func->email);
        w_nome(func->nome);
        w_nasc(func->nasc);
        printf("                 .......   Funcao do funcionario   .......            \n");
        printf("|                             1. Gerente                                        |\n");
        printf("|                             2. Recepcao                                       |\n");
        printf("|                             3. Faxineiro(a)                                   |\n");
        w_funcao(&(func->funcao));
        func->status = 'A';
        grava_func(func);
    }
    else
    {
        printf("- Funcionario ja cadastrado com esse CPF!\n");
    }
    printf("*-------------------------------------------------------------------------------*\n");
    printf("\t>>");
    getchar();
    free(func);
}
void grava_func(Funcionario *func)
{
    FILE *fp;
    fp = fopen("funcionarios.dat", "ab");
    if (fp == NULL)
    {
        printf("Erro na abertura do arquivo\n");
        return;
    }
    fwrite(func, sizeof(Funcionario), 1, fp);
    fclose(fp);
}
void list_func(char ope)
{
    FILE *fp;
    Funcionario *func;
    func = (Funcionario *)malloc(sizeof(Funcionario));
    fp = fopen("funcionarios.dat", "rb");
    if (fp == NULL)
    {
        printf("- Nao funcionarios cadastrados!");
        getchar();
    }
    while (fread(func, sizeof(Funcionario), 1, fp))
    {
        if(ope=='T'){
            if (func->status != 'I')
            {
                most_func(func);
            }
        }
        if(ope=='A'){
            time_t t = time(NULL);
            struct tm tm = *localtime(&t);
            int m=data(func->nasc);
            if(m==(tm.tm_mon+1)){
                most_func(func);
            }
        }
    }
    getchar();
    free(func);
    fclose(fp);
}

void most_func(Funcionario *func)
{
    printf("CPF: %s\n", func->cpf);
    printf("Email: %s\n", func->email);
    printf("Nome: %s\n", func->nome);
    printf("Data de Nascimento: %s\n", func->nasc);
    if(func->funcao==1){
        printf("Funcao: Gerente \n");
    }else if(func->funcao==2){
        printf("Funcao: Recepcao \n");
    }else if(func->funcao==3){
        printf("Funcao: Faxineiro(a) \n");
    }
    getchar();
}
void pesq_func(void)
{
    system("clear||cls");
    char cpf[12];
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Pesquisando dados de funcionario   .......            \n");
    printf("*-------------------------------------------------------------------------------*\n");
    w_cpf(cpf);
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Resultados Encontrados   .......                      \n");
    encont_func(cpf, 'M');
    printf("*-------------------------------------------------------------------------------*\n");
    printf("\t>> Digite ENTER para prosseguir!");
    getchar();
}
int encont_func(char cpf[], char ope)
{
    FILE *fp;
    int existe = 0;
    Funcionario *func;
    func = (Funcionario *)malloc(sizeof(Funcionario));
    fp = fopen("funcionarios.dat", "rb");
    if (fp == NULL)
    {
        fp = fopen("funcionarios.dat", "ab");
    }
    while (fread(func, sizeof(Funcionario), 1, fp))
    {
        if (strcmp(func->cpf, cpf) == 0 && func->status == 'A')
        {
            if (ope == 'M')
            {
                most_func(func);
            }
            existe = 1;
        }
    }
    free(func);
    fclose(fp);
    return existe;
}
void edit_func(void)
{
    char cpf[12];
    int opc;
    FILE *fp;
    Funcionario *func;
    func = (Funcionario *)malloc(sizeof(Funcionario));
    fp = fopen("funcionarios.dat", "r+b");
    system("clear||cls");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Atualizando dados de funcionario   .......            \n");
    printf("*-------------------------------------------------------------------------------*\n");
    w_cpf(cpf);
    if (fp == NULL)
    {
        printf("Não foi possivel abrir o arquivo!");
        getchar();
    }
    if (encont_func(cpf, 'I') == 1){
        while (fread(func, sizeof(Funcionario), 1, fp)){
            if (strcmp(func->cpf, cpf) == 0 && func->status == 'A') {
                do
                {
                    printf("1 - Email: %s\n", func->email);
                    printf("2 - Nome: %s\n", func->nome);
                    printf("3 - Data de Nascimento: %s\n", func->nasc);
                    printf("0 - Finalizar alteracoes.");
                    printf("\n -Campo que deseja editar:");
                    scanf("%d", &opc);
                    getchar();
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
                    fseek(fp, -1 * (sizeof(Funcionario)), SEEK_CUR);
                    fwrite(func, sizeof(Funcionario), 1, fp);
                } while (opc!=0);
                break;
            }
        }
    }
    else
    {
        printf("\t\t- Funcionario nao encontrado!\n");
    }
    free(func);
    fclose(fp);
    printf("*-------------------------------------------------------------------------------*\n");
    printf("\t>> Digite ENTER para prosseguir!");
    getchar();
}
void del_func(void)
{
    char cpf[12];
    Funcionario *func;
    FILE *fp;
    func = (Funcionario *)malloc(sizeof(Funcionario));
    system("clear||cls");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Deletando funcionario   .......                       \n");
    printf("*-------------------------------------------------------------------------------*\n");
    w_cpf(cpf);
    fp = fopen("funcionarios.dat", "r+b");
    if (fp == NULL)
    {
        printf("Não foi possivel abrir o arquivo!");
        getchar();
    }
    if (encont_func(cpf, 'I') == 1)
    {
        while (fread(func, sizeof(Funcionario), 1, fp) == 1)
        {
            if ((strcmp(func->cpf, cpf) == 0) && func->status == 'A')
            {
                func->status = 'I';
                fseek(fp, -1 * (sizeof(Funcionario)), SEEK_CUR);
                fwrite(func, sizeof(Funcionario), 1, fp);
                break;
            }
        }
    }
    else
    {
        printf("\t\t- Funcionario nao encontrado!");
        getchar();
    }
    fclose(fp);
    free(func);
    printf("\n*-------------------------------------------------------------------------------*\n");
    printf("\t>> Digite ENTER para prosseguir!");
    getchar();
}
void list_fun_alf(void){
    Funcionario *list;
    list = NULL;
    gerar_list_fun(&list);
    exibir_list_fun(list);
    del_list_fun(&list);
}
void list_fun_r(void){
    Funcionario *list;
    list = NULL;
    gerar_reser_fun(&list);
    exibir_list_fun(list);
    del_list_fun(&list);
}
void gerar_list_fun(Funcionario **list){
    FILE *fp;
    Funcionario *fun;
    del_list_fun(&(*list));
    *list = NULL;
    fp = fopen("funcionarios.dat","rb");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo... \n");
        return;
    } else {
        fun = (Funcionario *) malloc(sizeof(Funcionario));
        while (fread(fun, sizeof(Funcionario), 1, fp)) {
            if ((*list == NULL) || (strcmp(fun->nome, (*list)->nome) < 0)) {
                fun->prox = *list;
                *list = fun;
            } else {
                Funcionario* ant = *list;
                Funcionario* at = (*list)->prox;
                while ((at != NULL) && (strcmp(at->nome, fun->nome) < 0)) {
                    ant = at;
                    at = at->prox;
                }
                ant->prox = fun;
                fun->prox = at;
            }
            fun = (Funcionario*) malloc(sizeof(Funcionario));
        }
        free(fun);
        fclose(fp);
    } 
}
void gerar_reser_fun(Funcionario **list){
    FILE *fp;
    Funcionario *fun;
    del_list_fun(&(*list));
    *list = NULL;
    fp = fopen("funcionarios.dat","rb");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo... \n");
        return;
    } else {
        fun = (Funcionario *) malloc(sizeof(Funcionario));
        while (fread(fun, sizeof(Funcionario), 1, fp)) {
            if ((*list == NULL) || (cont_reser_fun(fun->cpf)>cont_reser_fun((*list)->cpf))) {
                fun->prox = *list;
                *list = fun;
            } else {
                Funcionario* ant = *list;
                Funcionario* at = (*list)->prox;
                while ((at != NULL) && (cont_reser_fun(ant->cpf)>cont_reser_fun(at->cpf))) {
                    ant = at;
                    at = at->prox;
                }
                ant->prox = fun;
                fun->prox = at;
            }
            fun = (Funcionario*) malloc(sizeof(Funcionario));
        }
        free(fun);
        fclose(fp);
    } 
}
int cont_reser_fun(char funcionario[]){
    FILE* fp;
    Funcionario* fun;
    int existe=0;
    fun = (Funcionario*) malloc(sizeof(Funcionario));
    fp = fopen("funcionarios.dat", "rb");
    if (fp == NULL) {
        fp = fopen("funcionarios.dat","ab");
    }
    while(fread(fun,sizeof(Funcionario), 1, fp)){
        if (strcmp(fun->cpf,funcionario)==0 && fun->status=='A') {
            FILE* fr;
            Reserva* reser;
            reser = (Reserva*) malloc(sizeof(Reserva));
            fr = fopen("reservas.dat", "rb");
            if (fr == NULL) {
                fr = fopen("reservas.dat","ab");
            }
            while(fread(reser,sizeof(Reserva), 1, fr)){
                if (strcmp(reser->func_in, funcionario)==0) {
                    existe=existe+1;
                }
            }
            free(reser);
            fclose(fr);
        }
    }
    free(fun);
    fclose(fp);
    return existe;
}
void del_list_fun(Funcionario **list){
    Funcionario *fun;
    while (*list != NULL) {
        fun = *list;
        *list = (*list)->prox;
        free(fun);
    }  
}
void exibir_list_fun(Funcionario *aux){
    while (aux != NULL) {
        printf("| %-15s - %-10s        -%-12s   -%-12d   |   \n", aux->nome, aux->nasc ,aux->cpf,cont_reser_fun(aux->cpf));
        aux =aux->prox;
	}
    getchar();
}