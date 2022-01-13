#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define Space 32
#define Air 0
#define Dinosaur 1     //恐龍的座標標識
#define Obstacle 2      //障礙的座標標識
#define BAR 3       //牆的座標標識
void print_game(void);
void HideCursor(void);
void gotoxy(int x, int y);
void changecolor();
//初始化地圖 130*25
char map[25][80];
int score, game, Dx, Dy, Ox, Ox2, Ox3, jump_temp, jump, DS, T;
game = 0;
jump = 0;
score = 0;
DS = 1;
int main()
{
	system("color 70");
	srand(time(NULL));
	int x, y;
	Dx = 3; Ox = 48; Dy = 23; Ox2 = 65; Ox3 = 79; T = 1;
	//初始化恐龍座標
	map[Dy][Dx] = Dinosaur;
	//初始化障礙座標
	map[23][Ox] = Obstacle;
	map[23][Ox2] = Obstacle;
	map[23][Ox3] = Obstacle;
	//地板
	for (x = 0; x < 25; x++)
	{
		for (y = 0; y < 50; y++)
		{
			if (x == 24)
				map[x][y] = BAR;
		}
	}
	//開始
	printf("按任意鍵開始!");
	getch();
	//主要內容
	while (1)
	{
		HideCursor();
		print_game();
		map[23][Ox] = Air;
		map[23][Ox2] = Air;
		map[23][Ox3] = Air;
		Ox--; Ox2--; Ox3--;
		map[23][Ox] = Obstacle;
		map[23][Ox2] = Obstacle;
		map[23][Ox3] = Obstacle;
		if (map[Dy][Dx] == Obstacle)
		{
			break;
		}
		//判斷跳躍
		if (kbhit() != 0)
		{
			jump_temp = getch();
			if ((jump_temp == Space) && (jump == 0))
			{
				jump = 1;
			}
			jump_temp == 0;
		}
		//跳躍移動
		if (jump == 1)
		{
			map[Dy][Dx] = Air;
			if ((0 < DS) && (DS < 5))
			{
				Dy--;
				DS++;
			}
			else if (DS == 5)
			{
				DS = -1;
			}
			else if ((-5 < DS) && (DS < 0))
			{
				Dy++;
				DS--;
			}
			else if (DS == -5)
			{
				DS = 1;
				jump = 0;
			}
			map[Dy][Dx] = Dinosaur;
		}
		//將障礙清除重新出現
		if (Ox == 0)
		{
			map[23][0] = Air;
			Ox = ((rand() % 30) + 50);
		}
		else if (Ox2 == 0)
		{
			map[23][0] = Air;
			Ox2 = ((rand() % 30) + 50);

		}
		else if (Ox3 == 0)
		{
			map[23][0] = Air;
			Ox3 = ((rand() % 30) + 50);
		}
	}
	printf("Game Over!!!!!!");
}
void print_game(void) {
	int i, j;
	changecolor();
	//根據地圖上每點的情況繪製遊戲（ i 表示 x 軸，j 表示 y 軸），按行列印
	for (i = 0; i < 25; i++)
	{
		for (j = 0; j < 50; j++) {
			//空白地方
			if (map[i][j] == 0) {
				printf("  ");
			}
			//恐龍
			else if (map[i][j] == Dinosaur) {
				printf("龍");
			}
			//圍欄
			else if (map[i][j] == BAR) {
				printf("地");
			}
			//障礙
			else if (map[i][j] == Obstacle) {
				printf("石");
			}
		}
		putchar('\n');
	}
	gotoxy(0, 0);
	printf("score:%d", score);
	Sleep(1);//休眠函式  
	score++;
}
//隱藏光標
void HideCursor(void)
{
	CONSOLE_CURSOR_INFO cursor_info = { 1,0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void gotoxy(int x, int y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(handle, coord);//定位到handle這個視窗，把游標打在coord座標
}

void changecolor() {
	int color;
	if (score > 500)
	{
		color = rand() % 6;
		switch (color)
		{
		case 0:
			system("color 42");
			break;
		case 1:
			system("color 14");
			break;
		case 2:
			system("color 41");
			break;
		case 3:
			system("color 24");
			break;
		case 4:
			system("color 56");
			break;
		case 5:
			system("color 65");
			break;
		}
	}
}      