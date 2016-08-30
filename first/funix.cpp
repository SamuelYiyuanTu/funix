#include "funix.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void cd(Funix *funix, int argCount, const char *arguments[])
{
    cd(funix->currentDirectory,argCount,arguments);
}
  // calls cd() with currentDirectory as one of its parameters
int eXit(Funix *funix, int argCount, const char *arguments[])
               {
               if(argCount!=1) 
               {printf("usage: exit/n");
                return 0;
               }
               else return 1;
               }
                 // checks "exit" command, returns 0 on proper exit
            void getCommand(Funix *funix, char *command)
               {
               writePrompt(funix);
               char token[COMMAND_LENGTH]; 
               fgets(command, COMMAND_LENGTH, stdin);
               strcpy(token,strtok(command, "\n"));
               strcpy(command, token);
               funix->time++;
                if (strlen(token)==0)
                    getCommand(funix, command);
               }// writes prompt and reads command
void init(Funix *funix)
{
funix->time=0;//initialize time to be 0
funix->umask=0;//initialize umask to be 0
Dir* currentDirectory=(Dir*)malloc(sizeof(Dir));//create root directory
currentDirectory->name=NULL;//root name:""
createDirectory(funix->currentDirectory,funix->time,funix->umask);//initialize root directory
}  
  // creates currentDirectory, and sets umask and time
void ls(Funix *funix, int argCount, const char *arguments[])
{
    ls(funix->currentDirectory,argCount,arguments);
}
  // calls ls() with currentDirectory as one of its parameters
void mkdir(Funix *funix, int argCount, const char *arguments[])
{
mkdir(funix->currentDirectory, argCount, arguments,funix->time,funix->umask);

}  // calls mkdir() with currentDirectory as one of its parameters
int processCommand(Funix *funix, char *command)
            {
                int hi=0;
                

                
            const char *arg[MAX_ARGUMENTS];
            int Count=0;
            arg[Count]=strtok(command, " ");
            while(arg[Count] != NULL)
            { 
              Count++;
              arg[Count]=strtok(NULL, " ");
            }
                if(strcmp(arg[0],"cd")==0)
                    hi=1;
                if(strcmp(arg[0],"exit")==0)
                    hi= 2;
                if(strcmp(arg[0],"ls")==0)
                    hi= 3;
                if(strcmp(arg[0],"mkdir")==0)
                    hi= 4;
                if(strcmp(arg[0],"umask")==0)
                    hi= 5;
            switch(hi)
            {
            case 1: cd(funix,Count,arg); return 0;
            case 2: if(eXit(funix,Count,arg)==0) return 0; if(eXit(funix,Count,arg)==1) return 1; //¡Ì
            case 3: ls(funix,Count,arg); return 0;
            case 4: mkdir(funix,Count,arg); return 0;
            case 5: umask(funix,Count,arg); return 0;               //¡Ì
            default: printf("%s:command not found.\n",arg[0]); return 0;
            }
            }  // returns 0 on proper exit
            void run(Funix *funix)
            { 
            init(funix);
            char command[COMMAND_LENGTH]; 
            int i=0;
            while(i!=1)
            {
            getCommand(funix,command);
            i=processCommand(funix,command);
            }
            }

            // reads and processes commands in a loop until proper exit
            void umask(Funix *funix, int argCount, const char *arguments[])
            {
            int k;
            if(argCount!=2) printf("usage: umask octal\n");
            else
            {
              if(isdigit(*arguments[1])!=0)
              {k=atoi(arguments[1]);
               if(k<0||k>7) printf("umask: octal must be between 0 and 7");
               else funix->umask=k;
              }
              else printf("usage: umask octal\n");
            }
            }
              // checks "umask" command and executes it if it is proper
            void writePrompt(Funix *funix)
            {
            char path[]="/";
            showPath(funix->currentDirectory,path);
            printf(" #");
            }  // shows path and '#'





