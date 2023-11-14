#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "funcionario.h"
#include "quarto.h"
#include "reserva.h"

#define true 1
#define false 0

void inicio(void);
void cabecalho(void);
void instrucoes(void);
void sobre(void);
int menu_principal(void);

int main(void) {
    inicio();
    int op;
    do
    {
        system("clear||cls");
        op=menu_principal();
        switch (op)
        {
        case 1:
            menu_clientes();
            break;
        
        case 2:
            menu_funcionarios();
            break;
        case 3:
            menu_quartos();
            break;
        case 4:
            menu_reservas();
            break;
        case 5:
            instrucoes();
            break;
        case 6:
            sobre();
            break;
        }
    } while ((op)!=0);
    
    printf("%c",op);
    return 0;
}
void inicio(void){
    printf("        d8?__d8b_d8b__`8b                                    d8?__d8b_d8b__`8b \n");
    printf("       d8?_____d8b_____`8b          Bem vindo(s)            d8?_____d8b_____`8b\n");
    printf("       8b_______________d8                                  8b_______________d8\n");
    printf("        d8_____________8b               ao                   d8_____________8b\n");
    printf("         8ba_________ad8                                      8ba_________ad8\n");
    printf("          `8da_____ab8?       __________C.G._________          `8da_____ab8?\n");
    printf("            `Y8___8Y?        |                       |           `Y8___8Y?\n");
    printf("              `8_8?          |         Motel         |             `8_8?\n");
    printf("               `8?           |_______________________|              `8?");
    printf("                "                                                    "");
    printf("\n");
    printf("\t>> Digite ENTER para prosseguir...");
    getchar();
}
void cabecalho(void){
    printf("*-------------------------------------------------------------------------------*\n");
    printf("|                 Universidade Federal do Rio Grande do Norte                   |\n");
    printf("|                     Centro de Ensino Superior do Serido                      |\n");
    printf("|                   Departamento de Computacao e Tecnologia                     |\n");
    printf("|                      Disciplina DCT1106 -- Programacao                        |\n");
    printf("|                     Projeto Sistema de Gestao de Motel                        |\n");
    printf("|               Desenvolvido por M� Eloisa da Silva Santos (@EL0ISA)            |\n");
    printf("*-------------------------------------------------------------------------------*\n");
}
void instrucoes(void){
    system("clear||cls");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("|                          Intrucoes de uso do programa                         |\n");
    printf("|       1. Nas entradas de dados so serao aceito letras simples e pontuacao     |\n");
    printf("| 2. Entradas de valores reais so aceitarao . e nao , como separador de centavos|\n");
    printf("|                      3. Entradas sensiveis ao case                            |\n");
    printf("*-------------------------------------------------------------------------------*\n");
    getchar();
}
void sobre(void){
    system("clear||cls");
    cabecalho();
    printf("*-------------------------------------------------------------------------------*\n");
    printf("|                               Sobre o projeto                                 |\n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("| O CGmotel e um projeto desenvolvido para a disciplina de programacao com fins |\n");
    printf("| de aprendizagem. O mesmo consiste em um sistema de gestao para um motel, dessa|\n");
    printf("| forma contando com os modulos de clientes, quartos, reservas e funcionarios.  |\n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("|                           Desenvolvido por Eloisa                             |\n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("\t>> Digite ENTER para prosseguir...");
    getchar();getchar();
}
int menu_principal(void){
    int opc;
    printf("*-------------------------------------------------------------------------------*\n");
    printf("|                               Gestao do Motel                                 |\n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("|                               1. Clientes                                     |\n");
    printf("|                               2. Funcionarios                                 |\n");
    printf("|                               3. Quartos                                      |\n");
    printf("|                               4. Reservas                                     |\n");
    printf("|                               5. Instrucoes                                   |\n");
    printf("|                               6. Sobre o projeto                              |\n");
    printf("|                               0. Sair                                         |\n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("-- Sua opc: ");
    scanf(" %d",&opc);
    getchar();
    fflush(stdin);
    return opc;
}