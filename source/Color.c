#include<stdio.h>
#include<stdlib.h>
void changecolor(int score) {
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