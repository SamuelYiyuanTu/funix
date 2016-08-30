// Author: Xiaoyun Wang & Yiyuan Tu


#include <iostream>
#include <cstring>
#include <cstdlib>
#include "funix.h"

using namespace std;

Funix::Funix()
{
    this->currentDirectory = new Directory("/", NULL, this->umask, this->time);
    this->time  = 0;
    this->umask = 0;
}// standar con******or
Funix::~Funix()
{
}// de*****or

void Funix::cd( int argCount, const char *arguments[])

{
    this->currentDirectory = this->currentDirectory->cd(argCount, arguments);
}// calls cd() with currentDirectory as one of its parameters

int Funix::eXit( int argCount, const char *arguments[])

{
    
   if (argCount != 0)
      {
        cout << "usage: exit" << endl;
        return 1;
      } else return 0;
}// checks "exit" command, returns 0 on proper exit

void Funix::getCommand( char *command)

{
    string temp_str;
    writePrompt();
    getline(cin, temp_str );
    //cout<<temp_str<<" | "<<temp_str.length()<<endl;
    memcpy(command, temp_str.c_str(), sizeof(char)*temp_str.length());
    command[temp_str.length()] = ' ';
    command[temp_str.length() + 1] = '\0';

}// writes prompt and reads command


void Funix::ls( int argCount, const char *arguments[])

{
    this->currentDirectory->ls(argCount, arguments);
}// calls ls() with currentDirectory as one of its parameters

void Funix::mkdir( int argCount, const char *arguments[])

{
    this->currentDirectory->
    mkdir(argCount, arguments, 7-this->umask, this->time);
}// calls mkdir() with currentDirectory as one of its parameters

int Funix::processCommand( char *command)
{
    const char **arguments = new const char*[MAX_ARGUMENTS + 1];
    char *temp_str = new char[COMMAND_LENGTH + 1];
    int argC = 0;
    int current = 0;
    
   for (unsigned int i = 0; i<strlen(command); i++)
     {
        
      if (command[i] == ' ' || command[i] == '\n') 
         {

            if (current!=0)
            {
                arguments[argC] = new char[current + 1];
                temp_str[current] = '\0';
                memcpy((void*)arguments[argC], 
                              temp_str, sizeof(char)*current + 1);
                argC++;
                current = 0;
            }// see if current equals 0
         }//see if it is end 

        else // comments
         {
            temp_str[current] = command[i];
            current++;
         }//in_str=true;

     }//extra comments
    
    this->time++;
    int return_value = 1;
    
    if (strcmp(arguments[0], "exit") == 0)
        return_value = eXit( argC-1, &arguments[1]);
    
    else if (strcmp(arguments[0], "cd") == 0)
        cd(argC-1, &arguments[1]); // call cd
   
    else if (strcmp(arguments[0], "ls") == 0)
        ls(argC-1, &arguments[1]); // call ls
   
    else if (strcmp(arguments[0], "mkdir") == 0)
        mkdir(argC-1, &arguments[1]); //call mkdir
   
    else if (strcmp(arguments[0], "umask") == 0)
        umas(argC-1, &arguments[1]); //call umask
   
    else cout << arguments[0] << ": Command not found." << endl; //default
 
    for (int i = 0; i<argC; i++)
    {
        delete[] arguments[i]; arguments[i] = NULL;
    }// delete the new

    delete[] temp_str; temp_str = NULL;
    delete[] arguments; arguments = NULL;
    return return_value;
}// returns 0 on proper exit

void Funix::run()

{
    bool to_continue = true;
    char* command = new char[COMMAND_LENGTH + 1];
    
    while (to_continue)
     {
      getCommand(command );
      
         if (processCommand( command ) == 0) to_continue = false;
     }//while loop
} // reads and processes commands in a loop until proper exit

void Funix::umas( int argCount, const char *arguments[])

{
    
    if (argCount != 1)
      {
        cout << "usage: umask octal" << endl;
        return;
      }// if incorrect number of argument

    int temp = atoi(arguments[0]);
    
    if (temp<0 || temp>7)
      {
        cout << "umask: octal must be between 0 and 7" << endl;
        return;
      }//see if it is within the range

    this->umask = temp;
}// checks "umask" command and executes it if it is proper

void Funix::writePrompt()

{
    this->currentDirectory->showPath();
    cout << " # ";
}// shows path and '#'

