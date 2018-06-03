#include <stdio.h>
#include <stdlib.h>
#include "rlyres.h"
#include "conio2.h"

int main()
{
  int ch ,no;
  add_trains();
  while(1)
      {
          clrscr();
  ch = enterchoice();
 switch(ch)
 {
     case 1 : view_trains();
     textcolor(CYAN);
         printf("\nPress Enter to continue ");
         _getch();
         clrscr();
          break ;


     case 2 :{
          book_ticket(get_details());
textcolor(CYAN);
printf("\nPress Enter to continue");
_getch();

         break ;
     }
     case 3 :{
         clrscr();
         gotoxy(73,1);
textcolor(GREEN);
printf("Press 0 to go back");
textcolor(CYAN);
gotoxy(1,1);
         printf("enter ticket no :");
     int nu ;

     while(1){
            textcolor(CYAN);
            scanf("%d",&nu);
      if(nu < 0 )
    {
        gotoxy(20,27);
        textcolor(RED);
        printf("ENTER A VALID TICKET NUMBER");
        _getch();
        fflush(stdin);
        gotoxy(20,27);
        printf("\t \t \t \t \t \b");
        gotoxy(18,1);
        printf("\t\t\t\t \b");
        gotoxy(18,1);
    }
    else if(nu > 0){
     view_ticket(nu);
     break ;
    }
    else if(nu == 0)
        break ;

     }
     break ;
     }
     case 4 : {
         while(1){
         clrscr();
             char mob[12];
             gotoxy(73,1);
textcolor(GREEN);
printf("Press 0 to go back");
textcolor(LIGHTGRAY);
gotoxy(1,1);
          printf("Enter Mobile no.: ");
          fflush(stdin);
          fgets(mob,11,stdin);
         int *pos = strchr(mob,'\n');
          if(pos!=NULL)
            *pos = '\0';
            if(strcmp(mob,"0")!=0){
          int no = search_ticket(&mob);
          if(no == 0){
            printf("Sorry no ticket number is found");
            printf("\n\n press Enter to continue");
            _getch();
          }
          else if(no == -1)
            continue ;
          else{
            printf("Your ticket number is %d",no);
             printf("\n\n press Enter to continue");
            _getch();
          break ;
          }
            }
            else if(strcmp(mob,"0")==0)
                break ;
         }
         break ;
     }
     case 5 : view_all_bookings();
     printf("\n\n Press Enter to continue");
     _getch();
         break ;
     case 6 : clrscr();
     gotoxy(73,1);
textcolor(GREEN);
printf("Press 0 to go back");
textcolor(CYAN);
gotoxy(1,1);
     printf("Enter train number:");
     char trn[10] ;
     fflush(stdin);
     fgets(trn ,10,stdin );
     int *pos = strchr(trn,'\n');
     if(*pos!=NULL)
        *pos='\0';
        if(trn[0]!='0')
     view_booking(&trn);

         break ;
     case 7 : clrscr() ;
     int no ;
     gotoxy(73,1);
textcolor(GREEN);
printf("Press 0 to go back");
textcolor(CYAN);
gotoxy(1,1);
     printf("Enter Ticket no.:");
     scanf("%d",&no);
     if(no != 0){
     no = cancel_ticket(no);
     if(no == 0)
        printf("\nSorry no bookings found ");
     else if(no ==1)
        printf("\n Ticket cancel Succesfully");
     printf("\n\nPress Enter to continue");
     _getch();
     }
          break ;
     case 8 :
         clrscr();
         int np ;
       gotoxy(73,1);
textcolor(GREEN);
printf("Press 0 to go back");
textcolor(CYAN);
gotoxy(1,1);
char tr[10] ;
printf("Enter train no. to cancel train :");
fflush(stdin);
fgets(tr,10,stdin);
int *po = strchr(tr,'\n');
     if(*po!=NULL)
        *po='\0';
        if(strcmp(tr,"0")!=0){
           np = cancel_train(&tr);
        if(np == 0)
            printf("\nThere are no bookings in this train");
        else if(np == 1)
            printf("\nTrains bookings are canceled succesfully");
        printf("\n \nPress enter to continue");
        _getch();
        }
         break ;
     case 9 : exit(0);
     break ;
     default :textcolor(LIGHTRED);
         printf("Please enter a valid choice!!!!!.... \nTry Again Press Enter");
         _getch();
          clrscr();
     break ;

 }
  }

    return 0 ;
}
