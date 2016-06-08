#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "function.h"


BOOL AddRecord(PRECORD head)
{
    //1.����һ���ڵ�    
    char res[TEL_MAX_SIZE]="";
    PRECORD newRecord=NULL;
TAG:
    newRecord=
        (PRECORD)malloc(sizeof(RECORD));
    if(NULL==newRecord)
    {
        printf("�����ڴ�ʧ�ܣ�\n");
        system("PAUSE");
        return FALSE;
    }
    //2.������д���½��Ľڵ�
    printf("please input name:\n");
    gets(newRecord->name);
    fflush(stdin);
    printf("please input tel:\n");
    gets(newRecord->tel);
    fflush(stdin);
    //3.����
    newRecord->next=head->next;
    head->next=newRecord;
    printf("Success,press anykey to continue else press 0 to exit:");
    fflush(stdin);
    gets(res);
    if('0'==res[0])
        return TRUE;
    else
        goto TAG;
    
}

BOOL InitList(RECORD** head)//����ΪRECORD** ��������Ϊhead
{
    *head=(PRECORD)malloc(sizeof(RECORD));
    if(*head==NULL)
        return FALSE;
    (*head)->next=NULL;
    return TRUE;
}

void DestoryList(PRECORD head)
{
    PRECORD del = head;
    PRECORD delNext = head->next;
    while(delNext!=NULL)
    {
        free(del);
        del=delNext;
        delNext=delNext->next;    
    }
    free(del);
}


BOOL BrowseRecord(PRECORD head)
{
/*
1.�ж������ǲ��ǿ�����
2.����������ؼٲ���ʾ��ͨѶ¼û�м�¼��
3.
    */
    int count = 1;
    system("cls");
    printf("-------------RECORD-----------\n\n");
    printf("Rank     Name     Telephonenumber\n");
    head=head->next;
    if(head == NULL)
    {
        printf("ͨѶ¼û�м�¼!\n");
        system("PAUSE");
        return FALSE;
    }
    else
        while( head != NULL )
        {
            printf("%d:       %s       %s\n",count,head->name,head->tel);
            head=head->next;
            count ++;
        }
        system("PAUSE");
        
        return TRUE;
}

BOOL BrowseRecordInDelMenu(PRECORD head)
{
/*
1.�ж������ǲ��ǿ�����
2.����������ؼٲ���ʾ��ͨѶ¼û�м�¼��
3.
    */
    int count = 1;
    system("cls");
    printf("-------------RECORD-----------\n\n");
    printf("Rank     Name     Telephonenumber\n");
    head=head->next;
    if(head == NULL)
    {
        printf("ͨѶ¼û�м�¼!");
        return FALSE;
    }
    else
        while( head != NULL )
        {
            printf("%d:       %s       %s\n",count,head->name,head->tel);
            head=head->next;
            count ++;
        }
        printf("\n\n");
        printf("-----------------------------\n");
        return TRUE;
}



void SaveRecord(PRECORD head)
{
    
/*1.���ļ�
2.������д���ļ�
    3.�ر��ļ�*/
    FILE *fp=
        fopen("Record.txt","w");
    head=head->next;//����ͷ���
    while(NULL != head)
    {
        fprintf(fp,"%-15s%-15s\n",head->name,head->tel);
        head=head->next;
    }
    fclose(fp);
}



PRECORD GetRecordFromFile(void)
{
    PRECORD head = NULL;
    PRECORD pCurrentNote = NULL;
    PRECORD pPreNote = NULL;
    FILE* fp = NULL;
    fp=fopen("Record.txt","r");
    if(NULL == fp)
        return NULL;
    fgetc(fp);
    if( EOF == fgetc(fp))//�ļ����ڵ���û�м�¼˵��
        return NULL;
    else
        rewind(fp);//���ߴ�ͷָ���ļ�ͷ
    head = pCurrentNote=(PRECORD)malloc(sizeof(RECORD));
    while(!feof(fp))
    {
        if(fscanf(fp,"%s%s",pCurrentNote->name,pCurrentNote->tel) != EOF)
        {
            //pPreNote->next = pCurrentNote;
            pPreNote =  pCurrentNote;
            pCurrentNote=(PRECORD)malloc(sizeof(RECORD));
            pPreNote->next = pCurrentNote;
            //pPreNote =  pCurrentNote;
        }
    }
    pPreNote->next = NULL;
    free(pCurrentNote);
    fclose(fp);
    return head;
}

BOOL IsError(char sel[])//sel ��ʾsel[20]�ĵ�ַ
{
    if( sel[0]<'0'
        ||sel[0]>'9'
        ||strlen(sel)!=1 
        )
        return TRUE;
    else
        return FALSE;
}



char MainMenu(void)
{
    char sel[10]="";
    system("cls");
	system("color F2");
    printf("-----------MainMenu---------------\n");
    printf("�Ѧ��     1.AddRecord.			�Ѧ��\n");
    printf("�Ѧ��     2.BrowseRecord.		�Ѧ��\n");
    printf("�Ѧ��     3.DeleteRecord.		�Ѧ��\n");
    printf("�Ѧ��     4.SearchRecord.		�Ѧ��\n");
    printf("�Ѧ��     5.ModifyRecord.		�Ѧ��\n");
    printf("�Ѧ��     6.SortRecord			�Ѧ��\n");
    printf("�Ѧ��     7.ConserveRecord		�Ѧ��\n");
    printf("�Ѧ��     8.MusicPlayer.		�Ѧ��\n");
    printf("�Ѧ��     9.Help.				�Ѧ��\n");
    printf("�Ѧ��     0.Exit.				�Ѧ��\n");
    printf("-----------------------------------\n");
    printf("         Please select:");
    
    gets(sel);
    if( IsError(sel) )
    {
        printf("Error,Please select [0-9].");
        system("PAUSE");
        return -1;//why?
    }
    return sel[0];//why?
}

char SearchMenu(void)
{
    char sel[20] = "";
    system("cls");
    printf("-----------SearchMenu--------------\n");
    printf("1.SearchByName\n");
    printf("2.SearchByTel\n");
    printf("0.Exit\n");
    printf("-----------------------------------\n");
    printf("please select:");
    gets(sel);
    if( SearchMenuIsError(sel) )
        return -1;
    else
        return sel[0];
    
}

BOOL SearchMenuIsError(char* sel)
{
    if(strlen(sel) != 1 || sel[0]<'0' || sel[0]>'2')
        return TRUE;
    else
        return FALSE;
}

BOOL SearchByNameResult(PRECORD head,char* pName)
{
    BOOL tag = FALSE;
    printf("--------------SrarchResult------------------\n");
    head = head->next;
    while(head != NULL)
    {
        if( 0 == strcmp(head->name,pName) )
        {
            printf("%15s %15s\n",head->name,head->tel);
            tag = TRUE;
        }
        head = head->next; 
    }
    return tag;
}

void SearchByName(PRECORD head)
{
    char name[20] = "";
    printf("Please input name:\n");
    gets(name);
    system("cls");

    //SearchByNameResult(head);
   /* printf("--------------SrarchResult------------------");
    head = head->next;
    while(head != NULL)
    {
        if( 0 == strcmp(head->name,name) )
        {
            printf("%15s %15s\n",head->name,head->tel);
            flag = TRUE;
        }
        head = head->next; 
    }*/

    if( !SearchByNameResult(head,name))
        printf("���޴��ˣ�\n");
    system("PAUSE");
}

BOOL SearchByTelResult(PRECORD head,char* pTel)
{
    BOOL tag = FALSE;
    printf("--------------SrarchResult------------------\n");
    head = head->next;
    while(head != NULL)
    {
        if( 0 == strcmp(head->tel,pTel) )
        {
            printf("%15s %15s\n",head->name,head->tel);
            tag = TRUE;
        }
        head = head->next; 
    }
    return tag;
}

void SearchByTel(PRECORD head)
{
    char tel[20] = "";
    printf("Please input tellephonenumber:\n");
    gets(tel);
    system("cls");
    if( !SearchByTelResult(head,tel))
        printf("���޴��ˣ�\n");
    system("PAUSE");

    /*char tel[20] = "";
    BOOL flag = FALSE;//�ж��Ƿ��ҵ�ָ���ڵ�
    printf("Please input tel:\n");
    gets(tel);
    system("cls");
    head = head->next;
    while(head != NULL)
    {
        if( 0 == strcmp(head->tel,tel) )
        {
            printf("%15s %15s\n",head->name,head->tel);
            flag = TRUE;
        }
        head = head->next; 
    }
    if( flag == FALSE)
        printf("���޴��ˣ�\n");
    system("PAUSE");*/
}


void SearchRecord(PRECORD head)
{
    while(1)
    {
        switch(SearchMenu())
        {
        case'1':
            SearchByName(head);
            break;
        case'2':
            SearchByTel(head);
            break;
        case'0':
            return;
            break;
        default:
            printf("Error,Please selecte [0-2]");
            system("PAUSE");
            break;
        }
    }
}

BOOL DeleteMenuIsError(char* sel)
{
    if(strlen(sel) != 1 || sel[0]<'0' || sel[0]>'3')
        return TRUE;
    else
        return FALSE;
}

char Deletemenu(PRECORD head)
{
    char sel[20] = "";
    system("cls");
    BrowseRecordInDelMenu(head);
    if( BrowseRecordInDelMenu(head) == TRUE )
    {
        printf("\n\n");
        printf("-----------DeleteMenu--------------\n");
        printf("1.DeleteByName\n");
        printf("2.DeleteByTel\n");
        printf("3.DeleteAll\n");
        printf("0.Exit\n");
        printf("-----------------------------------\n");
        printf("please select:");
    gets(sel);
    if( DeleteMenuIsError(sel) )
        return -1;
    else
        return sel[0];
    }
    else
    {
        printf("sorry, there is no record\n");
        system("PAUSE");
        return '0';//zע�����ﷵ��'0',������0������
    }
}

void DeleteByName(PRECORD head)
{
    /*
    *1.����������ҽڵ�
    *2.��ʾҪɾ���ļ�¼������ʾ�û��Ƿ�Ҫɾ��
    *3.���ѡ��Y��ɾ����¼�����򷵻�
    *4.���û���ҵ�Ҫɾ���ļ�¼����ʾ�޴���
    */
    PRECORD pPreNote = head;
    PRECORD pCurrentNote = head->next;
    char name[20] = "";
    char sel[20] = "";
    printf("please input name:");
    gets(name);
    system("cls");
    if(!SearchByNameResult(head,name))
    {
        printf("���޴���.\n");
        system("PAUSE");
        return;
    }
    printf("ɾ���밴y/Y,�����밴�����");
    gets(sel);
    if(strlen(sel) != 1 && sel[0] != 'Y' && sel[0] != 'y')
        return;
    while(pCurrentNote != NULL)
    {
        if(strcmp(pCurrentNote->name,name) == 0)
        {
            pPreNote->next = pCurrentNote->next;
            free(pCurrentNote);
            pCurrentNote = pPreNote->next;
            continue;//һ��Ҫ��һ�䣡������Ȼ�������һ���ڵ㣬�����һ���ڵ�Ҳ��Ҫɾ���Ľڵ�Ļ����޷�ɾ����
        }
        pPreNote = pCurrentNote;
        pCurrentNote = pCurrentNote->next;
    }
    printf("ɾ���ɹ�\n");
    system("PAUSE");
}

void DeleteByTel(PRECORD head)
{
    /*
    *1.����������ҽڵ�
    *2.��ʾҪɾ���ļ�¼������ʾ�û��Ƿ�Ҫɾ��
    *3.���ѡ��Y��ɾ����¼�����򷵻�
    *4.���û���ҵ�Ҫɾ���ļ�¼����ʾ�޴���
    */
    PRECORD pPreNote = head;
    PRECORD pCurrentNote = head->next;
    char tel[20] = "";
    char sel[20] = "";
    printf("please input telephonenumber:");
    gets(tel);
    system("cls");
    if(!SearchByTelResult(head,tel))
    {
        printf("���޴���.\n");
        system("PAUSE");
        return;
    }
    printf("ɾ���밴y/Y,�����밴�����");
    gets(sel);
    if(strlen(sel) != 1 && sel[0] != 'Y' && sel[0] != 'y')
        return;
    while(pCurrentNote != NULL)
    {
        if(strcmp(pCurrentNote->tel,tel) == 0)
        {
            pPreNote->next = pCurrentNote->next;
            free(pCurrentNote);
            pCurrentNote = pPreNote->next;
            continue;//һ��Ҫ��һ�䣡������Ȼ�������һ���ڵ㣬�����һ���ڵ�Ҳ��Ҫɾ���Ľڵ�Ļ����޷�ɾ����
        }
        pPreNote = pCurrentNote;
        pCurrentNote = pCurrentNote->next;
    }
    printf("ɾ���ɹ�\n");
    system("PAUSE");
}

void DeleteAll(PRECORD head)
{
    char Reconfirm[15];
    PRECORD pPreNote = head;
    PRECORD pCurrentNote = head->next;
    printf("are you sure to delete all record? \n");
    do
    {
        printf("please enter 'Y'/'y' to comtinue,enter 'N'/'n' to exit:\n");
        gets(Reconfirm);
        fflush(stdin);
    }while( strlen(Reconfirm) != 1 || (Reconfirm[0] != 'Y' && Reconfirm[0] != 'y' && Reconfirm[0] != 'N' && Reconfirm[0] != 'n') );
    if(Reconfirm[0] == 'Y' || Reconfirm[0] == 'y')
    {
        while(pCurrentNote != NULL)
        {
            pPreNote->next = pCurrentNote->next;
            free(pCurrentNote);
            pCurrentNote = pPreNote->next;
        }
    }
    else
        return;
}

void DelRecord(PRECORD head)
{
    while(1)
    {
        switch(Deletemenu(head))
        {
        case'1':
            DeleteByName(head);
            break;
        case'2':
            DeleteByTel(head);
            break;
         case'3':
            DeleteAll(head);
            break;
         case'0':
            return;
            break;
        default:
            printf("Error,Please selecte [0-3]");
            system("PAUSE");
            break;
        }
    }
}

BOOL ModifyMenuIsError(char* sel)
{
    if(strlen(sel) != 1 || sel[0]<'0' || sel[0]>'2')
        return TRUE;
    else
        return FALSE;
}

char  Modifymenu(PRECORD head)
{
    char sel[20] = "";
    system("cls");
    BrowseRecordInDelMenu(head);
    if( BrowseRecordInDelMenu(head) == TRUE )
    {
        printf("\n\n");
        printf("-----------ModifyMenu--------------\n");
        printf("1.ModifyByName\n");
        printf("2.ModifyByTel\n");
        printf("0.Exit\n");
        printf("-----------------------------------\n");
        printf("please select:");
    gets(sel);
    if( DeleteMenuIsError(sel) )
        return -1;
    else
        return sel[0];
    }
    else
    {
        printf("sorry, there is no record\n");
        system("PAUSE");
        return '0';//zע�����ﷵ��'0',������0������
    }
}

void ModifyByName(PRECORD head)
{
    PRECORD pPreNote = head;
    PRECORD pCurrentNote = head->next;
    char name[20] = "";
    char modifiedName[20] = "";
    char modifiedTel[20] = "";
    char sel[20] = "";
    printf("please input the name you would like to modify:");
    gets(name);
    system("cls");
    if(!SearchByNameResult(head,name))
    {
        printf("���޴���.\n");
        system("PAUSE");
        return;
    }
    printf("�޸��밴y/Y,�����밴�����");
    gets(sel);
    printf("�������޸ĺ������:\n");
    gets(modifiedName);
    fflush(stdin);
    printf("�������޸ĺ�ĵ绰����:\n");
    gets(modifiedTel);
    fflush(stdin);
    if(strlen(sel) != 1 && sel[0] != 'Y' && sel[0] != 'y')
        return;
    while(pCurrentNote != NULL)
    {
        if(strcmp(pCurrentNote->name,name) == 0)
        {
            strcpy(pCurrentNote->name,modifiedName);
            continue;//һ��Ҫ��һ�䣡������Ȼ�������һ���ڵ㣬�����һ���ڵ�Ҳ��Ҫɾ���Ľڵ�Ļ����޷�ɾ����
        }
        pPreNote = pCurrentNote;
        pCurrentNote = pCurrentNote->next;
    }
    printf("�޸ĳɹ�\n");
    system("PAUSE");
}

void ModifyByTel(PRECORD head)
{
    PRECORD pPreNote = head;
    PRECORD pCurrentNote = head->next;
    char tel[20] = "";
    char modifiedName[20] = "";
    char modifiedTel[20] = "";
    char sel[20] = "";
    printf("please input the telephonenumber you would like to modify:");
    gets(tel);
    system("cls");
    if(!SearchByTelResult(head,tel))
    {
        printf("���޴���.\n");
        system("PAUSE");
        return;
    }
    printf("�޸��밴y/Y,�����밴�����");
    gets(sel); 
    printf("�������޸ĺ������:\n");
    gets(modifiedName);
    fflush(stdin);
    printf("�������޸ĺ�ĵ绰����:\n");
    gets(modifiedTel);
    fflush(stdin);
    if(strlen(sel) != 1 && sel[0] != 'Y' && sel[0] != 'y')
        return;
    while(pCurrentNote != NULL)
    {
        if(strcmp(pCurrentNote->tel,tel) == 0)
        {
            strcpy(pCurrentNote->tel,modifiedTel);
            continue;//һ��Ҫ��һ�䣡������Ȼ�������һ���ڵ㣬�����һ���ڵ�Ҳ��Ҫɾ���Ľڵ�Ļ����޷�ɾ����
        }
        pPreNote = pCurrentNote;
        pCurrentNote = pCurrentNote->next;
    }
    printf("�޸ĳɹ�\n");
    system("PAUSE");
}

void ModifyRecord(PRECORD head)
{
  while(1)
    {
        switch(Modifymenu(head))
        {
        case'1':
            ModifyByName(head);
            break;
        case'2':
            ModifyByTel(head);
            break;
         case'0':
            return;
            break;
        default:
            printf("Error,Please selecte [0-2]");
            system("PAUSE");
            break;
        }
    }  
}

void SortRecord(PRECORD head)
{
	switch(SortMenu())
	{
	case '1':
		SortByName(head);
		break;
	case '2':
		SortByTel(head);
		break;
	case '0':
		return;
	}
}
char SortMenu(void)
{
	char sel[5]="";
	system("cls");
	printf("-------SortRecord----------\n");
	printf("1.SortByName\n");
	printf("2.SortByTel\n");
	printf("0.exit\n");
	printf("---------------------------\n");
	printf("Please select : ");
	gets(sel);
	while(strlen(sel)!=1 || sel[0]<'0' || sel[0]>'2')
	{
		printf("Illegal input,please try again : ");
		gets(sel);
	}
	return sel[0];
}
void SortByName(PRECORD head)
{
	int flag=1;//----------------��־��ѭ���ȽϹ������Ƿ��н�������-------
	char temp[20]="",sel[5]="";
	PRECORD pPreNode = head;
	PRECORD pCurrentNode = pPreNode->next;
	if(pCurrentNode == NULL)
	{
		printf("There is no any Records !\n");
		printf("Any key to return to MainMenu ! \n");
		getche();
		return;
	}
	if(pCurrentNode->next == NULL)
	{
		printf("There is noly one record !\n");
		printf("%s	%s",pCurrentNode->name,pCurrentNode->tel);
		printf("Any key to return to MainMenu ! \n");
		getche();
		return;
	}
	while(flag)
	{
		flag=0;
		pPreNode = head;
		pCurrentNode = pPreNode ->next;
		while(pCurrentNode->next != NULL)
		{
			pPreNode = pCurrentNode;
			pCurrentNode = pPreNode->next;
			if(strcmp(pPreNode->name,pCurrentNode->name)>0)
			{
				flag++;//----------------���ȽϹ������н�����flag��ֵ�ı�---

				strcpy(temp,pPreNode->name);
				strcpy(pPreNode->name,pCurrentNode->name);
				strcpy(pCurrentNode->name,temp);
				strcpy(temp,pPreNode->tel);
				strcpy(pPreNode->tel,pCurrentNode->tel);
				strcpy(pCurrentNode->tel,temp);
			}
		}
	}
	printf("success!");
	BrowseRecord(head);
	getche();
}
void SortByTel(PRECORD head)
{
	int flag=1;//----------------��־��ѭ���ȽϹ������Ƿ��н�������-------
	char temp[20]="",sel[5]="";
	PRECORD pPreNode = head;
	PRECORD pCurrentNode = pPreNode->next;
	if(pCurrentNode == NULL)
	{
		printf("There is no any Records !\n");
		printf("Any key to return to MainMenu ! \n");
		getche();
		return;
	}
	if(pCurrentNode->next == NULL)
	{
		printf("There is noly one record !\n");
		printf("%s	%s",pCurrentNode->name,pCurrentNode->tel);
		printf("Any key to return to MainMenu ! \n");
		getche();
		return;
	}
	while(flag)
	{
		flag=0;
		pPreNode = head;
		pCurrentNode = pPreNode ->next;
		while(pCurrentNode->next != NULL)
		{
			pPreNode = pCurrentNode;
			pCurrentNode = pPreNode->next;
			if(strcmp(pPreNode->tel,pCurrentNode->tel)>0)
			{
				flag++;//----------------���ȽϹ������н�����flag��ֵ�ı�---

				strcpy(temp,pPreNode->name);
				strcpy(pPreNode->name,pCurrentNode->name);
				strcpy(pCurrentNode->name,temp);
				strcpy(temp,pPreNode->tel);
				strcpy(pPreNode->tel,pCurrentNode->tel);
				strcpy(pCurrentNode->tel,temp);
			}
		}
	}
	printf("success!");
	BrowseRecord(head);
	getche();
}

void ConserveRecord(PRECORD head)
{
	char path[20]="";
	FILE* fp=NULL;
	printf("Please input the path :");
	gets(path);
	fp=fopen(path,"w");
	while(head->next != NULL)
	{
		head = head->next;
		fprintf(fp,"%-15s%-15s\n",head->name,head->tel);
	}
	fclose(fp);
	printf("Record is successfully conserved as %s\n",path);
	printf("Any key to return to MainMenu !\n");
	getche();
}