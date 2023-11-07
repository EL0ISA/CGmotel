typedef struct funcionario Funcionario;

struct funcionario {
    char cpf[12];
    char nome[50];
    char email[255];
    char nasc[10];
    int funcao;
    char status;
};

void menu_funcionarios(void);
void cad_func(void);
void grava_func(Funcionario*);
void most_func(Funcionario*);
void list_func(void);
void pesq_func(void);
int encont_func(char cpf[], char ope);
void edit_func(void);
void del_func(void);