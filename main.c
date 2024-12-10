#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include"functions.h"

int main(){
   printf("_________________________________________________________________\n\n");
   printf("hello this is a simple application that manages your daily tasks.");
 int exit;
 
 task *head=NULL;
   do
   {
      displayMenu();
      do
      {
          printf("\nhere enter the number:");
          scanf("%d",&exit);
          while (exit<0 || exit>7)
          {
            printf("you must enter a number between(1-7)\ntry again:");
            scanf("%d",&exit);
          }  
      } while (exit<0 || exit>7 );

      switch (exit)
      {
      case 1:
           addTask(&head);
           returnMenu();
           break;
         ;
      case 2:
          deleteTask(&head);
          returnMenu();
          break;
         ;
      case 3: updateStatus(head);
              returnMenu();
         break;
         ;
      case 4:
         displayByStatus(head);
         returnMenu();
         break;
         ;
      case 5:
         displayByPriority(head);
         returnMenu();
         break;
      break;
      case 6:
         showDetails();
         returnMenu();
         break;
      }
   } while (exit!=7);
}

