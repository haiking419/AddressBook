#include <stdio.h>
#include <windows.h>
#pragma comment(lib,"winmm.lib")	//导入声音头文件库

#include "function.h"

void MusicPlayer(void)
{
	switch(MusicMenu())
	{
	case '1':
		Musicplay("Story2.wav");
		break;
	case '2':
		Musicplay("BlueStream.wav");
		break;
	case '3':
		Musicplay("Speech Off.wav");
		break;
	case '4':
		Musicclose();
		break;
	case '0':
		return;
	}
}

char MusicMenu(void)
{
	char sel[5]="";
	system("cls");
	printf("------------MsicMenu----------\n");
	printf("1.Story2.wav\n");
	printf("2.BlueStream.wav\n");
	printf("3.Speech Off.wav\n");
	printf("4.close music\n");
	printf("0.return\n");
	printf("Please select :");
	gets(sel);
	while(strlen(sel)!=1&&(sel[0]<'0'||sel[0]>3))
	{
		printf("Illegal input,please input [0~4] :");
		gets(sel);
	}
	return sel[0];
}

void Music(char path[20])
{
	PlaySound(path, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	Sleep(3*1000);
}

void Musicplay(char path[20])
{
	PlaySound(path, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void Musicclose(void)
{
	PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}
