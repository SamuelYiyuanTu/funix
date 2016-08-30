// Author: Xiaoyun Wang

#include "permissions.h"

Permissions::Permissions()
{
}// default con******or

Permissions::~Permissions()
{
}// des*****or

void Permissions::get_str(char* prem_str)
{
   
    if ((oct_perm & 4) == 0)
        prem_str[0] = '-';
    else // if the first position is fullfilled
        prem_str[0] = 'r';
   
    if ((oct_perm & 2) == 0)
        prem_str[1] = '-';
    else // same as above
        prem_str[1] = 'w';
   
    if ((oct_perm & 1) == 0)
        prem_str[2] = '-';
    else //commenting elses
         prem_str[2] = 'x';
} // get permissions

