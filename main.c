#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

void inicio(void);
void sobre(void);
char menu_principal(void);

void menu_clientes(void);
void cad_cli(void);
void pesq_cli(void);
void edit_cli(void);
void del_cli(void);

void menu_funcionarios(void);
void cad_func(void);
void pesq_func(void);
void edit_func(void);
void del_func(void);

int main(void) {
    inicio();
    sobre();
    char op;
    do
    {
        system("clear||cls");
        op=menu_principal();
        switch (op)
        {
        case '1':
            menu_clientes();
            break;
        
        case '2':
            menu_funcionarios();
            break;
        }
    } while ((op)!='0');
    
    printf("%c",op);
    return 0;
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
char menu_principal(void){
    char opc;
    printf("*-------------------------------------------------------------------------------*\n");
    printf("|                               Gestão do Motel                                |\n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("|                               1. Clientes                                     |\n");
    printf("|                               2. Funcionarios                                 |\n");
    printf("|                               3. Quartos                                      |\n");
    printf("|                               4. Reservas                                     |\n");
    printf("|                               0. Sair                                         |\n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("-- Sua opc: ");
    scanf("%c",&opc);
    return opc;
}

void menu_clientes(void){
    char opc;
    char menu=true;
    while (menu)
    {
        system("clear||cls");
        printf("\n*-------------------------------------------------------------------------------*\n");
        printf("*                               Menu Clientes                                   *\n");
        printf("*-------------------------------------------------------------------------------*\n");
        printf("|                             1. Cadastrar novo                                 |\n");
        printf("|                             2. Pesquisar dados                                |\n");
        printf("|                             3. Atualizar dados                                |\n");
        printf("|                             4. Deletar cliente                                |\n");
        printf("|                             0. Voltar                                         |\n");
        printf("*-------------------------------------------------------------------------------*\n");
        printf("-- Sua opc: ");
        scanf("%c",&opc);
        switch (opc)
        {
        case '0':
            menu=false;
            break;
        case '1':
            cad_cli();
            break;
        
        case '2':
            pesq_cli();
            break;
        case '3':
            edit_cli();
            break;
        case '4':
            del_cli();
            break;
        }
    }
    
}
void cad_cli(void){
    system("clear||cls");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Cadastrando novo cliente   .......                    \n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("|            - CPF (apenas números):                                            |\n");
    printf("|            - Nome completo:                                                   |\n");
    printf("|            - E-mail:                                                          |\n");
    printf("|            - Data de Nascimento (dd/mm/aaaa):                                 |\n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("\t>>");
    system("PAUSE");
}
void pesq_cli(void){
    system("clear||cls");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Pesquisando dados de cliente   .......                \n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("|            - Informe o CPF (apenas números):                                  |\n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("\t>>");
    system("PAUSE");
}
void edit_cli(void){
    system("clear||cls");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Atualizando dados de cliente   .......                \n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("|            - Informe o CPF (apenas números):                                  |\n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("\t>>");
    system("PAUSE");
}
void del_cli(void){
    system("clear||cls");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Deletando cliente   .......                           \n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("|            - Informe o CPF (apenas números):                                  |\n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("\t>>");
    system("PAUSE");
}

void menu_funcionarios(void){
    char opc;
    char menu=true;
    while (menu)
    {
        system("clear||cls");
        printf("*-------------------------------------------------------------------------------*\n");
        printf("*                               Menu Funcionarios                               *\n");
        printf("*-------------------------------------------------------------------------------*\n");
        printf("|                             1. Cadastrar novo                                 |\n");
        printf("|                             2. Pesquisar dados                                |\n");
        printf("|                             3. Atualizar dados                                |\n");
        printf("|                             4. Deletar funcionario                            |\n");
        printf("|                             0. Voltar                                         |\n");
        printf("*-------------------------------------------------------------------------------*\n");
        printf("-- Sua opc: ");
        scanf("%c",&opc);
        switch (opc)
            {
            case '0':
                menu=false;
                break;
            case '1':
                cad_func();
                break;
            
            case '2':
                pesq_func();
                break;
            case '3':
                edit_func();
                break;
            case '4':
                del_func();
                break;
            }
    }
}
void cad_func(void){
    system("clear||cls");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Cadastrando novo funcionario   .......                \n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("|            - CPF (apenas números):                                            |\n");
    printf("|            - Nome completo:                                                   |\n");
    printf("|            - E-mail:                                                          |\n");
    printf("|            - Data de Nascimento (dd/mm/aaaa):                                 |\n");
    printf("|            - Função:                                                          |\n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("\t>>");
    system("PAUSE");
}
void pesq_func(void){
    system("clear||cls");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Pesquisando dados de funcionario   .......            \n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("|            - Informe o CPF (apenas números):                                  |\n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("\t>>");
    system("PAUSE");
}
void edit_func(void){
    system("clear||cls");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Atualizando dados de funcionario   .......            \n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("|            - Informe o CPF (apenas números):                                  |\n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("\t>>");
    system("PAUSE");
}
void del_func(void){
    system("clear||cls");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Deletando funcionario   .......                       \n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("|            - Informe o CPF (apenas números):                                  |\n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("\t>>");
    system("PAUSE");
}

