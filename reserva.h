typedef struct reserva Reserva;

struct reserva {
    int id;
    char cliente[12];
    char quarto[10];
    char func_in[12];
    char func_out[12];
    char obs[100];
    int horas;
    double padd;
    char status;
};

void menu_reservas(void);
void pesq_reser(void);
void encont_reser(char cliente[]);
void del_reser(void);
void checkin(void);
void grava_reser(Reserva*);
void most_reser(Reserva*);
void list_reser(void);
int criar_id(void);
void checkout(void);