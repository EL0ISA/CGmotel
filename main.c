#include <stdio.h>
#include <stdlib.h>

void inicio(void);
void sobre(void);
void menu_principal(void);

int main(void) {
    inicio();
    sobre();
    menu_principal();
    return 0;
}
void menu_principal(void){
    char opc;
    system("clear||cls");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("|                               Gestão do Motel                                 |\n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("|                               1. Clientes                                     |\n");
    printf("|                               2. Funcionarios                                 |\n");
    printf("|                               3. Quartos                                      |\n");
    printf("|                               4. Reservas                                     |\n");
    printf("|                               0. Sair                                         |\n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("-- Sua opc: ");
    scanf("%c",&opc);
    getchar();
}
void sobre(void){
    printf("*-------------------------------------------------------------------------------*\n");
    printf("|                               Sobre o projeto                                 |\n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("| O CGmotel é um projeto desenvolvido para a disciplina de programação com fins |\n");
    printf("| de aprendizagem. O mesmo consiste em um sistema de gestão para um motel, dessa|\n");
    printf("| forma contando com os modulos de clientes, quartos, reservas e funcionarios.  |\n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("|                           Desenvolvido por Eloisa                             |\n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}
void inicio(void){
    printf("*-------------------------------------------------------------------------------*\n");
    printf("|                 Universidade Federal do Rio Grande do Norte                   |\n");
    printf("|                     Centro de Ensino Superior do Seridó                       |\n");
    printf("|                   Departamento de Computação e Tecnologia                     |\n");
    printf("|                      Disciplina DCT1106 -- Programação                        |\n");
    printf("|                     Projeto Sistema de Gestão de Motel                        |\n");
    printf("|               Desenvolvido por Mª Eloisa da Silva Santos (@EL0ISA)            |\n");
    printf("*-------------------------------------------------------------------------------*\n");
}