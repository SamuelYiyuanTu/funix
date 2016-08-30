#include "permissions.h"




void printPermissions (permissions* perm )
{
    
    
    char* p = (char*)malloc(sizeof(char)*5);
    if (perm->num==0) strcpy(p,"rwx");
    if (perm->num==1) strcpy(p,"rw-");
    if (perm->num==2) strcpy(p,"r-x");
    if (perm->num==3) strcpy(p,"r--");
    if (perm->num==4) strcpy(p,"-wx");
    if (perm->num==5) strcpy(p,"-w-");
    if (perm->num==6) strcpy(p,"--x");
    if (perm->num==7) strcpy(p,"---");
    printf("%s",p);
}

