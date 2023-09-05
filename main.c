#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define true 1
#define false 0

void inicio(void);
void cabecalho(void);
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

void menu_quartos(void);
void cad_quart(void);
void pesq_quart(void);
void edit_quart(void);
void del_quart(void);
void monitoramento(void);

void menu_reservas(void);
void cad_reser(void);
void pesq_reser(void);
void edit_reser(void);
void del_reser(void);
void checkin(void);
void checkout(void);

int main(void) {
    setlocale(LC_ALL,"Portuguese_Brazil");
    inicio();
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
        case '3':
            menu_quartos();
            break;
        case '4':
            menu_reservas();
            break;
        case '5':
            sobre();
            break;
        }
    } while ((op)!='0');
    
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
    printf("|               Desenvolvido por Mª Eloisa da Silva Santos (@EL0ISA)            |\n");
    printf("*-------------------------------------------------------------------------------*\n");
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
char menu_principal(void){
    char opc;
    printf("*-------------------------------------------------------------------------------*\n");
    printf("|                               Gestao do Motel                                 |\n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("|                               1. Clientes                                     |\n");
    printf("|                               2. Funcionarios                                 |\n");
    printf("|                               3. Quartos                                      |\n");
    printf("|                               4. Reservas                                     |\n");
    printf("|                               5. Sobre o projeto                              |\n");
    printf("|                               0. Sair                                         |\n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("-- Sua opc: ");
    scanf(" %c",&opc);
    return opc;
}

void menu_clientes(void){
    char opc='1';
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
        while (getchar() != '\n');
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
    char cpf[11],nome[50],email[100],nasc[20];
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Cadastrando novo cliente   .......                    \n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("|            - CPF (apenas numeros):");
    scanf("%s",cpf);
    while (getchar() != '\n'); /*limpando buffer by chatGPT*/ 
    printf("|            - Nome completo: ");
    scanf("%s",nome);
    while (getchar() != '\n');
    printf("|            - E-mail: ");
    scanf("%s",email);
    while (getchar() != '\n');
    printf("|            - Data de Nascimento (dd/mm/aaaa): ");
    scanf("%s",nasc);
    while (getchar() != '\n');
    printf("*-------------------------------------------------------------------------------*\n");
    printf("\t>> Digite ENTER para prosseguir!");
    getchar();
}
void pesq_cli(void){
    system("clear||cls");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Pesquisando dados de cliente   .......                \n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("|            - Informe o CPF (apenas numeros):                                  |\n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("\t>> Digite ENTER para prosseguir!");
    getchar();
}
void edit_cli(void){
    system("clear||cls");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Atualizando dados de cliente   .......                \n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("|            - Informe o CPF (apenas numeros):                                  |\n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("\t>> Digite ENTER para prosseguir!");
    getchar();
}
void del_cli(void){
    system("clear||cls");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Deletando cliente   .......                           \n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("|            - Informe o CPF (apenas numeros):                                  |\n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("\t>> Digite ENTER para prosseguir!");
    getchar();
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
        while (getchar() != '\n');
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
    printf("|            - CPF (apenas numeros):                                            |\n");
    printf("|            - Nome completo:                                                   |\n");
    printf("|            - E-mail:                                                          |\n");
    printf("|            - Data de Nascimento (dd/mm/aaaa):                                 |\n");
    printf("|            - Funcao:                                                          |\n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("\t>>");
    getchar();
}
void pesq_func(void){
    system("clear||cls");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Pesquisando dados de funcionario   .......            \n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("|            - Informe o CPF (apenas numeros):                                  |\n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("\t>> Digite ENTER para prosseguir!");
    getchar();
}
void edit_func(void){
    system("clear||cls");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Atualizando dados de funcionario   .......            \n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("|            - Informe o CPF (apenas numeros):                                  |\n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("\t>> Digite ENTER para prosseguir!");
    getchar();
}
void del_func(void){
    system("clear||cls");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Deletando funcionario   .......                       \n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("|            - Informe o CPF (apenas numeros):                                  |\n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("\t>> Digite ENTER para prosseguir!");
    getchar();
}

void menu_quartos(void){
    char menu=true;
    char opc;
    while (menu)
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
        case '0':
            menu=false;
            break;
        case '1':
            cad_quart();
            break;
        case '2':
            pesq_cli();
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
    }
    
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
    char menu=true;
    char opc;
    while(menu){
        system("clear||cls");
        printf("\n*-------------------------------------------------------------------------------*\n");
        printf("*                               Monitoramento                                   *\n");
        printf("*-------------------------------------------------------------------------------*\n");
        printf("|                             1. Quartos disponiveis                            |\n");
        printf("|                             2. Quartos em manutenção                          |/\n");
        printf("|                             3. Quartos para limpar                            |\n");
        printf("|                             0. Voltar                                         |\n");
        printf("*-------------------------------------------------------------------------------*\n");
        printf("-- Sua opc: ");
        scanf("%c",&opc);
        while (getchar() != '\n');
        switch (opc)
            {
            case '0':
                menu=false;
                break;
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
                printf("                 .......   Listando quartos em manutenção   .......              \n");
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
    }
}

void menu_reservas(void){
    char menu=true;
    char opc;
    while (menu)
    {
        system("clear||cls");
        printf("\n*-------------------------------------------------------------------------------*\n");
        printf("*                               Menu Reservas                                   *\n");
        printf("*-------------------------------------------------------------------------------*\n");
        printf("|                             1. Cadastrar nova                                 |\n");
        printf("|                             2. Pesquisar                                      |\n");
        printf("|                             3. Atualizar                                      |\n");
        printf("|                             4. Deletar reserva                                |\n");
        printf("|                             0. Voltar                                         |\n");
        printf("*-------------------------------------------------------------------------------*\n");
        printf("-- Sua opc: ");
        scanf("%c",&opc);
        while (getchar() != '\n');
        switch (opc)
            {
            case '0':
                menu=false;
                break;
            case '1':
                cad_reser();
                break;
            case '2':
                pesq_reser();
                break;
            case '3':
                edit_reser();
                break;
            case '4':
                del_reser();
                break;
            }
    }
}
void cad_reser(void){
    system("clear||cls");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Cadastrando nova reserva   .......                    \n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("|            - CPF do cliente:                                                  |\n");
    printf("|            - Identificação do quarto:                                         |\n");
    printf("|            - Horas de reserva:                                                |\n");
    printf("|            - Observações:                                                     |\n");
    printf("|            - Custos adicionais:                                               |\n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("\t>> Digite ENTER para prosseguir!");
    getchar();
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
void edit_reser(void){
    char opc;
    system("clear||cls");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Atualizando dados de reserva   .......                \n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("|            - Informe o ID da reserva:                                         |\n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("                 .......   Operação que deseja realizar   .......                \n");
    printf("*-------------------------------------------------------------------------------*\n");
    printf("|                             1. Check-in                                       |\n");
    printf("|                             2. Check-out                                      |\n");
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
        checkout();
        break;
    }
}
void checkin(void){
    system("clear||cls");
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