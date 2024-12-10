#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct task {

   int id ,priorityLevel;
   char description[100];
   char status[12];
   struct task* next;
}task;

task implementTask(task *t){
   do
   {
    printf("what is it's priority(1-5):");
    scanf("%d",&t->priorityLevel);
   } while (t->priorityLevel<0 || t->priorityLevel>6);
   char description[100];
   printf("Enter the description (max 100 characters): ");
   
    while (getchar() != '\n' && getchar() != EOF);

    if (fgets(t->description, sizeof(t->description), stdin) != NULL) {
        t->description[strcspn(t->description, "\n")] = '\0';
    } else {
        printf("Error reading the descrription.\n");
    }
   int statuss;
   do
   {
    printf("enter the status(1-3)\n1-pending\n2-In Progress\n3-Completed: ");
   scanf("%d",&statuss);
   } while (statuss<0 || statuss>3);
   if (statuss==1)
   {
    strcpy(t->status,"Pending");
   }else if (statuss==2)
   {
     strcpy(t->status,"In Progress");
   }else{
    strcpy(t->status,"Completed");
   }
   t->next=NULL;

   return *t;
}

void addTask(task** head){
  task t1;
  int id;
  task* temp,*temp2;

  printf("\n_________________________________________________________________\n\nhere we will be adding a new task\n_________________________________________________________________");
  if (*head==NULL)
  {
    printf("\n\ngive me the id of the first task:");
    scanf("%d",&id);
    
    implementTask(&t1);
    (*head)=malloc(sizeof(task));
    strcpy((*head)->description,t1.description);
    (*head)->priorityLevel=t1.priorityLevel;
    strcpy((*head)->status ,t1.status);
    (*head)->id=id;
    (*head)->next=NULL;
    
  }else{
    temp=*head;
    printf("\n\ngive me the id of your task (the id should be unique):");
    scanf("%d",&id);
    
       while (temp!=NULL) //to check if the id is unique
      {
       if (temp->id==id)
       {
         printf("\nthis id exists already try to enter a new one:");
         scanf("%d",&id);
         temp=*head;
       }
       else{
         temp=temp->next;
        }
      }
      
      temp2=malloc(sizeof(task));//implementing the new task created
      implementTask(&t1);
      strcpy(temp2->description,t1.description);
      temp2->priorityLevel=t1.priorityLevel;
      strcpy(temp2->status ,t1.status);
      temp2->id=id;
      temp2->id=id;
      
      temp=*head;
      task *previous;

      if ((*head)->priorityLevel<temp2->priorityLevel)// updating the head if it's priority level is less then the task we created
      {
        temp2->next=*head;
        *head=temp2;
      }else
      {
      while (temp!=NULL && temp->priorityLevel>=temp2->priorityLevel)//traverse the list to reach a task with a priority level less than the one of the task we created 
      {
        previous=temp;
        temp=temp->next;
      }
       previous->next=temp2;
       temp2->next=temp;
      }
    } 
  }

 void deleteTask(task** head){
   printf("\n_________________________________________________________________\n\nhere we will be deleting a task using it's ID\n_________________________________________________________________");
   if (*head==NULL)
   {
    printf("\n\nthe tasks aren't implemented yet,there is no task to delete\n\n");
   }else{
    bool 
     found=false;
     task* temp;
     printf("\nenter the id of the task you want to delete:");
     int identifier;
     scanf("%d",&identifier);
    
    do { //forcing the user to enter an existing id
      temp=*head;
      while(temp!=NULL){
         if (temp->id==identifier)
         {
           printf("\nthis id is valid\n");
           found=true;
           break;
         }else{temp=temp->next;
         }
         
      }
      if (temp==NULL)
      {
         printf("this id is not valid. Try another one:");
         scanf("%d",&identifier);
      }
    }
     while(found==false);
    
    
    temp=*head;

    if (temp->id==identifier)
    {
      *head=(*head)->next;
      free(temp);
    }else
    {
      
      while (temp->next->id!=identifier)
      {
          temp=temp->next;
      }
      temp->next=temp->next->next;
      free(temp->next);
      
    }
    printf("\n THE TASK HAS BEEN DELETED SUCCESFULLY\n\n");
   }
   
  }
 
 void updateStatus(task*head){

  task* temp=head;
  bool 
     found=false;
     if (head==NULL)
     {
      printf("\ntasks arent implemented yet or has been deleted...\n\n");
     }else{
     
     printf("__________________________________________________________\n");
     printf("\nenter the id of the task you want to update it's status:");
     int identifier;
     scanf("%d",&identifier);
    
    do { //forcing the user to enter an existing id
      while(temp!=NULL
      ){
         if (temp->id==identifier)
         {
           printf("\nthe current status of this task is:'%s'\n",temp->status);
           found=true;
           break;
         }else{temp=temp->next;
         }
      }
      if (temp==NULL)
      {
         printf("this id is not valid. Try another one:");
         scanf("%d",&identifier);
         temp=head;
      }
    }
     while(found==false);
    


    int statuss;
   do
   {
    
   printf("enter the status(1-3)\n1-pending\n2-In Progress\n3-Completed: ");
   scanf("%d",&statuss);
   while (temp->id!=identifier)
      {
          temp=temp->next;
      }
   } while (statuss<0 || statuss>3);
   if (statuss==1)
   {
    strcpy(temp->status,"pending");
   }else if (statuss==2)
   {
     strcpy(temp->status,"In Progress");
   }else{
    strcpy(temp->status,"Completed");
   }

   printf("\n STATUS UPDATED\n\n");
   }
 }

 void taskAffiche(task* t){

  printf("\n__________________________\n");
  printf("ID:%d",t->id);
  printf("\nPriority Level:%d",t->priorityLevel);
  printf("\nStatus:%s",t->status);
  printf("\nDescription:%s\n",t->description);
  printf("__________________________\n");
 }
 
 void displayByStatus(task* head){
     int i=0;
     printf("\n_________________________________________________________________\n\nhere we will be displaying the tasks\n_________________________________________________________________\n\n");
     if (head==NULL)
     {
      printf(" tasks hasn't been implemented yet or has been deleted...\n\n");
     }else{
     task *temp=head;
     
     while (temp!=NULL)//displaying all tasks with pending status
     {
       
       
       if (strcmp(temp->status,"Pending")==0)
       {
        if (i==0)
        {
        printf("\n THE PENDING TASKS");
        i=1;
        }
         taskAffiche(temp);
       }
       temp=temp->next;
     }
     temp=head;
     i=0;
     
     while (temp!=NULL)//displaying all tasks with in progress status
     {
       
       if (strcmp(temp->status,"In Progress")==0)
       {
        if (i==0)
        {
        printf("\n THE IN PROGRESS TASKS");
        i=1;
        }
         taskAffiche(temp);
       }
       temp=temp->next;
     }

     i=0;
     temp=head;
    
      while (temp!=NULL)//displaying all tasks with completed status
     {
       
       if (strcmp(temp->status,"Completed")==0)
       {
        if (i==0)
        {
         printf("\n THE COMPLETED TASKS");
        i=1;
        }
         taskAffiche(temp);
       }
       temp=temp->next;
     }
     }
 }


 void displayByPriority(task*head){
    int i;
     printf("\n_______________________________________________________________\n\nhere we will be displaying the tasks by priority level\n_________________________________________________________________\n\n");
     if (head==NULL)
     {
      printf(" tasks hasn't been implemented yet or has been deleted...\n\n");
     }else{
      task *temp=head;
     do {
      printf("which priority level tasks you want to display(1-5):");
      scanf("%d",&i);
      }
     while(i<0 || i>6);
     int n=0;
     bool priorityFound=false;
     while (temp!=NULL)//checking if there is any task with priority level of i
     {
       if (temp->priorityLevel==i)
       {
        priorityFound=true;
        break;
       }
       temp=temp->next;
     }
    if (!priorityFound)
      {
        printf("there is no task with priority level of %d\n\n",i);
      }
    else{
     while (temp!=NULL)//displaying all tasks with priority level of i
     {
      
      
      if (n==0)
      {
        printf("\ntasks with priority level of %d\n",i);
        n=1;
      }
      
       if (temp->priorityLevel==i)
       {
         taskAffiche(temp);
       }
       temp=temp->next;
     }
     }
     }

 }
 void displayMenu(){
    printf("\n_________________________________________________________________");
    printf("\nenter a number from(1-7) to select one of the functions bellow:\n");
    printf("\n1-task insertion\n2-Task Deletion\n3-Update Status\n4-Display Tasks\n5-Search by Priority\n6-show more details about the functions\n7-EXIT");
 }

 void showDetails(){
   printf("__________________________________________________________________________________________________\n");
   printf("\n1-The Task Insertion: adds a new task to the list. \n  Tasks are added in order of priority (higher priority tasks come first)\n");
   printf("\n2-The task Deletion: deletes a task by its identifier.\n");
   printf("\n3-Update Status: updates the status of a task by its identifier.\n");
   printf("\n4- Display Tasks: displays all tasks, grouped by their current status \n  (i.e., 'Pending' tasks first, followed by 'In Progress' and then 'Completed').\n");
   printf("\n5-Search by Priority: searches and displays all tasks with a specific priority level.\n");
   printf("__________________________________________________________________________________________________\n");
 }
 void returnMenu(){
  printf("Press any key to return to the menu:");
    while (getchar() != '\n' && getchar() != EOF);  // Clear buffer
    getchar();  
 }