typedef struct funcionario Funcionario;

struct funcionario {
    char cpf[12];
    char nome[50];
    char email[255];
    char nasc[10];
    int funcao;
    char status;
    struct funcionario *prox;
};

void menu_funcionarios(void);
void cad_func(void);
void grava_func(Funcionario*);
void most_func(Funcionario*);
void list_func(char ope);
void pesq_func(void);
int encont_func(char cpf[], char ope);
void edit_func(void);
void del_func(void);
void gerar_list_fun(Funcionario**);
void del_list_fun(Funcionario**);
void exibir_list_fun(Funcionario*);
void list_fun_alf(void);
void list_fun_r(void);
void gerar_reser_fun(Funcionario **list);
int cont_reser_fun(char funcionario[]);