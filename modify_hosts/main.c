#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modify.h"

#define targethostpath "/etc/hosts"
#define localhostpath  "./hosts"

int main(int argc, char *argv[])
{
    int doNotDelete = 0;
    if(argc > 1)
    {
        if(strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)
        {
            printf("\nThere is nothing about help option!Please refer to README.md\n\n");
            return 0;
        }
        else if(strcmp(argv[1], "-s") == 0 || strcmp(argv[1], "--save") == 0)
        {
            doNotDelete = 1;
            goto start;
        }
        else
        {
            printf("Can not recognize the option!\n");
            goto ret;
        }
    }
start:
    rmHosts();
    if(downloadHostsFile()){
        printf("\n\nDownload hosts from https://raw.hellogithub.com/hosts failed!\n\n");
        goto ret;
    }
    modifyHosts(targethostpath, localhostpath);
    flushDns();
    if(doNotDelete)
    {
        printf("\nThe downloaded hosts was saved!\n\n");
        goto ret;
    }
    else
        rmHosts();
ret:
    return 0;
}