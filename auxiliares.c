#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "auxiliares.h"
#include "uteis.h"

double* w_preco(double*preco){
    int valido;
    char cpreco[20];
    do
    {
        printf("|            - Preco por hora:");
        scanf("%[^\n]",cpreco);
        fflush(stdin);
        valido=verif_preco(cpreco);
    } while (valido!=1);
    double vfloat=atof(cpreco);
    *preco=vfloat;
    return preco;
}
double* w_padd(double*padd){
    int valido;
    char cpreco[20];
    do
    {
        printf("|            - Custos adicionais:");
        scanf("%[^\n]",cpreco);
        fflush(stdin);
        valido=verif_preco(cpreco);
    } while (valido!=1);
    printf("oka");
    double vfloat=atof(cpreco);
    *padd=vfloat;
    return padd;
}
char* w_nome(char* nome){
    int valido;
    do
    {
        printf("|            - Nome completo: ");
        scanf("%[^\n]",nome);
        fflush(stdin);
        valido=verif_nome(nome);
    } while (valido!=1);
    return nome;
}
char* w_cpf(char* cpf){
    int valido;
    do
    {
        printf("|            - CPF (apenas numeros):");
        scanf("%[^\n]",cpf);
        fflush(stdin);
        valido=verif_cpf(cpf);
    } while (valido!=1);
    return cpf;
}
char* w_email(char* email){
    int valido;
    do
    {
        printf("|            - E-mail: ");
        scanf("%[^\n]",email);
        fflush(stdin);
        valido=verif_email(email);
    } while (valido!=1);
    return email;
}
char* w_nasc(char* nasc){
    int valido;
    do
    {
        printf("|            - Data de Nascimento (dd/mm/aaaa): ");
        scanf("%[^\n]",nasc);
        fflush(stdin);
        valido=verif_nasc(nasc);
    } while (valido!=1);
    return nasc;
}
int* w_funcao(int* funcao){
    int valido;
    char cfuncao[1];
    do
    {
        printf("|            - Opcao:");
        scanf("%[^\n]",cfuncao);
        fflush(stdin);
        valido=verif_funcao(cfuncao);
    } while (valido!=1);
    *funcao=atoi(cfuncao);
    return funcao;
}
char* w_identificacao(char* identificacao){
    int valido;
    do
    {
        printf("|            - Identificacao:");
        scanf("%[^\n]",identificacao);
        fflush(stdin);
        valido=verif_identificacao(identificacao);
    } while (valido!=1);
    return identificacao;
}
char* w_descricao(char* descricao){
    int valido;
    do
    {
        printf("|            - Descricao:");
        scanf("%[^\n]",descricao);
        fflush(stdin);
        valido=verif_descricao(descricao);
    } while (valido!=1);
    return descricao;
}
int* w_status(int* status){
    int valido;
    char cstatus[1];
    do
    {
        printf("|            - Opcao:");
        scanf("%[^\n]",cstatus);
        fflush(stdin);
        valido=verif_funcao(cstatus);
    } while (valido!=1);
    *status=atoi(cstatus);
    return status;
}
char* w_cliente(char* cliente){
    int valido;
    do
    {
        printf("|            - CPF do cliente:");
        scanf("%[^\n]",cliente);
        fflush(stdin);
        valido=verif_cpf(cliente);
    } while (valido!=1);
    return cliente;
}
char* w_funcionario(char* funcionario){
    int valido;
    do
    {
        printf("|            - CPF do funcionario:");
        scanf("%[^\n]",funcionario);
        fflush(stdin);
        valido=verif_cpf(funcionario);
    } while (valido!=1);
    return funcionario;
}
char* w_quarto(char* quarto){
    int valido;
    do
    {
        printf("|            - Identificacao do quarto:");
        scanf("%[^\n]",quarto);
        fflush(stdin);
        valido=verif_identificacao(quarto);
    } while (valido!=1);
    return quarto;
}
int* w_horas(int* horas){
    int valido;
    char choras[2];
    do
    {
        printf("|            - Horas de reserva:");
        scanf("%[^\n]",choras);
        fflush(stdin);
        valido=verif_horas(choras);
    } while (valido!=1);
    *horas=atoi(choras);
    return horas;
}
char* w_obs(char* obs){
    int valido;
    do
    {
        printf("|            - Observacoes:");
        scanf("%[^\n]",obs);
        fflush(stdin);
        valido=verif_obs(obs);
    } while (valido!=1);
    return obs;
}