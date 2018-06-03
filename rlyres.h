#ifndef RLYRES_H_INCLUDED
#define RLYRES_H_INCLUDED

struct train
{
    char train_no[10];
    char from[10];
    char to[10];
    int fac_fare ;
    int sac_fare ;

};
struct passenger
{
    char p_name[20];
    char gender ;
    char mob_no[10] ;
    int age ;
    char train_no[20];
    char p_class ;
    char address[30];
    int ticketno ;
};
typedef struct train train ;
typedef struct passenger passenger ;
int search_ticket(char* );
int check_booking(char* , char*);
int last_ticket_no();
char get_pGen();
char* get_pname();
char *get_pmob();
int get_pAge();
char* get_trainNo();
char get_pClass();
int enterchoice();
void add_trains();
void view_trains();
int book_ticket(passenger);
int* get_ticket_no(char *);
void view_ticket(int);
void view_all_bookings();
void view_booking(char *);
int cancel_ticket(int);
int cancel_train(char *);
passenger get_details();



#endif // RLYRES_H_INCLUDED
