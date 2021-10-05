#include <stdio.h>
#include <unistd.h>
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>


#define MAX_LINE 80 /* Max Length Command */
#define history_size 10 // Max length history

using namespace std;

int history_count = 0; //number for history
char *command_history[history_size];



void run_history(char *command)
{
  int i = 0;
  if(history_count == 0)
  {
    printf("EMPTY HISTORY \n");
    return;
  }
  
  if(command[1] == '!')
  {
    i = history_count - 1;
  }else{
    i = atoi(&command[1]) - 1;
    if((i < 0) || (i > history_count))
    {
      printf("No command in history \n");
      return;
    }
  }
}


void add_history(char *command)
{
   if(history_count == (history_size-1))
   {
     int i = 0;
     free(command_history[0]); // Deletes the history in slot 0
     
       for(int i = 1; i < history_count; i++)
       {
         command_history[i-1] = command_history[i];
         history_count--;
       }
       
   }
    
    command_history[history_count] = strdup(command);
    history_count++;
}



void showHistory()
{
  int i = 0;
  if(history_count == 0)
  {
    printf("EMPTY HISTORY\n");
  }
  else
  {
    for(int i = history_count - 1; i >= 0; i--)
    {
    printf("%i %s\n", i+1, command_history[i]);
     }
  }

}

int main(void)
{
  cout << "-------------------------\n";
  cout << "NAME : IAN ALTOVEROS \n";
  cout << "DESCRIPTION: IMPLEMENTION OF A SIMPLE SHELL INTERFACE \n";
  cout << "CS433 OS - 10/14/2020 \n";
  cout << "------------------------\n";

  
  
  
 
   char *args[MAX_LINE/2 + 1]; /* command line arguments */

   int should_run = 1; /* flag to determine when to exit program */

   while (should_run)
   {

       printf("osh> ");

       fflush(stdout);
     
     /**
    * After reading user input, the steps are:
    * (1) fork a child process using fork()
    * (2) the child process will invoke execvp()
    * (3) parent will invoke wait() unless command included &
     */
      
       char command[MAX_LINE+1];
      
       fgets(command,MAX_LINE+1,stdin);

     
        
     
       if(strcmp(command,"history")) //SHOW HISTORY
       {
         showHistory();
       }
     
      add_history(command);
    
     
       if (!strcmp(command,"exit\n"))
           should_run = 0;
       if(strcmp(command, "!") == 0)
       {
         run_history(command);
       }
       else
       {
           pid_t pid;
           pid = fork();
           if(pid < 0)
           {
             cout << "Fork Failed!\n";
             return 1;
           }
           else if(pid == 0)
           {

               command[strlen(command)-1] = 0;
               char *token = strtok(command, " ");

               int i = 0;
               while(token != NULL)
               {
                   args[i] = token;
                   token = strtok(NULL, " ");
                   i++;
               }


               args[i] = NULL;
               execvp(args[0],args);
               exit(0);
           }
           else
           {
   
               if(command[strlen(command)-2] == '&')
                   continue;
               else
                   wait(NULL);
           }
       }
     
   }

   return 0;
}

                   

 



