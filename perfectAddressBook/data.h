
#ifndef _DATA_H_
#define _DATA_H_

#define BOOL int
#define TRUE 1
#define FALSE 0
#define NAME_MAX_SIZE 20
#define TEL_MAX_SIZE 20

typedef  struct Record
{
    char name[NAME_MAX_SIZE];
    char tel[TEL_MAX_SIZE];
    struct Record *next;
}RECORD,*PRECORD;

#endif