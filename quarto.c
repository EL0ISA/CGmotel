#include <stdio.h>
#include <stdlib.h>
#include "quarto.h"

void menu_quartos(void){
    char opc;
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
        printf("|                             5. Monitoramento                                  |\n");
        printf("|                             0. Voltar                                         |\n");
        printf("*-------------------------------------------------------------------------------*\n");
        printf("-- Sua opc: ");
        scanf("%c",&opc);
        while (getchar() != '\n');
        switch (opc)
        {
        case '1':
            cad_quart();
            break;
        case '2':
            pesq_quart();
            break;
        case '3':
            edit_quart();
            break;
        case '4':
            del_quart();
            break;
        case '5':
            monitoramento();
            break;
        }
    } while (opc!='0');
    
}
void cad_quart(void){
    system("clear||cls");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Cadastrando novo quarto   .......                     \n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("|            - Identificacao:                                                   |\n");
    printf("|            - Descricao:                                                       |\n");
    printf("|            - Preco por hora:                                                  |\n");
    printf("|            - Status:                                                          |\n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("\t>> Digite ENTER para prosseguir!");
    getchar();
}
void pesq_quart(void){
    system("clear||cls");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Pesquisando dados de quarto   .......                 \n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("|            - Informe a identificacao do quarto:                               |\n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("\t>> Digite ENTER para prosseguir!");
    getchar();
}
void edit_quart(void){
    system("clear||cls");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Atualizando dados de quarto   .......                 \n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("|            - Informe a identificacao do quarto:                               |\n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("\t>> Digite ENTER para prosseguir!");
    getchar();
}
void del_quart(void){
    system("clear||cls");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Deletando dados de quarto   .......                   \n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("|            - Informe a identificacao do quarto:                               |\n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("\t>> Digite ENTER para prosseguir!");
    getchar();
}
void monitoramento(void){
    char opc;
    do
    {
        system("clear||cls");
        printf("\n*-------------------------------------------------------------------------------*\n");
        printf("*                               Monitoramento                                   *\n");
        printf("*-------------------------------------------------------------------------------*\n");
        printf("|                             1. Quartos disponiveis                            |\n");
        printf("|                             2. Quartos em manutencao                          |/\n");
        printf("|                             3. Quartos para limpar                            |\n");
        printf("|                             0. Voltar                                         |\n");
        printf("*-------------------------------------------------------------------------------*\n");
        printf("-- Sua opc: ");
        scanf("%c",&opc);
        while (getchar() != '\n');
        switch (opc)
            {
            case '1':
                system("clear||cls");
                printf("*-------------------------------------------------------------------------------*\n");
                printf("                 .......   Listando quartos os disponiveis   .......                \n");
                printf("*-------------------------------------------------------------------------------*\n");
                printf("|   Identificacao           -    Preco por Hora                                 |\n");
                printf("*-------------------------------------------------------------------------------*\n");
                printf("|   27E                     -    R$ 55                                          |\n");
                printf("*-------------------------------------------------------------------------------*\n");
                printf("\t>> Digite ENTER para prosseguir!");
                getchar();
                break;
            case '2':
                system("clear||cls");
                printf("*-------------------------------------------------------------------------------*\n");
                printf("                 .......   Listando quartos em manutencao   .......              \n");
                printf("*-------------------------------------------------------------------------------*\n");
                printf("|   Identificacao           -    Preco por Hora                                 |\n");
                printf("*-------------------------------------------------------------------------------*\n");
                printf("|   27E                     -    R$ 55                                          |\n");
                printf("*-------------------------------------------------------------------------------*\n");
                printf("\t>> Digite ENTER para prosseguir!");
                getchar();
                break;
            case '3':
                system("clear||cls");
                printf("*-------------------------------------------------------------------------------*\n");
                printf("                 .......   Listando quartos para limpeza   .......              \n");
                printf("*-------------------------------------------------------------------------------*\n");
                printf("|   Identificacao           -    Preco por Hora                                 |\n");
                printf("*-------------------------------------------------------------------------------*\n");
                printf("|   27E                     -    R$ 55                                          |\n");
                printf("*-------------------------------------------------------------------------------*\n");
                printf("\t>> Digite ENTER para prosseguir!");
                getchar();
                break;
            }
    } while (opc!='0');
    
}