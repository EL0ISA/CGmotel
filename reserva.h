void menu_reservas(void);
void pesq_reser(void);
void del_reser(void);
void checkin(void);
void checkout(void);

typedef struct reserva Reserva;

struct reserva {
    char cliente[11];
    char quarto[10];
    char funcionario[11];
    char obs[100];
    int horas;
    double padd;
};