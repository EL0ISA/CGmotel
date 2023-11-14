typedef struct quarto Quarto;

struct quarto {
    char identificacao[10];
    char descricao[100];
    double preco;
    int status;
};

void menu_quartos(void);
void cad_quart(void);
void grava_quart(Quarto*);
void most_quart(Quarto*);
void list_quart(void);
char* preco(char* precoTrunc, size_t tamP);
void pesq_quart(void);
int encont_quart(char ide[], char ope);
void edit_quart(void);
void del_quart(void);
void monitoramento(void);
