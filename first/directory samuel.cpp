#include "directory.h"
#include "funix.h"
/*
void showPath(Dir *currentDirectory);
{
    if(currentDirectory->parentDirectory==NULL) printf("/");
    else {
    char *path = (char*)malloc(sizeof(char)*COMMAND_LENGTH);
    path=currentDirectory -> Name;
    path=strncat (path, "/");
    Dir *temp=(Dir*)malloc(sizeof(Dir));
    temp=currentDirectory;
    while (temp -> parentDirectory !=NULL)
    {
        path=strncat("/", path);
        path=strncat(temp -> parentDirectory -> Name, path);
        temp=parentDirectory;
    }
    path=strncat("/", path);
    printf("%s", path);
        free (temp);
        }
}

*/

void createDirectory (Funix *funix, char *name, char *argument[])
{
    funix -> currentDirectory -> name = argument;
    funix -> currentDirectory -> umask= 0;
}

void ls ()
{

}