#include <stdlib.h>

#include "function.h"
#include "data.h"


int main(void)
{
    PRECORD head=0;
    InitList(&head);
    head->next = GetRecordFromFile();//�������switch����ӵȹ��ܾͰ׷��ˡ��ᵼ���ڴ�й©��
	Musicplay("Story2.wav");
	while(1)//Ϊ��������Ļһֱ��ʾ
	{   
        switch ( MainMenu() )//ʵ�ʲ��������͸�������������
        {
            case '1':
                AddRecord(head);
                break;
            case '2':
                BrowseRecord(head);
                break;
            case '3':
                DelRecord(head);
                break;
            case '4':
                SearchRecord(head);
                break;
            case '5':
                ModifyRecord(head);
                break;
            case '6':
				SortRecord(head);
                break;
            case '7':
				ConserveRecord(head);
                break;
            case '8':
				MusicPlayer();
                break;
            case '0':
				Music("lost.wav");
				SaveRecord(head);
                DestoryList(head);
                exit(0);
                break;
            default:
                break;
            }
	}
	return 0;
}
