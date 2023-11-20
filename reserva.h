typedef struct reserva Reserva;

struct reserva {
    int id;
    char cliente[12];
    char quarto[10];
    char func_in[12];
    char func_out[12];
    char hora_in[20];
    char hora_out[20];
    char obs[100];
    int horas;
    double padd;
    double ptotal;
    char status;
};

void menu_reservas(void);
void pesq_reser(void);
void encont_reser(char cliente[]);
int bus_id_reser(int id, char ope);
void del_reser(void);
void checkin(void);
void grava_reser(Reserva*);
void most_reser(Reserva*);
void list_reser(char ope);
int criar_id(void);
void checkout(void);
void status_quart(char ide[],int ope);
int cli_out(char cliente[]);