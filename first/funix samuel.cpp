#include "funix.h"


void cd(Funix *funix, int argCount, const char *arguments[])
{
    
}
// calls cd() with currentDirectory as one of its parameters
int eXit(Funix *funix, int argCount, const char *arguments[])
{
   /* if (arguments[1]!= NULL) {
        printf("usage: exit\n");
        argCount++;
        return argCount;
    }
    else return argCount;*/ return 0;
}
// checks "exit" command, returns 0 on proper exit
void getCommand(Funix *funix, char *command)
{
    /*writePrompt(*funix);
    fgets(command, COMMAND_LENGTH, stdio);
    char *token= (char*)malloc(COMMAND_LENGTH);
    token=strtok(command, "\n");
    strcpy(command,token);*/
}
// writes prompt and reads command
void init(Funix *funix)
{
    funix -> time=0;
    funix -> umask=0;
    funix -> currentDirectory = createDirectory(funix, "/");
}
// creates currentDirectory, and sets umask and time
void ls(Funix *funix, int argCount, const char *arguments[])
{
    char temp[MAX_ARGUMENTS];
    temp = funix-> currentDirectory->subDirectory= name;
    printf("%s", temp);
}
// calls ls() with currentDirectory as one of its parameters
void mkdir(Funix *funix, int argCount, const char *arguments[])
{
    
    funix -> currentDirectory -> subDirectory -> name = arguments;
    funix -> currentDirectory -> subDirectory -> rTime ++;
    
}
// calls mkdir() with currentDirectory as one of its parameters
int processCommand(Funix *funix, char *command)
{
    /*char *arg[MAX_ARGUMENTS];
    int i=0;
    arg[i]=strtok(command," ");
    while (arg[i]!=NULL)
    {
        ++i;
    arg[i]=strtok(NULL," ");
    }
    switch (getInteger(arg)) {
        case 1:
            cd();
            break;
        case 2:
            if(eXit(funix, 0, arg[])==1) break;
            else return 1;
            break;
        case 3:
            // Directory ::ls
            break;
        case 4:
            mkdir(funix, i, arg[1]);
            break;
        case 5:
            umask();
            break;
        default: printf("%s: Command not found.\n", arg[0]);
     break;*/ return 0;
    }

    return 0;
}// returns 0 on proper exit
void run(Funix *funix)
{
    init(funix);
    char command[COMMAND_LENGTH];
    int k =0;
    
    while (k!= 1) {
        getCommand(funix, &command);
        k=processCommand(funix, &command);
        
    }
    
}
// reads and processes commands in a loop until proper exit
void umask(Funix *funix, int argCount, const char *arguments[])
{
    if (argCount>1 ) printf("usage: umask octal");
    if (!isdigit(arguments) ||  )
}
// checks "umask" command and executes it if it is proper
void writePrompt(Funix *funix)
{
   /* char *ptr=showPath()
    printf("%s #", ptr); */
}  // shows path and '#'

/* int getInteger(char *arguments)
{
    if (strcmp(arguments, "cd")==0) return (1);
    if (strcmp(arguments, "exit")==0) return (2);
    if (strcmp(arguments, "ls")==0) return (3);
    if (strcmp(arguments, "mkdir")==0) return (4);
    if (strcmp(arguments, "umask")==0) return (5);
} */