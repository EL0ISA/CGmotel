#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "uteis.h"

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
    }else if(contPonto==1){
        for (int i = 0; cpreco[i]!='.'; i++){
            ponto++;
        }
        for (int i = (ponto); i<tam; i++){
            p_ponto++;
        }
        if((p_ponto-1)>2){
            return 0;
        }
    }
   return 1; 
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
int data(char* nasc){
    char dia[2]="",mes[2]="";
    int p_barra=0,s_barra=0;
    for (int i = 0; nasc[i]!='/'; i++){
        concatenar(dia,nasc[i]);
        p_barra++;
    }
    for (int i = (p_barra+1); nasc[i]!='/'; i++){
        concatenar(mes,nasc[i]);
        s_barra++;
    }
    int m=atoi(mes);
    return m;
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
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    if (a>=1800 && a<=(tm.tm_year+1900) && d>0){
        if(m>(tm.tm_mon) &&d>(tm.tm_mday)&& a>=(tm.tm_year+1900)){
            return 0; 
        }
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
int verif_identificacao(char* identificacao){
    int tam=strlen(identificacao);
    if (identificacao==NULL){
        return 0;
    }
    for (int i = 0; i < tam; i++)
    {
        if(!isalnum(identificacao[i])){
            return 0;
        }
    }
    
    if(tam>15){
        return 0;
    }
    return 1;
}
int verif_descricao(char* descricao){
    if (descricao==NULL || strcmp(descricao,"")==0){
        return 0;
    }
    if(strlen(descricao)>99){
        return 0;
    }
    return 1;
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
    if(0>n && n>3){
        return 0;
    }
    return 1;
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
    if(1>n || n>12){
        return 0;
    }
    return 1;
}
int verif_obs(char* obs){
    if(strlen(obs)>99){
        return 0;
    }
    return 1;
}
//Adpatado do ChatGPT por Maria Eloisa(eu)
char* data_hora(char* data_hora, size_t tam){
    struct tm current_time;
    time_t t = time(NULL);
    current_time = *localtime(&t);
    strftime(data_hora, tam, "%d-%m-%Y %H:%M:%S", &current_time);

    return data_hora;
}