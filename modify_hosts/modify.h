#ifndef MODIFY_H
#define MODIFY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"


void rmHosts(void){
    system("rm -f hosts*");
    return;
}

void flushDns(void)
{
    system("/etc/init.d/networking restart");
    return;
}

int downloadHostsFile(void)
{
    int ret = system("wget https://raw.hellogithub.com/hosts");
    return ret;
}

int modifyHosts(char tp[], char lp[])
{
    char *strtemp = NULL;
    strtemp = (char *)malloc(sizeof(char) * STRLEN);
    memset(strtemp, 0, sizeof(char) * STRLEN);
    char ctemp = 0;
    FILE *targetfp = fopen(tp, "r+");
    if(!targetfp){
        printf("Open target hosts failed!\n");
        return 0;
    }
    FILE *localfp = fopen(lp, "r");
    if(!localfp){
        printf("Open local hosts failed!\n");
        return 0;
    }
    long int offset = 0;
    offset = findIdentifier(targetfp);
    if(offset < 0)
        return -1;
    do {
        ctemp = fgetc(targetfp);//set fpos_t to head of next line.
    } while(ctemp != '\n');
    if(!fgets(strtemp, STRLEN, localfp)){
        return -1;
    }
    do {
        fprintf(targetfp, "%s", strtemp);
    } while(fgets(strtemp, STRLEN, localfp));
    free(strtemp);
    fclose(targetfp);
    fclose(localfp);
}

#endif