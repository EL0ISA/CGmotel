typedef struct quarto Quarto;

struct quarto {
    int id;
    char identificacao[16];
    char descricao[100];
    double preco;
    int status;
    struct quarto *prox;
};

void menu_quartos(void);
void cad_quart(void);
void grava_quart(Quarto*);
void most_quart(Quarto*);
void list_quart(char ope);
void quart_cli(void);
void pesq_quart(void);
int encont_quart(int id, char ope);
void edit_quart(void);
void del_quart(void);
void relatorios_quart(void);
void list_mais_reser(void);
void gerar_mais_reser(Quarto **list);
int cont_quart(int quarto);
void del_mais_reser(Quarto **list);
void exibir_mais_reser(Quarto *aux);
int cont_q(void);
int criar_id_quar(void);
void bus_quart(char ide[]);