#include <stdio.h>
#include <string.h>
#include "shared.h"

int shared_lib_function(char* msg)
{
    printf("Hi! I'm a dynamic lib that receives '%s', and return '%zu'\n",msg,strlen(msg));
    return strlen(msg);
}
