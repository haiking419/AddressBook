#include <stdlib.h>

#include "function.h"
#include "data.h"


int main(void)
{
    PRECORD head=0;
    InitList(&head);
    head->next = GetRecordFromFile();//如果放在switch，添加等功能就白费了。会导致内存泄漏！
	Musicplay("Story2.wav");
	while(1)//为的是让屏幕一直显示
	{   
        switch ( MainMenu() )//实际参数的类型个数，这里由于
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
