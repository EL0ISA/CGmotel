typedef struct cliente Cliente;

struct cliente {
    char cpf[12];
    char nome[50];
    char email[255];
    char nasc[11];
    char status;
};

void menu_clientes(void);
void cad_cli(void);
void grava_cli(Cliente*);
void most_cli(Cliente*);
void list_cli(void);
void pesq_cli(void);
int encont_cli(char cpf[], char ope);
void edit_cli(void);
void del_cli(char cpf[]);
