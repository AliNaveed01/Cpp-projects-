#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
//#include<unistd.h>
#include<windows.h>
using namespace std;

int main()
{
	//purpose of code(project)
	cout << "The following code is a Game \n\n\t A basic Pacman game \t\n\n";

	// information about code
	cout << "\t INSTRUCTIONS" << endl;
	cout << "a) For moving, press" << endl;
	cout << "1: 'up key' for going UP" << endl;
	cout << "2: 'down key' for going DOWN" << endl;
	cout << "3: 'right key' for going RIGHT" << endl;
	cout << "4: 'left key' for going LEFT" << endl;
	cout << "b) Try not to touch the barriers" << endl;
	cout << "c) Eating the enemies will result in game over" << endl;
	cout << "d) You will have three lives before game ends" << endl;
	cout << "\n\n";
	cout << "----------------------------------------------------------\n" << endl;
	cout << "\t\tLEVELS" << endl;
	cout << " Press:  a) 'E' for easy" << endl;
	cout << "         b) 'M' for medium" << endl;
	cout << "         c) 'H' for hard" << endl;
	cout << "\n_______________________________________________________________\n";


	//declaration and initialliation of arrays and variables	
	string array[20][20];
	int x = 0, y = 0;
	int n = 1, m = 1;
	int n1 = 1, m1 = 18;
	int n2 = 17, m2 = 1;
	int n3 = 17, m3 = 17;
	int move, up = -1, down = -2, left = -3, right = -4;		//Player
	int move1 = 4, up1 = 1, down1 = 3, left1 = 2, right1 = 4;		//Enemy 01
	int move2 = 5, up2 = 5, down2 = 6, left2 = 7, right2 = 8;		//Enemy 02
	int move3 = 9, up3 = 12, down3 = 10, left3 = 11, right3 = 9;	//Enemy 03
	int score = 0;
	int lives = 3;






	//space for game
	for (x = 0; x < 20; x++)
	{
		for (y = 0; y < 20; y++)
		{
			cout << array[x][y];

		}
	}
	// design of game


	char level;
	cout << " Enter the difficulty level = ";
	cin >> level;
	if (level == 'E' || level == 'e')
	{

		for (x = 0; x < 20; x++)
		{
			for (y = 0; y < 20; y++)
			{
				if (x == 0 || x == 19)
				{
					array[x][y] = "#";

				}
				else if (y == 0 || y == 19)
				{
					array[x][y] = "#";
				}
				else if (x == 7 && y > 6 && y < 13)
				{
					array[x][y] = "#";
				}
				else if (x == 5 && y > 6 && y < 13)
				{
					array[x][y] = "#";
				}
				else if (y == 5 && x > 10 && x < 17)
				{
					array[x][y] = "#";
				}
				else if (y == 13 && x > 10 && x < 17)
				{
					array[x][y] = "#";
				}
				else if (y == 2 && x > 4 && x < 9)
				{
					array[x][y] = "#";
				}
				else if (x == 2 && y > 6 && y < 13)
				{
					array[x][y] = "#";
				}
				else if (x == 10 && y > 6 && y < 12)
				{
					array[x][y] = "#";
				}
				else if (x == 14 && y > 6 && y < 11)
				{
					array[x][y] = "#";
				}
				else if (y == 17 && x > 4 && x < 9)
				{
					array[x][y] = "#";
				}
				else if (y == 10 && x == 11)
				{
					array[x][y] = "o";

				}
				else if (y == 7 && x == 6)
				{
					array[x][y] = "o";

				}
				else if (y == 12 && x == 12)
				{
					array[x][y] = "o";

				}
				else if (y == 15 && x == 12)
				{
					array[x][y] = "o";

				}
				else if (y == 5 && x == 5)
				{
					array[x][y] = "o";
				}
				else if (y == 6 && x == 6)
				{
					array[x][y] = "o";
				}
				else if (y == 6 && x == 9)
				{
					array[x][y] = "o";
				}
				else if (y == 18 && x == 10)
				{
					array[x][y] = "o";
				}
				else
				{

					array[n1][m1] = "&";
					array[n2][m2] = "$";
					array[n3][m3] = "?";
					array[x][y] = ".";
				}

			}
		}
	}
	else if (level == 'M' || level == 'm')
	{

		for (x = 0; x < 20; x++)
		{
			for (y = 0; y < 20; y++)
			{
				if (x == 0 || x == 19)
				{
					array[x][y] = "#";

				}
				else if (y == 0 || y == 19)
				{
					array[x][y] = "#";
				}
				else if (x == 7 && y > 4 && y < 15)
				{
					array[x][y] = "#";
				}
				else if (x == 5 && y > 4 && y < 15)
				{
					array[x][y] = "#";
				}
				else if (y == 5 && x > 10 && x < 17)
				{
					array[x][y] = "#";
				}
				else if (y == 13 && x > 10 && x < 17)
				{
					array[x][y] = "#";
				}
				else if (y == 2 && x > 2 && x < 9)
				{
					array[x][y] = "#";
				}
				else if (y == 2 && x > 10 && x < 18)
				{
					array[x][y] = "#";
				}
				else if (x == 2 && y > 4 && y < 15)
				{
					array[x][y] = "#";
				}
				else if (x == 10 && y > 6 && y < 12)
				{
					array[x][y] = "#";
				}
				else if (x == 14 && y > 6 && y < 12)
				{
					array[x][y] = "#";
				}
				else if (y == 17 && x > 2 && x < 9)
				{
					array[x][y] = "#";
				}
				else if (y == 17 && x > 10 && x < 17)
				{
					array[x][y] = "#";
				}
				else if (y == 10 && x == 11)
				{
					array[x][y] = "o";

				}
				else if (y == 7 && x == 6)
				{
					array[x][y] = "o";

				}
				else if (y == 12 && x == 12)
				{
					array[x][y] = "o";

				}
				else if (y == 15 && x == 12)
				{
					array[x][y] = "o";

				}

				else if (y == 6 && x == 6)
				{
					array[x][y] = "o";
				}
				else if (y == 6 && x == 9)
				{
					array[x][y] = "o";
				}
				else if (y == 18 && x == 10)
				{
					array[x][y] = "o";
				}
				else
				{

					array[1][18] = "&";
					array[17][1] = "$";
					array[17][17] = "?";
					array[x][y] = ".";
				}

			}
		}
	}

	else if (level == 'H' || level == 'h')
	{

		for (x = 0; x < 20; x++)
		{
			for (y = 0; y < 20; y++)
			{
				if (x == 0 || x == 19)
				{
					array[x][y] = "#";

				}
				else if (y == 0 || y == 19)
				{
					array[x][y] = "#";
				}
				else if (x == 7 && y > 3 && y < 16)
				{
					array[x][y] = "#";
				}
				else if (x == 5 && y > 3 && y < 16)
				{
					array[x][y] = "#";
				}
				else if (y == 5 && x > 10 && x < 18)
				{
					array[x][y] = "#";
				}
				else if (y == 4 && x > 10 && x < 18)
				{
					array[x][y] = "#";
				}
				else if (y == 13 && x > 10 && x < 18)
				{
					array[x][y] = "#";
				}
				else if (y == 14 && x > 10 && x < 18)
				{
					array[x][y] = "#";
				}
				else if (y == 2 && x > 2 && x < 9)
				{
					array[x][y] = "#";
				}
				else if (y == 2 && x > 10 && x < 18)
				{
					array[x][y] = "#";
				}
				else if (x == 2 && y > 3 && y < 16)
				{
					array[x][y] = "#";
				}
				else if (x == 3 && y > 3 && y < 16)
				{
					array[x][y] = "#";
				}
				else if (x == 4 && y > 3 && y < 16)
				{
					array[x][y] = "#";
				}
				else if (x == 8 && y > 3 && y < 16)
				{
					array[x][y] = "#";
				}
				else if (x == 10 && y > 6 && y < 12)
				{
					array[x][y] = "#";
				}
				else if (x == 14 && y > 6 && y < 12)
				{
					array[x][y] = "#";
				}
				else if (x == 16 && y > 6 && y < 12)
				{
					array[x][y] = "#";
				}
				else if (x == 17 && y > 6 && y < 12)
				{
					array[x][y] = "#";
				}
				else if (y == 17 && x > 2 && x < 9)
				{
					array[x][y] = "#";
				}
				else if (y == 17 && x > 10 && x < 17)
				{
					array[x][y] = "#";
				}
				else if (y == 10 && x == 11)
				{
					array[x][y] = "o";

				}
				else if (y == 7 && x == 6)
				{
					array[x][y] = "o";

				}
				else if (y == 12 && x == 12)
				{
					array[x][y] = "o";

				}
				else if (y == 15 && x == 12)
				{
					array[x][y] = "o";

				}

				else if (y == 6 && x == 6)
				{
					array[x][y] = "o";
				}
				else if (y == 6 && x == 9)
				{
					array[x][y] = "o";
				}
				else if (y == 18 && x == 10)
				{
					array[x][y] = "o";
				}
				else
				{

					array[1][18] = "&";
					array[17][1] = "$";
					array[17][17] = "?";
					array[x][y] = ".";
				}

			}
		}
	}



	//printing of the array for game

	array[n][m] = "@";
	cout << "\t\t\t SCORE = " << score;
	cout << endl;
	for (x = 0; x < 20; x++)
	{
		for (y = 0; y < 20; y++)
		{
			if (array[x][y] == "@")
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			}
			else if (array[x][y] == "&")
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			}
			else if (array[x][y] == "?")
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			else if (array[x][y] == "$")
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
			}
			else if (array[x][y] == "o")
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
			}
			cout << array[x][y] << " ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);

		}
		cout << endl;
	}

	// conditions 

	while (lives != 0)
	{

		while (true)

		{
			if (level == 'e' || level == 'E')
			{
				Sleep(500);
			}
			else if (level == 'm' || level == 'M')
			{
				Sleep(300);
			}
			else if (level == 'h' || level == 'H')
			{
				Sleep(100);
			}

			//////////////////////////////////////
			if (GetAsyncKeyState(VK_DOWN)) {
				move = down;
				move1 = rand() % 4 + 1;
				move2 = rand() % 4 + 5;
				move3 = rand() % 4 + 9;

			}
			else if (GetAsyncKeyState(VK_UP)) {
				move = up;
				move1 = rand() % 4 + 1;
				move2 = rand() % 4 + 5;
				move3 = rand() % 4 + 9;

			}
			else if (GetAsyncKeyState(VK_LEFT
			)) {
				move = left;
				move1 = rand() % 4 + 1;
				move2 = rand() % 4 + 5;
				move3 = rand() % 4 + 9;

			}
			else if (GetAsyncKeyState(VK_RIGHT)) {
				move = right;
				move1 = rand() % 4 + 1;
				move2 = rand() % 4 + 5;
				move3 = rand() % 4 + 9;

			}
			if (move == down)
			{
				n++;
				if (n > 0)
				{
					array[n - 1][m] = " ";
				}

			}
			else if (move == up)
			{
				n--;
				if (n > 0)
				{
					array[n + 1][m] = " ";
				}
			}
			else if (move == left)
			{
				m--;
				if (n > 0)
				{
					array[n][m + 1] = " ";
				}
			}
			else if (move == right)
			{
				m++;
				if (n > 0)
				{
					array[n][m - 1] = " ";
				}
			}

			////////////////:ENEMY 01:///////////////////////////////////////////////////////////////
		/*
		if(n1==1 && m1==1) move1=rand()%4+1;
		if(n1==10 && m1==1) move1=rand()%4+1;
		if(n1==19 && m1==1) move1=rand()%4+1;
		if(n1==28 && m1==1) move1=rand()%4+1;
		if(n1=37 && m1==1) move1=rand()%4+1;
		if(n1==1 && m1==9) move1=rand()%4+1;
		if(n1==10 && m1==9) move1=rand()%4+1;
		if(n1==19 && m1==9) move1=rand()%4+1;
		if(n1==28 && m1==9) move1=rand()%4+1;
		if(n1==37 && m1==9) move1=rand()%4+1;
		if(n1==1 && m1==14) move1=rand()%4+1;
		if(n1==19 && m1==14) move1=rand()%4+1;
		if(n1==37 && m1==14) move1=rand()%4+1;
		if(n1==1 && m1==18) move1=rand()%4+1;
		if(n1==1 && m1==14) move1=rand()%4+1;//DUplicate
		if(n1==19 && m1==18) move1=rand()%4+1;
		if(n1==37 && m1==18) move1=rand()%4+1;
	*/
			if (n1 == n2 && m1 == m2)
			{
				move1 = rand() % 4 + 1;
				move2 = rand() % 4 + 5;
				move3 = rand() % 4 + 9;
			}
			if (n1 + 1 == n2 && m1 == m2)
			{
				move1 = rand() % 4 + 1;
				move2 = rand() % 4 + 5;
				move3 = rand() % 4 + 9;
			}
			if (n1 == n2 && m1 + 1 == m2)
			{
				move1 = rand() % 4 + 1;
				move2 = rand() % 4 + 5;
				move3 = rand() % 4 + 9;
			}
			if (n1 == n2 && m1 - 1 == m2)
			{
				move1 = rand() % 4 + 1;
				move2 = rand() % 4 + 5;
				move3 = rand() % 4 + 9;
			}
			if (n1 == n3 && m1 == m3)
			{
				move1 = rand() % 4 + 1;
				move2 = rand() % 4 + 5;
				move3 = rand() % 4 + 9;
			}
			if (n1 + 1 == n3 && m1 == m3)
			{
				move1 = rand() % 4 + 1;
				move2 = rand() % 4 + 5;
				move3 = rand() % 4 + 9;
			}
			if (n1 == n3 && m1 + 1 == m3)
			{
				move1 = rand() % 4 + 1;
				move2 = rand() % 4 + 5;
				move3 = rand() % 4 + 9;
			}
			if (n1 == n3 && m1 - 1 == m3)
			{
				move1 = rand() % 4 + 1;
				move2 = rand() % 4 + 5;
				move3 = rand() % 4 + 9;
			}
			if (n2 == n3 && m2 == m3)
			{
				move1 = rand() % 4 + 1;
				move2 = rand() % 4 + 5;
				move3 = rand() % 4 + 9;
			}
			if (n2 + 1 == n3 && m2 == m3)
			{
				move1 = rand() % 4 + 1;
				move2 = rand() % 4 + 5;
				move3 = rand() % 4 + 9;
			}
			if (n2 == n3 && m2 + 1 == m3)
			{
				move1 = rand() % 4 + 1;
				move2 = rand() % 4 + 5;
				move3 = rand() % 4 + 9;
			}
			if (n2 == n3 && m2 - 1 == m3)
			{
				move1 = rand() % 4 + 1;
				move2 = rand() % 4 + 5;
				move3 = rand() % 4 + 9;
			}
			///////////////////////////////:>ENEMY 01 <:////////////////////////////	

			if (move1 == left1)
			{
				if (array[n1 - 1][m1] == " ")

				{
					array[n1][m1] = " ";
					n1--;
					array[n1][m1] = "&";
				}
				else if (array[n1 - 1][m1] == ".")
				{
					array[n1][m1] = ".";
					n1--;
					array[n1][m1] = "&";
				}
				else if (array[n1 - 1][m1] == "@")
				{
					lives--;
					if (lives == 0)
					{
						break;
					}
					array[n1][m1] = ".";
					n1--;
					array[n1][m1] = "@";
				}
			}
			//////////////////////////////////////////////////////////////////////////////////////
			else if (move1 == right1)
			{
				if (array[n1 + 1][m1] == " ")
				{
					array[n1][m1] = " ";
					n1++;
					array[n1][m1] = "&";
				}
				else if (array[n1 + 1][m1] == ".")
				{
					array[n1][m1] = ".";
					n1++;
					array[n1][m1] = "&";
				}
				else if (array[n1 + 1][m1] == "@")
				{
					lives--;
					if (lives == 0)
					{
						break;
					}
					array[n1][m1] = ".";
					n1++;
					array[n1][m1] = "@";
				}
			}
			//////////////////////////////////////////////////////////////////////////////////////
			else if (move1 == up1)
			{
				if (array[n1][m1 - 1] == " ")
				{
					array[n1][m1] = " ";
					m1--;
					array[n1][m1] = "&";
				}
				else if (array[n1][m1 - 1] == ".")
				{
					array[n1][m1] = ".";
					m1--;
					array[n1][m1] = "&";
				}
				else if (array[n1][m1 - 1] == "@")
				{
					lives--;
					if (lives == 0)
					{
						break;
					}
					array[n1][m1] = ".";
					m1--;
					array[n1][m1] = "@";

				}
			}
			//////////////////////////////////////////////////////////////////////////////////////
			else if (move1 == down1)
			{
				if (array[n1][m1 + 1] == " ")
				{
					array[n1][m1] = " ";
					m1++;
					array[n1][m1] = "&";
				}
				else if (array[n1][m1 + 1] == ".")
				{
					array[n1][m1] = ".";
					m1++;
					array[n1][m1] = "&";
				}
				else if (array[n1][m1 + 1] == "@")
				{
					lives--;
					if (lives == 0)
					{
						break;
					}
					array[n1][m1] = ".";
					m1++;
					array[n1][m1] = "@";
				}
			}


			//////////////////////////////////////:>Enemy 02<://///////////////////////////////
			if (move2 == left2)
			{
				if (array[n2 - 1][m2] == " ")
				{
					array[n2][m2] = " ";
					n2--;
					array[n2][m2] = "$";
				}
				else if (array[n2 - 1][m2] == ".")
				{
					array[n2][m2] = ".";
					n2--;
					array[n2][m2] = "$";
				}
				else if (array[n2 - 1][m2] == "@")
				{
					lives--;
					if (lives == 0)
					{
						break;
					}
					array[n2][m2] = ".";
					n2--;
					array[n2][m2] = "@";
				}
			}
			//////////////////////////////////////////////////////////////////////////////////////
			else if (move2 == right2)
			{
				if (array[n2 + 1][m2] == " ")
				{
					array[n2][m2] = " ";
					n2++;
					array[n2][m2] = "$";
				}
				else if (array[n2 + 1][m2] == ".")
				{
					array[n2][m2] = ".";
					n2++;
					array[n2][m2] = "$";
				}
				else if (array[n2 + 1][m2] == "@")
				{
					lives--;
					if (lives == 0)
					{
						break;
					}
					array[n2][m2] = ".";
					n2++;
					array[n2][m2] = "@";
				}
			}
			//////////////////////////////////////////////////////////////////////////////////////
			else if (move2 == up2)
			{
				if (array[n2][m2 - 1] == " ")
				{
					array[n2][m2] = " ";
					m2--;
					array[n2][m2] = "$";
				}
				else if (array[n2][m2 - 1] == ".")
				{
					array[n2][m2] = ".";
					m2--;
					array[n2][m2] = "$";
				}
				else if (array[n2][m2 - 1] == "@")
				{
					lives--;
					if (lives == 0)
					{
						break;
					}
					array[n2][m2] = ".";
					m2--;
					array[n2][m2] = "@";
				}
			}
			//////////////////////////////////////////////////////////////////////////////////////
			else if (move2 == down2)
			{
				if (array[n2][m2 + 1] == " ")
				{
					array[n2][m2] = " ";
					m2++;
					array[n2][m2] = "$";
				}
				else if (array[n2][m2 + 1] == ".")
				{
					array[n2][m2] = ".";
					m2++;
					array[n2][m2] = "$";
				}
				else if (array[n2][m2 + 1] == "@")
				{
					lives--;
					if (lives == 0)
					{
						break;
					}
					array[n2][m2] = ".";
					m2++;
					array[n2][m2] = "@";

				}
			}
			//////////////////////////////////:>Enemy 03<:////////////////////////////////
			if (move3 == left3)
			{
				if (array[n3 - 1][m3] == " ")
				{
					array[n3][m3] = " ";
					n3--;
					array[n3][m3] = "?";
				}
				else if (array[n3 - 1][m3] == ".")
				{
					array[n3][m3] = ".";
					n3--;
					array[n3][m3] = "?";
				}
				else if (array[n3 - 1][m3] == "@")
				{
					lives--;
					if (lives == 0)
					{
						break;
					}
					array[n3][m3] = ".";
					n3--;
					array[n3][m3] = "@";

				}
			}
			//////////////////////////////////////////////////////////////////////////////////////
			else if (move3 == right3)
			{
				if (array[n3 + 1][m3] == " ")
				{
					array[n3][m3] = " ";
					n3++;
					array[n3][m3] = "?";
				}
				else if (array[n3 + 1][m3] == ".")
				{
					array[n3][m3] = ".";
					n3++;
					array[n3][m3] = "?";
				}
				else if (array[n3 + 1][m3] == "@")
				{
					lives--;
					if (lives == 0)
					{
						break;
					}
					array[n3][m3] = ".";
					n3++;
					array[n3][m3] = "@";
				}
			}
			//////////////////////////////////////////////////////////////////////////////////////
			else if (move3 == up3)
			{
				if (array[n3][m3 - 1] == " ")
				{
					array[n3][m3] = " ";
					m3--;
					array[n3][m3] = "?";
				}
				else if (array[n3][m3 - 1] == ".")
				{
					array[n3][m3] = ".";
					m3--;
					array[n3][m3] = "?";
				}
				else if (array[n3][m3 - 1] == "@")
				{
					lives--;
					if (lives == 0)
					{
						break;
					}
					array[n3][m3] = ".";
					m3--;
					array[n3][m3] = "@";

				}
			}
			//////////////////////////////////////////////////////////////////////////////////////
			else if (move3 == down3)
			{
				if (array[n3][m3 + 1] == " ")
				{
					array[n3][m3] = " ";
					m3++;
					array[n3][m3] = "?";
				}
				else if (array[n3][m3 + 1] == ".")
				{
					array[n3][m3] = ".";
					m3++;
					array[n3][m3] = "?";
				}
				else if (array[n3][m3 + 1] == "@")
				{
					lives--;
					if (lives == 0)
					{
						break;
					}
					array[n3][m3] = ".";
					m3++;
					array[n3][m3] = "@";
				}
			}
			//////////////////////////////////////////
			system("cls");
			if (array[n][m] == "&" || array[n][m] == "$" || array[n][m] == "?" || array[n][m] == "#")
			{

				lives--;
				if (lives == 0)
				{
					system("cls");
					cout << "\n\n*********************************************************************************************\n\n";
					cout << "GAME OVER..!";

					cout << "\t\t\t SCORE = " << score;
					cout << endl;
					break;
				}
			}
			else if (array[n][m] == "o")
			{
				cout << "immunity booster eaten";

			}
			// calculation of score 
			else if (array[n][m] == "." || array[n][m] == "o")
			{
				score++;
			}

			array[n][m] = "@";
			cout << "\t\t\t SCORE = " << score;
			cout << endl;
			cout << "\t Lives remaining = " << lives << endl;
			for (x = 0; x < 20; x++)
			{
				for (y = 0; y < 20; y++)
				{
					array[n][m] = "@";
					if (array[x][y] == "@")
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
					}
					else if (array[x][y] == "&")
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
					}
					else if (array[x][y] == "?")
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					}
					else if (array[x][y] == "$")
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
					}
					else if (array[x][y] == "o")
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
					}
					cout << array[x][y] << " ";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);

				}
				cout << endl;
			}

		}
	}



	system("pause");
	return 0;
}