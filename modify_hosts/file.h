#ifndef FILE_H
#define FILE_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define STRLEN 256
#define IDENTIFIER "#github identfier"

long int findIdentifier(FILE *fp)
{
    long int offset = 0;
    char c;
    char identifier[] = IDENTIFIER;
    c = fgetc(fp);
    offset++;
//    printf("in fun %s:offset = %ld, c = %c\n", __FUNCTION__, offset, c);
    do {
        for(int i = 0; i < strlen(identifier); i++){
            if(c == identifier[i]){
                if(i == strlen(identifier) - 1)
                    return offset;
//                printf("c = %c, identifier[%d] = %c\n", c, i, identifier[i]);
                c = fgetc(fp);
                offset++;
                continue;
            }
            else
                break;
        }
        c = fgetc(fp);
        offset++;
    }while(c != EOF);
    if((offset - strlen(identifier)) > -1)
    return -1;

}

#endif