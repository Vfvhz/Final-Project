#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define Space 32
#define Air 0
#define Dinosaur 1     //���s���y�м���
#define Obstacle 2      //��ê���y�м���
#define BAR 3       //�𪺮y�м���
void print_game(void);
void HideCursor(void);
void gotoxy(int x, int y);
void changecolor(int color);
//��l�Ʀa�� 80*25
char map[25][80];
int score, game, Dx, Dy, Ox, Ox2, Ox3, jump_temp, jump, DS;
clock_t begin, end;
double cost;
game = 0;
jump = 0;
score = 0;
DS = 1;
int main()
{
	system("color 70");
	srand(time(0));
	int x, y;
	Dx = 3; Ox = 48; Dy = 23; Ox2 = 65; Ox3 = 79;
	//��l�Ʈ��s�y��
	map[Dy][Dx] = Dinosaur;
	//��l�ƻ�ê�y��
	map[23][Ox] = Obstacle;
	map[23][Ox2] = Obstacle;
	map[23][Ox3] = Obstacle;
	//�a�O
	for (x = 0; x < 25; x++)
	{
		for (y = 0; y < 50; y++)
		{
			if (x == 24)
				map[x][y] = BAR;
		}
	}
	//�}�l
	printf("�����N��}�l!");
	getch();
	begin = clock();
	//�D�n���e
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
		//�P�_���D
		if (kbhit() != 0)
		{
			jump_temp = getch();
			if ((jump_temp == Space) && (jump == 0))
			{
				jump = 1;
			}
			jump_temp == 0;
		}
		//���D����
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
		//�N��ê�M�����s�X�{
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
	end = clock();
	cost = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\n�C���ɶ�: %0.2lf secs",cost);
	printf("\nGame Over!!!!!!\n");
}
void print_game(void) {
	int i, j;
	changecolor(score);
	//�ھڦa�ϤW�C�I�����pø�s�C���] i ��� x �b�Aj ��� y �b�^�A����C�L
	for (i = 0; i < 25; i++)
	{
		for (j = 0; j < 50; j++) {
			//�ťզa��
			if (map[i][j] == 0) {
				printf("  ");
			}
			//���s
			else if (map[i][j] == Dinosaur) {
				printf("�s");
			}
			//����
			else if (map[i][j] == BAR) {
				printf("�a");
			}
			//��ê
			else if (map[i][j] == Obstacle) {
				printf("��");
			}
		}
		putchar('\n');
	}
	gotoxy(0, 0);
	printf("score:%d", score);
	Sleep(1);//��v�禡  
	score++;
}
void gotoxy(int x, int y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(handle, coord);//�w���handle�o�ӵ����A���Х��bcoord�y��
}