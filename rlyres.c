#include "rlyres.h"
#include<stdio.h>
#include "conio2.h"
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int enterchoice()
{
    int choice , i;
    textcolor(CYAN);
    gotoxy(28,2);
    printf("RAILYWAY RESERVATION SYSTEM\n");
    for(i=0;i<90;i++)
        printf("_");
        printf("\nSelect an Option\n");
        printf("1- View Trains\n2- Book Tickets\n3- View Ticket\n4- Search Ticket No\n5- View All Bookings\n6- View Train Bookings\n7- Cancel Ticket\n8- Cancel Train\n9- QUIT");
        printf("\nEnter Choice  ");

        scanf("%d",&choice);
    return choice ;

}
void add_trains()
{
    FILE *fp ;
    fp = fopen("e:\\c programsss\\reFiles\\alltrains.dat","rb");
    if(fp == NULL)
    {
    fp = fopen("e:\\c programsss\\reFiles\\alltrains.dat","wb");
    train t[4] ={
        {"123","BPL","GWA",2100,1500},
        {"546","BPL","DEL",3500,2240},
        {"345","HBJ","AGR",1560,1135},
        {"896","HBJ","MUM",4500,3360}
    };
    fwrite(&t,4*sizeof(train),1,fp);
    fclose(fp);
    }
    else

        fclose(fp);

}
void view_trains()
{
    FILE *fp ;
    clrscr();
    fp = fopen("e:\\c programsss\\reFiles\\alltrains.dat","rb");
    train  t ;
    int i ;
textcolor(GREEN);
    printf("\n Train no. | From |  To   | first Ac fare | Second Ac fare\n");
    for(i=0;i<90;i++)
        printf("_");
    while(fread(&t,sizeof(train),1,fp) == 1)
        printf("    %s    |  %s |  %s  |      %d     | %d\n\n",t.train_no,t.from,t.to,t.fac_fare,t.sac_fare);
}
int book_ticket(passenger q)
{

if(check_booking(&q.train_no,&q.p_class) >=2)
{
    printf("\nSorry All Tickets are Booked\n");
    return 0;
}
    FILE *fp ;
    fp = fopen("e:\\c programsss\\reFiles\\trains.dat","ab+");

    if(fp == NULL)
    {
        fp =fopen("e:\\c programsss\\reFiles\\trains.dat","wb");
        fclose(fp);
        fp = fopen("e:\\c programsss\\reFiles\\trains.dat","ab+");
    }
    fwrite(&q,sizeof(passenger),1,fp);
    fclose(fp);
    textcolor(BROWN);
    printf("Your Ticket succesfully Booked\n");
    printf("Your Ticket is\nTicket no. = %d\nName = %s \nGen = %c\nMob No. = %s\nAge = %d\nTran No. = %s\nClass = %c\nAdd. = %s",q.ticketno,q.p_name,q.gender,q.mob_no,q.age,q.train_no,q.p_class,q.address);

    return q.ticketno;
}
passenger get_details()
{
 static passenger p ;
  strcpy(p.p_name,get_pname());
     p.gender  = get_pGen();
     strcpy(p.mob_no,get_pmob());
     p.age= get_pAge();
     strcpy(p.train_no,get_trainNo());
     p.p_class = get_pClass();
     printf("Enter address:");
     fflush(stdin);
     fgets(p.address,30,stdin);
     int *pos = strchr(p.address,'\n');
     *pos = '\0';
     if(strcmp(p.address,"0")==0)
     {
         textcolor(RED);
         gotoxy(20,25);
         printf("RESERVATION CANCLED");
         _getch();
         textcolor(CYAN);
         clrscr();
         main();
     }
     p.ticketno= last_ticket_no();
     return p ;
}

char *get_pname()
{
   clrscr();
      static char name[20];
     printf("Enter name:");
     gotoxy(60,1);
     textcolor(GREEN);
     printf("Press 0 to Exit");
     textcolor(CYAN);
     gotoxy(12,1);
     fflush(stdin);
     fgets(name,20,stdin);
     int *pos = strchr(name,'\n');
     *pos = '\0';
     if(name[0] == '0')
     {
        clrscr();
        gotoxy(20,27);
         textcolor(RED);
         printf("Reservation canceled");
         _getch();
         clrscr();
        main();
     }
        else
            return name ;
}
char get_pGen()
{
    textcolor(CYAN);
    char gen ;
    printf("Enter Gender(M/F):");
    while(1)
    {
        textcolor(CYAN);
    fflush(stdin);
     scanf("%c",&gen);
     if(gen == '0')
     {
         clrscr();
         gotoxy(20,27);
         textcolor(RED);
         printf("Reservation canceled");
         _getch();
         clrscr();
        main();
     }
        if(gen == 'M' || gen == 'F')
            return gen ;
     else
     {
         gotoxy(20,27);
         textcolor(RED);
         printf("Enter a valid choice! and try again");
         _getch();
         gotoxy(20,27);
         printf("                                     \b");
         gotoxy(19,2);
         printf(" \b");

     }
    }
}
char *get_pmob()
{
    char mob[11];
    printf("Enter your Mobile no. :");
    while(1){
            textcolor(CYAN);
            int b = 0 ;
    fflush(stdin);
    fgets(mob,11,stdin);
    int *pos = strchr(mob,'\n');
    if(pos != NULL)
    *pos = '\0';
    if(mob[0] == '0')
    {
clrscr();
 gotoxy(20,27);
         textcolor(RED);
         printf("Reservation canceled");
         _getch();
         clrscr();
main();
    }
    if(strlen(mob)!= 10)
    {
        gotoxy(20,27);
        textcolor(RED);
        printf("enter a valid number");
        _getch();
        fflush(stdin);
        gotoxy(20,27);
        printf("\t\t\t\t\t \b");
        gotoxy(24,3);
        printf("\t\t\t\t  \b");
        gotoxy(24,3);
    }
    else if(strlen(mob) == 10)
    {
        int i =0 ;
    while(mob[i] != '\0')
    {
        if(!isdigit(mob[i]))
        {
            gotoxy(20,27);
        textcolor(RED);
        printf("enter a valid number");
        _getch();
        fflush(stdin);
        gotoxy(20,27);
        printf("\t\t\t\t\t \b");
        gotoxy(24,3);
        printf("\t\t\t\t  \b");
        gotoxy(24,3);
        b=1 ;
        break ;
        }
        else
            b= 0 ;
        i++;
    }

    }
    if(b == 0 && strlen(mob)== 10)
        return mob ;
    }
}
int get_pAge()
{

    int age;
    printf("Enter your Age :");
    while(1)
    {
        textcolor(CYAN);
    scanf("%d",&age);
    if(age == 0)
    {
clrscr();
 gotoxy(20,27);
         textcolor(RED);
         printf("Reservation canceled");
         _getch();
         clrscr();
main();
    }
    else if(age <= 0)
    {
        gotoxy(20,27);
        textcolor(RED);
        printf("ENTER A VALID AGE");
        _getch();
        fflush(stdin);
        gotoxy(20,27);
        printf("\t \t \t \t \t \b");
        gotoxy(17,4);
        printf("\t\t\t\t \b");
        gotoxy(17,4);
    }
    else
        return age ;
}
}
char *get_trainNo()
{
    char trainNo[10];
    printf("Enter your train no.: ");
    while(1)
    {
        textcolor(CYAN);
   fflush(stdin);
    fgets(trainNo,10,stdin);
    int *pos = strchr(trainNo,'\n');
    *pos = '\0';
    if(trainNo[0] == '0')
    {
clrscr();
 gotoxy(20,27);
         textcolor(RED);
         printf("Reservation canceled");
         _getch();
         clrscr();
main();
    }
    FILE *fp ;
    train tr;
    fp = fopen("e:\\c programsss\\reFiles\\alltrains.dat","rb");
    while(fread(&tr,sizeof(train),1,fp)==1)
    {
        if(!strcmpi(trainNo,tr.train_no))
        {

        fclose(fp);
            return tr.train_no;
    }
    }
    fclose(fp);
         gotoxy(20,27);
         textcolor(RED);
         printf("Enter a valid Train Number! and try again");
         _getch();
         gotoxy(20,27);
         printf("                                          ");
         gotoxy(22,5);
         printf("\t \t \t \t ");
              gotoxy(22,5);

    }
}
char get_pClass()
{


    char clss;
    printf("Enter your class(F(First)/S(second):");
    while(1)
    {
        textcolor(CYAN);
    scanf("%c",&clss);
    if(clss == '0')
    {
clrscr();
 gotoxy(20,27);
         textcolor(RED);
         printf("Reservation canceled");
         _getch();
         clrscr();
main();
    }
    else if(clss == 'F' || clss == 'S')
        return clss ;
        else
        {

             gotoxy(20,27);
         textcolor(RED);
         printf("Enter a valid choice! and try again");
         fflush(stdin);
          gotoxy(20,27);
          _getch();
          printf("\t \t \t \t \t \b");
         gotoxy(37,6);
         printf(" \b");

        }
    }
}

int last_ticket_no()
{
    FILE *fp ;
    passenger no ;
    fp = fopen("e:\\c programsss\\reFiles\\trains.dat","rb");
    if(fp == NULL || fread(&no,sizeof(passenger),1,fp)!=1)
        return 1 ;

    fseek(fp,-sizeof(int),SEEK_END);
    fread(&no.ticketno,sizeof(int),1,fp);
    fclose(fp);
    no.ticketno = no.ticketno +1;
    return no.ticketno ;
}
int check_booking(char* trainno,char* cls)
{

    char cl[10] , trai[10];
    strcpy(cl,cls);
    strcpy(trai,trainno);
    FILE *fp ;
    int count =  0 ;
    passenger pr ;
    fp = fopen("e:\\c programsss\\reFiles\\trains.dat","rb");
    if(fp == NULL || fread(&pr,sizeof(passenger),1,fp)!=1)
        return 0 ;
        rewind(fp);
        while(fread(&pr,sizeof(passenger),1,fp)==1)
        {
            if((strcmp(pr.train_no,trai)==0) && (pr.p_class == cl[0])){
                count++ ;

        }
        }
        fclose(fp);
        return count ;
}
void view_ticket(int no)
{
    FILE *fp,*ft ;
    passenger q ;
   fp = fopen("e:\\c programsss\\reFiles\\trains.dat","rb");
ft = fopen("e:\\c programsss\\reFiles\\alltrains.dat","rb");
if(fp == NULL || ft == NULL ||  fread(&q,sizeof(passenger),1,fp)!=1){
    printf("Sorry there are no bookings with this ticket");
    printf("\nPress enter to continue");
    _getch();
    main();
}
int b = 0 ;

        train t ;
        int fare ;
        rewind(fp);
        while(fread(&q,sizeof(passenger),1,fp)==1)
        {
            if(q.ticketno == no){

                    while(fread(&t,sizeof(train),1,ft) == 1)
                    {
                        if(strcmp(t.train_no,q.train_no)==0 && q.p_class == 'F'){
                            fare =t.fac_fare;
                            break ;
                        }
                        else if(strcmp(t.train_no,q.train_no)==0 && q.p_class == 'S'){
                            fare =t.sac_fare;
                            break;
                        }
                    }
printf("Your Ticket is \nName = %s \nGen = %c\nMob No. = %s\nAge = %d\nTran No. = %s\nClass = %c\nAdd. = %s\nFrom = %s\nTo = %s\nFare = %d",q.p_name,q.gender,q.mob_no,q.age,q.train_no,q.p_class,q.address,t.from,t.to,fare);
b=0;
break ;
            }
          else
                b = 1 ;
        }
        fclose(fp);
        fclose(ft);
        if(b==1)
            printf("\n\t \t You have No ticket with this no.");
            printf("\n Press Enter to continue");
_getch();
}
int search_ticket(char* mob )
{
 FILE *fp ;
 passenger pr ;

    if(strlen(mob)!= 10)
    {
        gotoxy(20,27);
        textcolor(RED);
        printf("enter a valid number");
        _getch();
        fflush(stdin);
        gotoxy(20,27);
        printf("\t\t\t\t\t \b");
        return -1 ;
    }
    else if(strlen(mob) == 10)
    {
        int i =0 ;
    while(mob[i] != '\0')
    {
        if(!isdigit(mob[i]))
        {
            gotoxy(20,27);
        textcolor(RED);
        printf("enter a valid number");
        _getch();
        fflush(stdin);
        gotoxy(20,27);
        printf("\t\t\t\t\t \b");
        return -1 ;
        }
        i++;
    }

    }
 fp = fopen("e:\\c programsss\\reFiles\\trains.dat","rb");
if(fp==NULL || fread(&pr,sizeof(passenger),1,fp)!=1)
    return 0 ;
    rewind(fp);
while(fread(&pr,sizeof(passenger),1,fp)==1)
{
    if(strcmp(pr.mob_no,mob) == 0){
        fclose(fp);
        return pr.ticketno ;
    }
}
return 0 ;
    }

void view_all_bookings()
{
    clrscr();
    FILE *fp ;
     passenger q ;
    fp = fopen("e:\\c programsss\\reFiles\\trains.dat","rb");

     if(fp==NULL || fread(&q,sizeof(passenger),1,fp)!=1){
            printf("Sorry there are no bookings");
    return 0 ;
     }
    rewind(fp);
    textcolor(YELLOW);
     printf("Train no. |     Name     | Ticket no. | Mobile Number | Age |  Gen | Class | Address\n");
     int i ;
     for(i=0 ; i<90 ; i++)
        printf("_");
        i=0;
     while(fread(&q,sizeof(passenger),1,fp)==1)
     {
         gotoxy(1,5+i);
 printf("%s",q.train_no);
 gotoxy(13,5+i);
 printf("%s",q.p_name);
gotoxy(32,5+i);
 printf("%d",q.ticketno);
 gotoxy(42,5+i);
  printf("%s",q.mob_no);
  gotoxy(57,5+i);
   printf("%d",q.age);
   gotoxy(65,5+i);
    printf("%c",q.gender);
    gotoxy(72,5+i);
     printf("%c",q.p_class);
     gotoxy(79,5+i);
      printf("%s",q.address);
      i=i+2;
     }

     fclose(fp);
}
void view_booking(char* trn)
{

    FILE *fp ;
    fp = fopen("e:\\c programsss\\reFiles\\trains.dat","rb");
 passenger q ;
     if(fp==NULL || fread(&q,sizeof(passenger),1,fp)!=1 ){
            printf("\nSorry there are no bookings in this train");
     printf("\n press Enter to continue");
     _getch();
    return 0 ;
     }
    rewind(fp);
     int b = 0;
     gotoxy(1,3);
     textcolor(YELLOW);
      printf("\n\nTrain no. |     Name     | Ticket no. | Mobile Number | Age |  Gen | Class | Address\n");
     int i ;
     for(i=0 ; i<90 ; i++)
        printf("_");
        i=0 ;
     while(fread(&q,sizeof(passenger),1,fp)==1)
     {
if(strcmp(q.train_no,trn)==0){
        b=1;
       gotoxy(1,8+i);
 printf("%s",q.train_no);
 gotoxy(13,8+i);
 printf("%s",q.p_name);
gotoxy(32,8+i);
 printf("%d",q.ticketno);
 gotoxy(42,8+i);
  printf("%s",q.mob_no);
  gotoxy(57,8+i);
   printf("%d",q.age);
   gotoxy(65,8+i);
    printf("%c",q.gender);
    gotoxy(72,8+i);
     printf("%c",q.p_class);
     gotoxy(79,8+i);
      printf("%s",q.address);
      i=i+2;
}
     }
     fclose(fp);
if(b==0)
    printf("\nSorry there are no bookings in this train number %s",trn);
printf("\n\nPress Enter to continue ");
     _getch();

}
int cancel_ticket(int ticket_no)
{
    FILE *fp , *fc ;
    passenger pr , qr ;
    fp = fopen("e:\\c programsss\\reFiles\\trains.dat","rb+");
    fc = fopen("e:\\c programsss\\reFiles\\trains1.dat","wb+");
    if(fp==NULL || fc ==NULL || fread(&pr,sizeof(passenger),1,fp)!=1 )
        return 0 ;
       rewind(fp);
    while(fread(&pr,sizeof(passenger),1,fp)==1)
    {
        if(pr.ticketno == ticket_no)
        {
            rewind(fp);
            int i ;
            for(i=0;fread(&qr,sizeof(passenger),1,fp)==1;i++)
            {
                if(qr.ticketno != ticket_no)
            fwrite(&qr,sizeof(passenger),1,fc);
            }
            fclose(fp);
            fclose(fc);
remove("e:\\c programsss\\reFiles\\trains.dat");
rename("e:\\c programsss\\reFiles\\trains1.dat","e:\\c programsss\\reFiles\\trains.dat");
            return 1 ;
        }
    }


  return 0 ;
}
int cancel_train(char* trn)
{
    FILE *fp , *fc ;
     passenger pr , qr ;
    fp = fopen("e:\\c programsss\\reFiles\\trains.dat","rb+");
    fc = fopen("e:\\c programsss\\reFiles\\trains1.dat","wb+");
    if(fp==NULL || fc ==NULL ||fread(&pr,sizeof(passenger),1,fp)!=1)
        return 0 ;
       rewind(fp);
        while(fread(&pr,sizeof(passenger),1,fp)==1)
    {
        if(strcmp(pr.train_no,trn)==0)
        {
            rewind(fp);
            int i ;
            for(i=0;fread(&qr,sizeof(passenger),1,fp)==1;i++)
            {
                if(strcmp(qr.train_no,trn) != 0)
            fwrite(&qr,sizeof(passenger),1,fc);
            }
            fclose(fp);
            fclose(fc);
remove("e:\\c programsss\\reFiles\\trains.dat");
rename("e:\\c programsss\\reFiles\\trains1.dat","e:\\c programsss\\reFiles\\trains.dat");
            return 1 ;
        }
    }

}
