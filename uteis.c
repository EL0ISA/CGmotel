#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
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
    double vfloat=atof(cpreco);
    *padd=vfloat;
    return padd;
}
int verif_preco(char* cpreco){
    int tam=strlen(cpreco);
    int contPonto=0,ponto=0, p_ponto=0;
    if(tam>20){
        return 0;
    }
    for (int i = 0; i < tam; i++)
    {
        if(!isdigit(cpreco[i]) && cpreco[i]!='.'){
            return 0;
        }
        if(ispunct(cpreco[i])){
            contPonto++;
        }
    }
    if(contPonto>1){
        return 0;
    }
    for (int i = 0; cpreco[i]!='.'; i++){
        ponto++;
    }
    for (int i = (ponto); i<tam; i++){
        p_ponto++;
    }
    if((p_ponto-1)>2){
        return 0;
    }
   return 1; 
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
int verif_nome(char* nome){
    int tam=strlen(nome);
    int espaco=0;
    for (int i = 0; i < tam; i++)
    {
        if(!isalpha(nome[i])&&nome[i]!=' '){
            return 0;
        }
        if(nome[i]==' '){
            if(nome[i+1]==nome[i]||nome[i-1]==nome[i]){
                return 0;
            }
            espaco++;
        }
    }
    if (espaco<1){
        return 0;
    }
    if(tam>50){
        return 0;
    }
    return 1;
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
int verif_cpf(char* cpf){
    int tam=strlen(cpf);
    int s1=0,d1=0,d2=0;
    if(tam!=11){
        return 0;
    }
    /*apenas numeros*/
    for(int i=0;i<tam;i++){
        if(!isdigit(cpf[i])){
            return 0;
        }
    }

    for (int i = 0; i <9; i++){
        char letra[1]="";
        concatenar(letra,cpf[i]);
        int n=atoi(letra);
        s1+=n*(10-i);
    }
    if(s1%11<2){
        d1=0;
    }else if(s1%11>=2){
        d1=11-(s1%11);
    }
    char caract = d1+'0';
    if(caract!=cpf[9]){
        return 0;
    }
    s1=0;
    for (int i = 0; i <10; i++){
        char letra[1]="";
        concatenar(letra,cpf[i]);
        int n=atoi(letra);
        s1+=n*(11-i);
    }
    if(s1%11<2){
        d2=0;
    }else if(s1%11>=2){
        d2=11-(s1%11);
    }
    char caract2 = d2+'0';
    if(caract2!=cpf[10]){
        return 0;
    }
    return 1;
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
int verif_email(char* email){
    int tam=strlen(email);
    int arroba=0,ponto=0,pre_arroba=0;
    if(tam>225){
        return 0;
    }
    for (int i = 0; i<tam; i++){
        /*qualquer caracter difente desses, será invalido*/
        if(!isalnum(email[i])&& email[i]!='@'&&email[i]!='.'&&email[i]!='-'&&email[i]!='_'){
            return 0;
        }
        if(email[i]=='@'){
            arroba++;
        }
        /*ter ao menos um caracter alphanum após . - ou _*/
        if(email[i]=='.' || email[i]=='-' || email[i]=='_'){
            if(email[i]==email[i+1]&&!isalnum(email[i+1])){
                return 0;
            }
        }
    }
    /*ter apenas 1 @*/
    if(arroba!=1){
        return 0;
    }
    for (int i = 0; email[i]!='@'; i++){
        pre_arroba++;
    }
    if(pre_arroba>64){
        return 0;
    }
    /*ter ao menos 1 caracter alphanum antes e pós @*/
    if(!isalnum(email[pre_arroba-1])||!isalnum(email[pre_arroba+1])){
        return 0;
    }
    for (int i = (pre_arroba+1); i<tam; i++){
        if(email[i]=='.'){
            ponto++;
        }
    }
    if(1>ponto){
        return 0;
    }
    return 1;
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
int verif_nasc(char* nasc){
    int tam=strlen(nasc);
    char dia[2]="",mes[2]="",ano[4]="";
    int p_barra=0,s_barra=0;
    if(tam>10){
        return 0;
    }
    for (int i = 0; i<tam; i++){
        /*qualquer caracter difente desses, será invalido*/
        if(!isdigit(nasc[i])&& nasc[i]!='/'){
            return 0;
        }
        /*ter ao menos um caracter numerico antes e depois do /*/
        if(nasc[i]=='/'){
            if(!isdigit(nasc[i+1])&&!isdigit(nasc[i-1])){
                return 0;
            }
        }
    }
    /*pegando dia,mes e ano separadamente*/
    for (int i = 0; nasc[i]!='/'; i++){
        concatenar(dia,nasc[i]);
        p_barra++;
    }
    int d=atoi(dia);
    for (int i = (p_barra+1); nasc[i]!='/'; i++){
        concatenar(mes,nasc[i]);
        s_barra++;
    }
    int m=atoi(mes);
    for (int i = ((p_barra+1)+(s_barra+1)); i<tam; i++){
        concatenar(ano,nasc[i]);
    }
    if(strlen(ano)>4){
        return 0;
    }
    int a=atoi(ano);
    /*validação data*/
    if(1>m && m>12){
        return 0;
    }
    if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12){
        if(d>31||d<1){
            return 0;
        }
    }else if(m==4 || m==6 || m==9 || m==11){
        if(d>30||d<1){
            return 0;
        }
    }else if(m==2){
        if(bissexto(a)==1){
            if(d>29||d<1){
                return 0;
            }
        }else{
            if(d>28||d<1){
                return 0;
            }
        }
    }else{
        return 0;
    }
    return 1;
}
void concatenar(char text[], char caracter){
    int tam = strlen(text);
    text[tam] = caracter;
    text[tam + 1] = '\0'; /*recolocar o terminador*/
}
int bissexto(int a){
    if(a%4==0 && a%100!=0){
        return 1;
    }else if(a%400==0){
        return 1;
    }else{
        return 0;
    }
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
int verif_funcao(char* cfuncao){
    int tam=strlen(cfuncao);
    if(tam>1){
        return 0;
    }
    if(!isdigit(cfuncao[0])){
        return 0;
    }
    int n=atoi(cfuncao);
    if(0>n || n>3){
        return 0;
    }
    return 1;
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
int verif_identificacao(char* identificacao){
    int tam=strlen(identificacao);
    for (int i = 0; i < tam; i++)
    {
        if(!isalnum(identificacao[i])){
            return 0;
        }
    }
    
    if(tam>10){
        return 0;
    }
    return 1;
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
int verif_descricao(char* descricao){
    if(strlen(descricao)>100){
        return 0;
    }
    return 1;
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
int verif_status(char* cstatus){
    int tam=strlen(cstatus);
    if(tam>1){
        return 0;
    }
    if(!isdigit(cstatus[0])){
        return 0;
    }
    int n=atoi(cstatus);
    if(0>n || n>3){
        return 0;
    }
    return 1;
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
        valido=verif_funcao(choras);
    } while (valido!=1);
    *horas=atoi(choras);
    return horas;
}
int verif_horas(char* choras){
    int tam=strlen(choras);
    if(tam>2){
        return 0;
    }
    for (int i = 0; i < tam; i++)
    {
        if(!isdigit(choras[i])){
            return 0;
        }
    }
    
    int n=atoi(choras);
    if(0<n || n>12){
        return 0;
    }
    return 1;
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
int verif_obs(char* obs){
    if(strlen(obs)>100){
        return 0;
    }
    return 1;
}