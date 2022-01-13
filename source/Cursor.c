#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
//ÁôÂÃ¥ú¼Ð
void HideCursor(void)
{
	CONSOLE_CURSOR_INFO cursor_info = { 1,0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}