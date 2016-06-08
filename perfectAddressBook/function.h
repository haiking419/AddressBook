#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include"data.h"


char MainMenu(void);
void DestoryList(PRECORD head);
BOOL InitList(RECORD**head);
BOOL AddRecord(PRECORD head);
void SaveRecord(PRECORD head);
BOOL BrowseRecord(PRECORD head);
PRECORD GetRecordFromFile(void);
char SearchMenu(void);
BOOL SearchMenuIsError(char* sel);
void SearchRecord(PRECORD head);
void SearchByName(PRECORD head);
BOOL SearchByNameResult(PRECORD head,char* pName);
void SearchByTel(PRECORD head);
void DelRecord(PRECORD head);

char Deletemenu(PRECORD head);
void DeleteByName(PRECORD head);
void DeleteByTel(PRECORD head);
BOOL DeleteMenuIsError(char* sel);
void DeleteByName(PRECORD head);

char  Modifymenu(PRECORD head);
void ModifyRecord(PRECORD head);
BOOL ModifyMenuIsError(char* sel);
void ModifyByTel(PRECORD head);
void ModifyByName(PRECORD head);

void SortRecord(PRECORD head);
char SortMenu(void);
void SortByName(PRECORD head);
void SortByTel(PRECORD head);

void ConserveRecord(PRECORD head);


void MusicPlayer(void);
char MusicMenu(void);
void Music(char path[20]);
void Musicplay(char path[20]);
void Musicclose(void);

#endif
