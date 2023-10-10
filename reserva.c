#include <stdio.h>
#include <stdlib.h>
#include "reserva.h"
#include "auxiliares.h"

void menu_reservas(void){
    int opc;
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
        scanf("%d",&opc);
        fflush(stdin);
        switch (opc)
            {
            case 1:
                checkin();
                break;
            case 2:
                pesq_reser();
                break;
            case 3:
                checkout();
                break;
            case 4:
                del_reser();
                break;
            }
    } while (opc!=0);
    
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
    char cliente[11],quarto[10],funcionario[11],obs[100];
    int horas=0;
    double padd;
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Cadastrando nova reserva   .......                    \n");
    printf("*-------------------------------------------------------------------------------*\n");
    w_cliente(cliente);
    w_quarto(quarto);
    w_horas(&horas);
    w_obs(obs);
    w_padd(&padd);
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Realizando Check-in   .......                         \n");
    printf("*-------------------------------------------------------------------------------*\n");
    w_funcionario(funcionario);
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