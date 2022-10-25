#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> test;
void init_desk(int massive[][8], int size)// int * massive[] // Инициализирует доску
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			massive[i][j] = 0;
		}
	}
	
}
void show_desk(int massive[][8], int size) // Показать доску
{
	system("cls");// Очитска экрана

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout <<massive[i][j] <<" ";
		}
		cout << "\n";
	}
	if (!test.empty())
		for (auto item : test)
		{
			cout << item << "\n";
		}
}
//смещение по X и по Y принимают значени -1, 1, 2, -2 
//при этом если смещение по X будет по модулю 1 (-1,1),
//то смещение по Y будет 2 по модулю (-2, 2)

void get_x_y(int dir[])
{
	srand((unsigned)time(NULL));// Функция случайности

	int x = rand() % 2 + 1;
	int y = 3 - x;
	if (rand() % 2 == 1) 
	{
		x = 0 - x;
	}
	
	if(rand()%2 == 1)
	{
		y = 0 - 2;
	}
	dir[0] = x;
	dir[1] = y;


}
void get_func(int number, int dir[]) // Получает случайную функцию хода конем
{
	srand((unsigned)time(NULL));

	switch (number)
	{
	case 0:
		dir[0] = -2;
		dir[1] = -1;
		break;
	case 1:
		dir[0] = -2;
		dir[1] = 1;
		break;
	case 2:
		dir[0] = -1;
		dir[1] = -2;
		break;
	case 3:
		dir[0] = -1;
		dir[1] = 2;
		break;
	case 4:
		dir[0] = 1;
		dir[1] = -2;
		break;
	case 5:
		dir[0] = 1;
		dir[1] = 2;
		break;
	case 6:
		dir[0] = 2;
		dir[1] = 1;
		break;
	case 7:
		dir[0] = 2;
		dir[1] = -1;
		break;

	default:
		break;
	}

}
void  get_x_y_2(int dir[])
{

	srand((unsigned)time(NULL));
	int temp = rand() % 8;
	get_func(temp, dir);
	


}
bool check_move(int desk[][8], int _x, int _y)
{
	int dir[2];
	for (int i = 0; i < 8; i++) 
	{
		get_func(i, dir);
		int div_x = dir[0];
		int div_y = dir[1];
		if (_x + div_x>=0 
			&& _x + div_x<=7 
			&& _y + div_y >=0
			&& _y + div_y <=7
			&& desk[_x + div_x][_y + div_y] == 0)
		{
			return true;
		}

	}
	return false;

}
void hourse_move(int massive[][8], int size, int cur_x, int cur_y)
{
	int dir[2]{0};
	int div_x, div_y;
	if (check_move(massive, cur_x, cur_y))
	{

		do {


			get_x_y(dir);
			div_x = dir[0];
			div_y = dir[1];

		} while
			(
				cur_x + div_x < 0
				|| cur_x + div_x > 7
				|| cur_y + div_y < 0
				|| cur_y + div_y > 7
				|| massive[cur_x + div_x][cur_y + div_y] == 1
				||!check_move(massive, cur_x + div_x, cur_y + div_y)
				
				);
			

		massive[cur_x + div_x][cur_y + div_y] = 1;
		show_desk(massive, 8);
		system("pause");
		test.push_back("X: " + std::to_string(cur_x + div_x) + "Y: " + std::to_string(cur_y + div_y));
		hourse_move(massive, 8, cur_x + div_x, cur_y + div_y);
	}
	
	


}
int main()
{

	int x = 0;
	int y = 0;
	int desk[8][8];
	init_desk(desk,8);
	desk[x][y] = 1;
	
	hourse_move(desk, 8, x,y);

	return 0;
}