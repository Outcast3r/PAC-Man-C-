#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<Windows.h>
#include<conio.h>
using namespace std;
int choice();// for choice which used
void read_data(int );//for reading data
void initialloadingscreen();//for Creating pacman
void write_data(int);//for writing score
bool checkLives(int);//for checking lives
void print_board(char map[19][32], int &score, int &Life);///for display board
void create_dots(char map[19][32]);//for creating dots in board
void user_input(char map[19][32], int &score, int &Life);
void move_right(char map[19][32], int &score, int &Life, int &row, int &col);//for move right
void move_left(char map[19][32], int &score, int &Life, int &row, int &col);//for move left
void move_down(char map[19][32], int &score, int &Life,int &row,int &col);//for move down
void move_up(char map[19][32], int &score, int &Life);//for move up
void calling(char ch, char map[19][32], int &row, int &col, int &score, int &Life);
void main()
{
	srand(time(NULL));
	for (;;)
	{

		int show, score = 0, Life = 3, che;
		char quit;
		che = choice();
		initialloadingscreen();
		if (che == 1)
		{
			char map[19][32] = {
				"+00000000000000000000000000000+",
				"0                             0",
				"0  000            000         0",
				"0                             0",
				"0  000            000         0",
				"0                             0",
				"0               000000        0",
				"0                             0",
				"0    0000                     0",
				"0               000000        0",
				"0                             0",
				"0                             0",
				"0          000000             0",
				"0                             0",
				"0                   0000      0",
				"0                             0",
				"0     000000                  0",
				"0                             0",
				"+00000000000000000000000000000+"
			};

			map[1][1] = 'P';////Position of pacman
			create_dots(map);
			print_board(map, score, Life);
			user_input(map, score, Life);
			write_data(score);
			cout << "\nIf you want to quit the game Press 'q'\n";
			cout << "Press any Key to Go Back Menu" << endl;

			cin >> quit;
			system("cls");
			if (quit == 'q')
			{
				exit(0);
			}

		}
		else if (che == 2)
		{
			cout << "press Enter to see  high score: " << endl;
			_getch();
			read_data(score);
			Sleep(2000);
			system("cls");
		}
		else if (che == 3)
		{
			system("CLS");
			cout << "\t\tINSTRUCTIONS\n\n\n";
			cout << " for movement to used arrow keys and pacman will eat 'L' then 20 score add  \n";
			cout << " if pacman eat 'M' then reduce life chances and total life is three 3 \n";
			cout << "\n\npress any key to go back\n";
			_getch();
			system("cls");
		}
		else if (che == 4)
		{
			exit(1);
			system("pause>0");
		}
	}

}
void initialloadingscreen()
{

	cout << "\n"
		".______      ___       ______ .___  ___.      ___      .__   __. \n"
		"|   _  \\    /   \\     /      ||   \\/   |     /   \\     |  \\ |  | \n"
		"|  |_)  |  /  ^  \\   |  ,----'|  \\  /  |    /  ^  \\    |   \\|  | \n"
		"|   ___/  /  /_\\  \\  |  |     |  |\\/|  |   /  /_\\  \\   |  . `  | \n"
		"|  |     /  _____  \\ |  `----.|  |  |  |  /  _____  \\  |  |\\   | \n"
		"| _|    /__/     \\__\\ \\______||__|  |__| /__/     \\__\\ |__| \\__| \n"
		"                                                                 \n"
		"";
	cout << "\n\n\n\n\t\t\tdevelopers: Waqas Manzoor, Ali Khalid, Hamza Hakim \n";
	Sleep(1000);
	system("cls");
}
int choice()
{

	cout << "\t\t\t\t\t Menu\n";

	cout << "\n\t\t1. play game\n" << "\n\t\t2. high score\n" << "\n\t\t3. help\n" << "\n\t\t4. exit" << endl;
	int choices;
	cout << "\n\t\tYour choice......: ";
	cin >> choices;
	cout << "\n\t\tplease wait.......";
	Sleep(700);
	system("cls");
	return choices;
}
void create_dots(char map[19][32])
{
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			if (map[i][j] == ' ')
			{
				map[i][j] = '.';
			}
		}
	}

	int x = rand() % 10 + 1;
	char powerPills = 'L';
	while (x != 0){
		int i = rand() % 17 + 1;
		int j = rand() % 27 + 1;
		if (i == 19 || i == 18){
			int k = 5;
			i = i - k;
		}
		if (j == 31 || j == 32)
		{
			int k = 5;
			j = j - k;
		}
		map[i][j] = powerPills;
		x--;
	}

	int y = 3;
	char mine = 'M';

	while (y != 0)
	{
		int i = rand() % 17 + 1;
		int j = rand() % 27 + 1;
		if (i == 19 || i == 18){
			int k = 5;
			i = i - k;
		}
		if (j == 31 || j == 32)
		{
			int k = 5;
			j = j - k;
		}
		map[i][j] = mine;
		y--;
	}


}
void print_board(char map[19][32], int &score, int &Life)
{
	system("color a");
	cout << endl << endl;
	for (int i = 0; i < 19; i++)
	{
		cout << "\t\t\t";
		for (int j = 0; j < 32; j++)
		{
			if (map[i][j] == 'L')
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			}

			else if (map[i][j] == 'M')
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
			}
			else if (map[i][j] == '0')
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);

			}
			else if (map[i][j] == 'P')
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			}
			cout << map[i][j] << " ";//for printing the board

		}
		cout << endl;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << " \n\n\t\t\t\t\t\t\t\t     Life: " << Life;
	cout << " \n\n\t\t\t\t\t\t\t\t     score: " << score << endl;
	cout << " \n\n\t\t\t\t\t\t\t\t     Press Q to Quit Game.. " << endl;

}
void user_input(char map[19][32], int &score, int &Life)
{

	int row = 1, col = 1;

	for (;;)
	{

		char ch = _getch();
		calling(ch, map, row, col, score, Life);
		if (checkLives(Life) == true)
		{
			break;
		}

	}
	system("cls");
	cout << " Game End " << endl;
}

void move_right(char map[19][32], int &row, int &col, int &score, int &Life)
{
	char a, b;

	if (map[row][col + 1] == '.' || map[row][col + 1] == 'L' || map[row][col + 1] == 'M')
	{
		if (map[row][col + 1] == '.')
		{
			map[row][col + 1] = ' ';
			score += 10;
		}
		if (map[row][col + 1] == 'L')
		{
			map[row][col + 1] = ' ';
			score += 20;

		}
		if (map[row][col + 1] == 'M')
		{
			map[row][col + 1] = ' ';
			Life--;


		}

	}
	else
	{


		if (map[row][col + 1] != '0')
		{

			a = map[row][col];
			map[row][col] = map[row][col + 1];
			map[row][col + 1] = a;
			col++;
			system("cls");
			print_board(map, score, Life);
		}


	}

}
void move_left(char map[19][32], int &row, int &col, int &score, int &Life)
{
	char a, b;


	if (map[row][col - 1] == '.' || map[row][col - 1] == 'L' || map[row][col - 1] == 'M')
	{
		if (map[row][col - 1] == '.')
		{
			map[row][col - 1] = ' ';
			score += 10;

		}
		if (map[row][col - 1] == 'L')
		{
			map[row][col - 1] = ' ';
			score += 20;
		}
		if (map[row][col - 1] == 'M')
		{
			map[row][col - 1] = ' ';
			Life--;

		}

	}
	else
	{
		if (map[row][col - 1] != '0')
		{
			a = map[row][col];
			map[row][col] = map[row][col - 1];
			map[row][col - 1] = a;
			--col;
			system("cls");

			print_board(map, score, Life);
		}
	}


}
void move_down(char map[19][32], int &row, int &col, int &score, int &Life)
{
	char a;
	if (map[row + 1][col] == '.' || map[row + 1][col] == 'L' || map[row + 1][col] == 'M')
	{
		if (map[row + 1][col] == '.')
		{
			map[row + 1][col] = ' ';

			score += 10;
		}
		if (map[row + 1][col] == 'L')
		{
			map[row + 1][col] = ' ';
			score += 20;
		}
		if (map[row + 1][col] == 'M')
		{
			map[row + 1][col] = ' ';
			Life--;
		}
	}

	else
	{
		if (map[row + 1][col] != '0')
		{

			a = map[row][col];
			map[row][col] = map[row + 1][col];
			map[row + 1][col] = a;
			row++;
			system("cls");

			print_board(map, score, Life);
		}
	}

}
void move_up(char map[19][32], int &row, int &col, int &score, int &Life)
{
	char a;

	if (map[row - 1][col] == '.' || map[row - 1][col] == 'L' || map[row - 1][col] == 'M')
	{
		if (map[row - 1][col] == '.')
		{
			map[row - 1][col] = ' ';
			score += 10;
		}
		if (map[row - 1][col] == 'L')
		{
			map[row - 1][col] = ' ';
			score += 20;
		}
		if (map[row - 1][col] == 'M')
		{
			map[row - 1][col] = ' ';
			Life--;
		}

	}
	else
	{
		if (map[row - 1][col] != '0')
		{
			a = map[row][col];
			map[row][col] = map[row - 1][col];
			map[row - 1][col] = a;
			row--;
			system("cls");

			print_board(map, score, Life);
		}
	}


}

void calling(char ch, char map[19][32], int &row, int &col, int &score, int &Life)
{

	if (ch == 77)
	{
		move_right(map, row, col, score, Life);
	}

	else {
		if (ch == 80)
		{
			move_down(map, row, col, score, Life);
		}
		else
		{
			if (ch == 75)
			{
				move_left(map, row, col, score, Life);
			}
			else
			{
				if (ch == 72)
				{
					move_up(map, row, col, score, Life);
				}
			}
		}
	}

	if (ch == 'q')
	{
		system("cls");
		cout << "<<<<<<.........Game Quit........>>>>>>>>>>" << endl;
		Sleep(1000);
		exit(0);
	}
}
bool checkLives(int l){
	if (l == 0){
		return true;
	}
	return false;
}
void write_data(int score)
{
	ofstream write_file;
	write_file.open("score.txt");
	if (!write_file.is_open())
	{
		cout << "Can't find the file.";
	}
	write_file << score;
	write_file.close();
}
void read_data(int score)
{
	ifstream read_file;
	read_file.open("score.txt");
	while (read_file >> score)
	{
		cout << " score : " << score << endl;

	}
	read_file.close();
}