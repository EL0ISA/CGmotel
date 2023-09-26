#include <stdio.h>
#include <stdlib.h>
#include "reserva.h"

void menu_reservas(void){
    char opc;
    do
    {
        system("clear||cls");
        printf("\n*-------------------------------------------------------------------------------*\n");
        printf("*                               Menu Reservas                                   *\n");
        printf("*-------------------------------------------------------------------------------*\n");
        printf("|                             1. Check-in                                       |\n");
        printf("|                             2. Pesquisar                                      |\n");
        printf("|                             3. Check-out                                      |\n");
        printf("|                             4. Deletar reserva                                |\n");
        printf("|                             0. Voltar                                         |\n");
        printf("*-------------------------------------------------------------------------------*\n");
        printf("-- Sua opc: ");
        scanf("%c",&opc);
        while (getchar() != '\n');
        switch (opc)
            {
            case '1':
                checkin();
                break;
            case '2':
                pesq_reser();
                break;
            case '3':
                checkout();
                break;
            case '4':
                del_reser();
                break;
            }
    } while (opc!='0');
    
}
void pesq_reser(void){
    system("clear||cls");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Pesquisando dados de reserva   .......                \n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("|            - Informe o CPF do cliente:                                        |\n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("\t>> Digite ENTER para prosseguir!");
    getchar();
}
void checkin(void){
    system("clear||cls");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Cadastrando nova reserva   .......                    \n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("|            - CPF do cliente:                                                  |\n");
    printf("|            - Identificacao do quarto:                                         |\n");
    printf("|            - Horas de reserva:                                                |\n");
    printf("|            - Observacoes:                                                     |\n");
    printf("|            - Custos adicionais:                                               |\n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Realizando Check-in   .......                         \n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("|            - CPF do Funcionario:                                              |\n");
    printf("|            - Horario:                                                         |\n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("\t>> Digite ENTER para prosseguir!");
    getchar();
}
void checkout(void){
    system("clear||cls");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Realizando Check-out   .......                        \n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("|            - Informe o ID da reserva:                                         |\n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("|            - CPF do Funcionario:                                              |\n");
    printf("|            - Horario:                                                         |\n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("\t>> Digite ENTER para prosseguir!");
    getchar();
}
void del_reser(void){
    system("clear||cls");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Deletando dados de reserva   .......                  \n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("|            - Informe o ID da reserva:                                         |\n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("\t>> Digite ENTER para prosseguir!");
    getchar();
}