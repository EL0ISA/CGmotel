void menu_funcionarios(void);
void cad_func(void);
void pesq_func(void);
void edit_func(void);
void del_func(void);

typedef struct funcionario Funcionario;

struct funcionario {
    char cpf[11];
    char nome[50];
    char email[255];
    char nasc[10];
    int funcao;
};