void menu_quartos(void);
void cad_quart(void);
void pesq_quart(void);
void edit_quart(void);
void del_quart(void);
void monitoramento(void);

typedef struct quarto Quarto;

struct quarto {
    char identificacao[10];
    char descricao[100];
    double preco;
    int status;
};