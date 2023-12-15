typedef struct cliente Cliente;

struct cliente {
    char cpf[12];
    char nome[50];
    char email[255];
    char nasc[11];
    char status;
    struct cliente *prox;
};

void menu_clientes(void);
void cad_cli(void);
void grava_cli(Cliente*);
void most_cli(Cliente*);
void list_cli(char ope);
void pesq_cli(void);
int encont_cli(char cpf[], char ope);
void edit_cli(void);
void del_cli(char cpf[]);
void gerar_list(Cliente**);
void del_list(Cliente**);
void exibir_list(Cliente*);
void exibir_list_alf(Cliente*);
void list_alf(void);
void list_cli_r(void);
void gerar_reser(Cliente**);
int cont_reser(char cliente[]);
void relatorios_cli(void);