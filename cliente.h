void menu_clientes(void);
void cad_cli(void);
void pesq_cli(void);
void edit_cli(void);
void del_cli(void);

typedef struct cliente Cliente;

struct cliente {
    char cpf[11];
    char nome[50];
    char email[255];
    char nasc[10];
};
