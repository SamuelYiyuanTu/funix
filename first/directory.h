#ifndef DIRECTORY_H
#define DIRECTORY_H


#include "permissions.h"

#define Max_subDirectories 3

typedef struct Dir
{
    char *name;
    struct Dir** subDirectory;
    int subNum;
    int Rtime;
    struct Dir* parentDirectory;
   permissions* perm;
}Directory;

void createDirectory(Directory* Directory,int time, int umask);

void showPath(Directory *currentDirectory,char *path);

void mkdir(Directory *currentDirectory, int argCount, const char *arguments[],int time, int umask);

void ls(Directory *currentDirectory, int argCount, const char *arguments[]);

void cd(Directory *currentDirectory, int argCount, const char *arguments[]);



# endif