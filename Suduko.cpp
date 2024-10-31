#include<iostream>//Bismillah e rahman e raheem
#include<fstream>
#include <ctime> 
using namespace std;
void menu(char [], char[], char[]);
void newgame(char [], char[], char[]);
int random_num();
void easygame(char [], char[], char[]);
void intermediategame(char pause[], char solved[], char highscore[]);
void hardgame(char pause[], char solved[], char highscore[]);
void resumegame(char pause[], char solved[], char highscore[]);
bool filewrite(ofstream&, char[]);
bool fileread(ifstream& file, char filename[]);
void displayHS(char filename[]);
int main()
{
	srand((unsigned)time(0));
	char pause[]={"pause.txt"};
	char solved[] = { "solved.txt" };
	char highscore[] = { "highscore.txt" };
	menu(pause, solved, highscore);

	system("pause");
	return 0;
}
void menu(char pause[], char solved[], char highscore[])
{
	int option = 0;
	while (option < 1 || option >4)
	{
		cout << "Welcome to SUDUKO" << endl << endl << endl;
		cout << "1-New game" << endl;
		cout << "2-Resume game" << endl;
		cout << "3-High score" << endl;
		cout << "4-Exit" << endl;
		cout << endl;
		cout << "Enter option number" << endl;
		cin >> option;
		if (option == 1)
		{
			newgame(pause, solved, highscore);
		}
		else if (option == 2)
		{
			resumegame(pause, solved, highscore);
		}
		else if (option == 3)
		{
			void displayHS(char filename[]);
		}
		else if (option == 4)
		{
			cout << "Thank you for playing" << endl << endl;
			exit(-1);
		}
		else
		{
			cout << "Please enter valid number" << endl;
		}
	}
}
void newgame(char pause[], char solved[], char highscore[])
{
	int suboption = 0;
	cout << "1-Easy level" << endl;
	cout << "2-Intermediate level" << endl;
	cout << "3-Hard level" << endl;
	cout << "4-Main menu" << endl << endl;
	cout << "Enter option number" << endl;
	cin >> suboption;
	if (suboption == 1)
	{
		easygame(pause,solved, highscore);
	}
	else if (suboption == 2)
	{
		intermediategame(pause, solved, highscore);
	}
	else if (suboption == 3)
	{
		hardgame(pause, solved, highscore);
	}
	else if (suboption == 4)
	{
		menu(pause, solved, highscore);
	}
}
int random_num()
{
	int num = 0;
	num = (rand() % 9)+1;
	return num;
}
void easygame(char pause[],char solved[], char highscore[])
{

	int row = 0, col = 0, i = 0;
	int num = 1, c = 0, put = 0;
	const int SIZE = 9;
	int suduko[SIZE][SIZE] = { 0 };
	bool flag = false;
	bool num_booked = true;
	for (int i = 0; i < SIZE; i++)
	{
		bool flag = false;
		while (flag == false)
		{
			flag = true;
			num = random_num();
			for (int j = 0; j < i; j++)
			{
				if (suduko[0][j] == num)
				{
					flag = false;
					break;
				}
			}
		}
		suduko[0][i] = num;
	}
	int temp = 0;
	for (int a = 1; a < SIZE; a++)
	{
		temp = 0;
		if (a == 3 || a == 6)
		{
			for (int b = 0; b < SIZE; b++)
			{
				if (b + 1 < 9)
				{
					suduko[a][b] = suduko[a - 1][b + 1];
				}
				else
				{
					suduko[a][b] = suduko[a - 1][0];
				}
			}
		}
		else
		{
			for (int b = 0; b < SIZE; b++)
			{
				if (b + 3 <= 8)
				{
					suduko[a][b] = suduko[a - 1][b + 3];
				}
				else
				{
					suduko[a][b] = suduko[a - 1][temp];
					temp++;
				}
			}
		}

	}
	int Newsuduko[SIZE][SIZE] = { 0 };
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			Newsuduko[i][j] = suduko[i][j];
		}
	}
/*	cout << "BEFORE EASY" << endl;
	cout << "   ";
	for (int i = 0; i < SIZE; i++)
	{
		cout<< i << " ";
	}
	cout << endl << endl;
	for (int i = 0; i < SIZE; i++)
	{
		cout << i << "  ";

		for (int j = 0; j < SIZE; j++)
		{
			cout << Newsuduko[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;*/
	///////////calcuations and initilialization/////
	int easy;
	easy = (90 * 81) / 100;
	easy = 81 - easy;
	i = 0;
	row = random_num();
	col = random_num();
	///////////////////////////////////////////////////
	cout << easy << " slots to fill" << endl << endl;
	//cout << "AFTER EASY" << endl;
	while (i < easy)
	{
		if (Newsuduko[row][col] != 0)
		{
			Newsuduko[row][col] = 0;
			row = random_num();
			col = random_num();
			i++;
		}
		else
		{
			row = random_num();
			col = random_num();
		}
	}//////////////////////////////////////////////////////////////////////////////////////////////
	cout << "   ";
	for (int i = 0; i < SIZE; i++)
	{
		cout << i << " ";
	}
	cout << endl << endl;
	for (int i = 0; i < SIZE; i++)
	{
		cout << i << "  ";
		for (int j = 0; j < SIZE; j++)
		{
			if (Newsuduko[i][j] == 0)
			{
				cout << "X ";
			}
			else
			{
				cout << Newsuduko[i][j] << " ";
			}
		}
		cout << endl;
	}
	ofstream filep;
	ofstream files;
	ofstream fileW;
	ifstream fileR;
	int addnum = 0;
	int rownum = 0;
	int colnum = 0;
	int numhs = 0;
	bool openfp = true;
	bool openfs = true;
	char letter = '\0';
	easy = 0;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (Newsuduko[i][j] == 0)
			{
				easy++;
			}
		}
	}
	for (int q = 0; q < easy;)
	{
		cout << "Enter number to add / press -99 to pause" << endl;
		cin >> addnum;
		if (addnum == -99)
		{
			openfp = filewrite(filep, pause);
			openfs = filewrite(files, solved);
			if (openfp == false || openfs == false)
			{
				cout << "Cannot save game" << endl;
				cout << "Continue game(c) or exit game without saving(e)" << endl;
				cin >> letter;
				if (letter == 'c')
				{
					continue;
				}
				else if (letter == 'e')
				{
					exit(-1);
				}
			}
			else
			{
				for (int i = 0; i < SIZE; i++)
				{
					for (int j = 0; j < SIZE; j++)
					{
						filep << Newsuduko[i][j];
					}
					filep << endl;
				}
				for (int i = 0; i < SIZE; i++)
				{
					for (int j = 0; j < SIZE; j++)
					{
						files << suduko[i][j];
					}
					files << endl;
				}
				cout << "File saved" << endl;
				filep.close();
				files.close();
				exit(-1);
			}
		}
		else if (addnum < 1 || addnum> 9)
		{
			cout << "Enter number between 1 - 9" << endl;
		}
		else
		{
			cout << "Enter row number" << endl;
			cin >> rownum;
			cout << "Enter column number" << endl;
			cin >> colnum;
			if (Newsuduko[rownum][colnum] != 0)
			{
				cout << "This slot is full. Try again" << endl;
			}
			else
			{
				Newsuduko[rownum][colnum] = addnum;
				cout << "Number added" << endl;
				cout << "   ";
				for(int i=0;i<SIZE;i++)
				{
					cout << i << " ";
				}
				cout << endl << endl;
				for (int i = 0; i < SIZE; i++)
				{
					cout << i << "  ";
					for (int j = 0; j < SIZE; j++)
					{
						if (Newsuduko[i][j] == 0)
						{
							cout << "X ";
						}
						else
						{
							cout << Newsuduko[i][j] << " ";
						}
					}
					cout << endl;
				}
				if (Newsuduko[rownum][colnum] == suduko[rownum][colnum])
				{
					numhs++;
				}
				q++;
			}
		}
	}
	cout << "Score = " << numhs << endl;
	temp = true;
	int j = 0;
	bool unique = true;
	temp = fileread(fileR, highscore);
	int hsarr[5] = { 0 };
	i = 0;
	int min = 0;
	if (temp == true)
	{
		while (fileR >> hsarr[i])
		{
			i++;
		}
		fileR.close();
		if (i > 5)
		{
			while (j < i)
			{
				min = hsarr[j];
				if (hsarr[j] < min)
				{
					min = hsarr[j];
				}
				if (numhs == hsarr[j])
				{
					unique = false;
				}
				j++;
			}
			if (unique == true)
			{
				j = 0;
				while (hsarr[j] != min)
				{
					j++;
				}
				hsarr[j] = numhs;
			}
			fileW.open(highscore, ios::trunc);
			j = 0;
			while (fileW << hsarr[j])
			{
				j++;
			}
			fileW.close();
		}
		else
		{
			j = 0;
			fileW.close();
			temp = filewrite(fileW, highscore);
			while (j < i)
			{
				if (numhs == hsarr[j])
				{
					unique = false;
				}
				j++;
			}
			if (unique == true)
			{
				fileW << numhs;
				fileW.close();
			}

		}
	}
	else
	{
		cout << "Highscore.txt not open" << endl;
	}
}
void intermediategame(char pause[], char solved[], char highscore[])
{

	int row = 0, col = 0, i = 0;
	int num = 1, c = 0, put = 0;
	const int SIZE = 9;
	int suduko[SIZE][SIZE] = { 0 };
	bool flag = false;
	bool num_booked = true;
	for (int i = 0; i < SIZE; i++)
	{
		bool flag = false;
		while (flag == false)
		{
			flag = true;
			num = random_num();
			for (int j = 0; j < i; j++)
			{
				if (suduko[0][j] == num)
				{
					flag = false;
					break;
				}
			}
		}
		suduko[0][i] = num;
	}
	int temp = 0;
	for (int a = 1; a < SIZE; a++)
	{
		temp = 0;
		if (a == 3 || a == 6)
		{
			for (int b = 0; b < SIZE; b++)
			{
				if (b + 1 < 9)
				{
					suduko[a][b] = suduko[a - 1][b + 1];
				}
				else
				{
					suduko[a][b] = suduko[a - 1][0];
				}
			}
		}
		else
		{
			for (int b = 0; b < SIZE; b++)
			{
				if (b + 3 <= 8)
				{
					suduko[a][b] = suduko[a - 1][b + 3];
				}
				else
				{
					suduko[a][b] = suduko[a - 1][temp];
					temp++;
				}
			}
		}

	}
	int Newsuduko[SIZE][SIZE] = { 0 };
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			Newsuduko[i][j] = suduko[i][j];
		}
	}
	/*cout << "BEFORE EASY" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		cout << "   " << i << " ";
	}
	cout << endl;
	for (int i = 0; i < SIZE; i++)
	{
		cout << i << "  ";
		for (int j = 0; j < SIZE; j++)
		{
			cout << Newsuduko[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;*/
	///////////calcuations and initilialization/////
	int intermediate;
	intermediate = (50 * 81) / 100;
	intermediate = 81 - intermediate;
	i = 0;
	row = random_num();
	col = random_num();
	///////////////////////////////////////////////////
	cout << intermediate << " slots to fill" << endl << endl;
	//cout << "AFTER EASY" << endl;
	while (i < intermediate)
	{
		if (Newsuduko[row][col] != 0)
		{
			Newsuduko[row][col] = 0;
			row = random_num();
			col = random_num();
			i++;
		}
		else
		{
			row = random_num();
			col = random_num();
		}
	}
	cout << "   ";
	for (int i = 0; i < SIZE; i++)
	{
		cout << i << " ";
	}
	cout << endl << endl;
	for (int i = 0; i < SIZE; i++)
	{
		cout << i << "  ";
		for (int j = 0; j < SIZE; j++)
		{
			if (Newsuduko[i][j] == 0)
			{
				cout << "X ";
			}
			else
			{
				cout << Newsuduko[i][j] << " ";
			}
		}
		cout << endl;
	}
	ofstream filep;
	ofstream files;
	ofstream fileW;
	ifstream fileR;
	int addnum = 0;
	int rownum = 0;
	int colnum = 0;
	int numhs = 0;
	bool openfp = true;
	bool openfs = true;
	char letter = '\0';
	for (int q = 0; q < intermediate; )
	{
		cout << "Enter number to add / press -99 to pause" << endl;
		cin >> addnum;
		if (addnum == -99)
		{
			openfp = filewrite(filep, pause);
			openfs = filewrite(files, solved);
			if (openfp == false || openfs == false)
			{
				cout << "Cannot save game" << endl;
				cout << "Continue game(c) or exit game without saving(e)" << endl;
				cin >> letter;
				if (letter == 'c')
				{
					continue;
				}
				else if (letter == 'e')
				{
					exit(-1);
				}
			}
			else
			{
				for (int i = 0; i < SIZE; i++)
				{
					for (int j = 0; j < SIZE; j++)
					{
						filep << Newsuduko[i][j];
					}
					filep << endl;
				}
				for (int i = 0; i < SIZE; i++)
				{
					for (int j = 0; j < SIZE; j++)
					{
						files << suduko[i][j];
					}
					files << endl;
				}
				cout << "File saved" << endl;
				filep.close();
				files.close();
				exit(-1);
			}
		}
		else if (addnum < 1 || addnum> 9)
		{
			cout << "Enter number between 1 - 9" << endl;
		}
		else
		{
			cout << "Enter row number" << endl;
			cin >> rownum;
			cout << "Enter column number" << endl;
			cin >> colnum;
			if (Newsuduko[rownum][colnum] != 0)
			{
				cout << "This slot is full. Try again" << endl;
			}
			else
			{
				Newsuduko[rownum][colnum] = addnum;
				cout << "Number added" << endl;
				cout << "   ";
				for (int i = 0; i < SIZE; i++)
				{
					cout << i << " ";
				}
				cout << endl << endl;
				for (int i = 0; i < SIZE; i++)
				{
					cout << i << "  ";

					for (int j = 0; j < SIZE; j++)
					{
						if (Newsuduko[i][j] == 0)
						{
							cout << "X ";
						}
						else
						{
							cout << Newsuduko[i][j] << " ";
						}
					}
					cout << endl;
				}
				if (Newsuduko[rownum][colnum] == suduko[rownum][colnum])
				{
					numhs++;
				}
				q++;
			}
		}
	}
	cout << "Score = " << numhs << endl;
	temp = true;
	int j = 0;
	bool unique = true;
	temp = fileread(fileR, highscore);
	int hsarr[5] = { 0 };
	i = 0;
	int min = 0;
	if (temp == true)
	{
		while (fileR >> hsarr[i])
		{
			i++;
		}
		fileR.close();
		if (i > 5)
		{
			while (j < i)
			{
				min = hsarr[j];
				if (hsarr[j] < min)
				{
					min = hsarr[j];
				}
				if (numhs == hsarr[j])
				{
					unique = false;
				}
				j++;
			}
			if (unique == true)
			{
				j = 0;
				while (hsarr[j] != min)
				{
					j++;
				}
				hsarr[j] = numhs;
			}
			fileW.open(highscore, ios::trunc);
			j = 0;
			while (fileW << hsarr[j])
			{
				j++;
			}
			fileW.close();
		}
		else
		{
			j = 0;
			fileW.close();
			temp = filewrite(fileW, highscore);
			while (j < i)
			{
				if (numhs == hsarr[j])
				{
					unique = false;
				}
				j++;
			}
			if (unique == true)
			{
				fileW << numhs;
				fileW.close();
			}

		}
	}
	else
	{
		cout << "Highscore.txt not open" << endl;
	}
}
void hardgame(char pause[], char solved[], char highscore[])
{

	int row = 0, col = 0, i = 0;
	int num = 1, c = 0, put = 0;
	const int SIZE = 9;
	int suduko[SIZE][SIZE] = { 0 };
	bool flag = false;
	bool num_booked = true;
	for (int i = 0; i < SIZE; i++)
	{
		bool flag = false;
		while (flag == false)
		{
			flag = true;
			num = random_num();
			for (int j = 0; j < i; j++)
			{
				if (suduko[0][j] == num)
				{
					flag = false;
					break;
				}
			}
		}
		suduko[0][i] = num;
	}
	int temp = 0;
	for (int a = 1; a < SIZE; a++)
	{
		temp = 0;
		if (a == 3 || a == 6)
		{
			for (int b = 0; b < SIZE; b++)
			{
				if (b + 1 < 9)
				{
					suduko[a][b] = suduko[a - 1][b + 1];
				}
				else
				{
					suduko[a][b] = suduko[a - 1][0];
				}
			}
		}
		else
		{
			for (int b = 0; b < SIZE; b++)
			{
				if (b + 3 <= 8)
				{
					suduko[a][b] = suduko[a - 1][b + 3];
				}
				else
				{
					suduko[a][b] = suduko[a - 1][temp];
					temp++;
				}
			}
		}

	}
	int Newsuduko[SIZE][SIZE] = { 0 };
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			Newsuduko[i][j] = suduko[i][j];
		}
	}
	/*cout << "BEFORE EASY" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		cout << "   " << i << " ";
	}
	for (int i = 0; i < SIZE; i++)
	{
		cout << i << "  ";
		for (int j = 0; j < SIZE; j++)
		{
			cout << Newsuduko[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;*/
	///////////calcuations and initilialization/////
	int hard;
	hard = (10 * 81) / 100;
	hard = 81 - hard;
	i = 0;
	row = random_num();
	col = random_num();
	///////////////////////////////////////////////////
	cout << hard << " slots to fill" << endl << endl;
//	cout << "AFTER EASY" << endl;
	while (i < hard)
	{
		if (Newsuduko[row][col] != 0)
		{
			Newsuduko[row][col] = 0;
			row = random_num();
			col = random_num();
			i++;
		}
		else
		{
			row = random_num();
			col = random_num();
		}
	}
	cout << "   ";
	for (int i = 0; i < SIZE; i++)
	{
		cout << i << " ";
	}
	cout << endl << endl;
	for (int i = 0; i < SIZE; i++)
	{
		cout << i << "  ";
		for (int j = 0; j < SIZE; j++)
		{
			if (Newsuduko[i][j] == 0)
			{
				cout << "X ";
			}
			else
			{
				cout << Newsuduko[i][j] << " ";
			}
		}
		cout << endl;
	}
	ofstream filep;
	ofstream files;
	ofstream fileW;
	ifstream fileR;
	int addnum = 0;
	int rownum = 0;
	int colnum = 0;
	int numhs = 0;
	bool openfp = true;
	bool openfs = true;
	char letter = '\0';
	for (int q = 0; q < hard;)
	{
		cout << "Enter number to add / press -99 to pause" << endl;
		cin >> addnum;
		if (addnum == -99)
		{
			openfp = filewrite(filep, pause);
			openfs = filewrite(files, solved);
			if (openfp == false || openfs == false)
			{
				cout << "Cannot save game" << endl;
				cout << "Continue game(c) or exit game without saving(e)" << endl;
				cin >> letter;
				if (letter == 'c')
				{
					continue;
				}
				else if (letter == 'e')
				{
					exit(-1);
				}
			}
			else
			{
				for (int i = 0; i < SIZE; i++)
				{
					for (int j = 0; j < SIZE; j++)
					{
						filep << Newsuduko[i][j];
					}
					filep << endl;
				}
				for (int i = 0; i < SIZE; i++)
				{
					for (int j = 0; j < SIZE; j++)
					{
						files << suduko[i][j];
					}
					files << endl;
				}
				cout << "File saved" << endl;
				filep.close();
				files.close();
				exit(-1);
			}
		}
		else if (addnum < 1 || addnum> 9)
		{
			cout << "Enter number between 1 - 9" << endl;
		}
		else
		{
			cout << "Enter row number" << endl;
			cin >> rownum;
			cout << "Enter column number" << endl;
			cin >> colnum;
			if (Newsuduko[rownum][colnum] != 0)
			{
				cout << "This slot is full. Try again" << endl;
			}
			else
			{
				Newsuduko[rownum][colnum] = addnum;
				cout << "Number added" << endl;
				cout << "   ";
				for (int i = 0; i < SIZE; i++)
				{
					cout << i << " ";
				}
				cout << endl << endl;
				for (int i = 0; i < SIZE; i++)
				{
					cout << i << "  ";

					for (int j = 0; j < SIZE; j++)
					{
						if (Newsuduko[i][j] == 0)
						{
							cout << "X ";
						}
						else
						{
							cout << Newsuduko[i][j] << " ";
						}
					}
					cout << endl;
				}
				if (Newsuduko[rownum][colnum] == suduko[rownum][colnum])
				{
					numhs++;
				}
				q++;
			}
		}
	}
	cout << "Score = " << numhs << endl;
	temp = true;
	int j = 0;
	bool unique = true;
	temp = fileread(fileR, highscore);
	int hsarr[5] = { 0 };
	i = 0;
	int min = 0;
	if (temp == true)
	{
		while (fileR >> hsarr[i])
		{
			i++;
		}
		fileR.close();
		if (i > 5)
		{
			while (j < i)
			{
				min = hsarr[j];
				if (hsarr[j] < min)
				{
					min = hsarr[j];
				}
				if (numhs == hsarr[j])
				{
					unique = false;
				}
				j++;
			}
			if (unique == true)
			{
				j = 0;
				while (hsarr[j] != min)
				{
					j++;
				}
				hsarr[j] = numhs;
			}
			fileW.open(highscore, ios::trunc);
			j = 0;
			while (fileW << hsarr[j])
			{
				j++;
			}
			fileW.close();
		}
		else
		{
			j = 0;
			fileW.close();
			temp = filewrite(fileW, highscore);
			while (j < i)
			{
				if (numhs == hsarr[j])
				{
					unique = false;
				}
				j++;
			}
			if (unique == true)
			{
				fileW << numhs;
				fileW.close();
			}

		}
	}
	else
	{
		cout << "Highscore.txt not open" << endl;
	}
}
bool filewrite(ofstream& file, char filename[])
{
	bool flag = true;
	file.open(filename, ios::trunc);
	if (!file.is_open())
	{
		cout << "File not open" << endl;
		flag = false;
		return flag;
	}
}
bool fileread(ifstream& file, char filename[])
{
	bool flag = true;
	file.open(filename);
	if (!file.is_open())
	{
		cout << "File not open" << endl;
		flag = false;
		return flag;
	}
}
void resumegame(char pause[], char solved[], char highscore[])
{
	int row = 0, col = 0, i = 0;
	int num = 1, c = 0, put = 0;
	const int SIZE = 9;
	int suduko[SIZE][SIZE] = { 0 };
	int Newsuduko[SIZE][SIZE] = { 0 };
	bool tempP = true;
	bool tempS = true;
	ifstream fileP;
	ifstream fileS;
	tempP = fileread(fileP, pause);
	tempS = fileread(fileS, solved);
	if (tempP == true && tempS == true)
	{
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				fileS >> suduko[i][j];
				fileP >> Newsuduko[i][j];
			}	
		}
		int run = 0;
		cout << "   ";
		for (int i = 0; i < SIZE; i++)
		{
			cout << i << " ";
		}
		cout << endl << endl;
		for (int i = 0; i < SIZE; i++)
		{
			cout << i << "  ";

			for (int j = 0; j < SIZE; j++)
			{
				if (Newsuduko[i][j] == 0)
				{
					run++;
					cout << "X ";
				}
				else
				{
					cout << Newsuduko[i][j];
				}
			}
			cout << endl;
		}
		////////////////
		ofstream filep;
		ofstream files;
		ofstream fileW;
		ifstream fileR;
		int addnum = 0;
		int rownum = 0;
		int colnum = 0;
		int numhs = 0;
		bool openfp = true;
		bool openfs = true;
		char letter = '\0';
		for (int q = 0; q < run;)
		{
			cout << "Enter number to add / press -99 to pause" << endl;
			cin >> addnum;
			if (addnum == -99)
			{
				openfp = filewrite(filep, pause);
				openfs = filewrite(files, solved);
				if (openfp == false || openfs == false)
				{
					cout << "Cannot save game" << endl;
					cout << "Continue game(c) or exit game without saving(e)" << endl;
					cin >> letter;
					if (letter == 'c')
					{
						continue;
					}
					else if (letter == 'e')
					{
						exit(-1);
					}
				}
				else
				{
					for (int i = 0; i < SIZE; i++)
					{
						for (int j = 0; j < SIZE; j++)
						{
							filep << Newsuduko[i][j];
						}
						filep << endl;
					}
					for (int i = 0; i < SIZE; i++)
					{
						for (int j = 0; j < SIZE; j++)
						{
							files << suduko[i][j];
						}
						files << endl;
					}
					cout << "File saved" << endl;
					filep.close();
					files.close();
					exit(-1);
				}
			}
			else if (addnum < 1 || addnum> 9)
			{
				cout << "Enter number between 1 - 9" << endl;
			}
			else
			{
				cout << "Enter row number" << endl;
				cin >> rownum;
				cout << "Enter column number" << endl;
				cin >> colnum;
				if (Newsuduko[rownum][colnum] != 0)
				{
					cout << "This slot is full. Try again" << endl;
				}
				else
				{
					Newsuduko[rownum][colnum] = addnum;
					cout << "Number added" << endl;
					cout << "   ";
					for (int i = 0; i < SIZE; i++)
					{
						cout << i << " ";
					}
					cout << endl << endl;
					for (int i = 0; i < SIZE; i++)
					{
						cout << i << "  ";
						for (int j = 0; j < SIZE; j++)
						{
							if (Newsuduko[i][j] == 0)
							{
								cout << "X ";
							}
							else
							{
								cout << Newsuduko[i][j] << " ";
							}
						}
						cout << endl;
					}
					if (Newsuduko[rownum][colnum] == suduko[rownum][colnum])
					{
						numhs++;
					}
					q++;
				}
			}
		}
		cout << "Score = " << numhs << endl;
		bool temp = true;
		int j = 0;
		bool unique = true;
		temp = fileread(fileR, highscore);
		int hsarr[5] = { 0 };
		int i = 0;
		int min = 0;
		if (temp == true)
		{
			while (fileR >> hsarr[i])
			{
				i++;
			}
			fileR.close();
			if (i > 5)
			{
				while (j < i)
				{
					min = hsarr[j];
					if (hsarr[j] < min)
					{
						min = hsarr[j];
					}
					if (numhs == hsarr[j])
					{
						unique = false;
					}
					j++;
				}
				if (unique == true)
				{
					j = 0;
					while (hsarr[j] != min)
					{
						j++;
					}
					hsarr[j] = numhs;
				}
				fileW.open(highscore, ios::trunc);
				j = 0;
				while (fileW << hsarr[j])
				{
					j++;
				}
				fileW.close();
			}
			else
			{
				j = 0;
				fileW.close();
				temp = filewrite(fileW, highscore);
				while (j < i)
				{
					if (numhs == hsarr[j])
					{
						unique = false;
					}
					j++;
				}
				if (unique == true)
				{
					fileW << numhs;
					fileW.close();
				}

			}
		}
		else
		{
			cout << "Highscore.txt not open" << endl;
		}
	}


	
}
void displayHS(char filename[])
{
	bool temp = true;
	ifstream file;
	int num = 0;
	temp = fileread(file, filename);
	if (temp == true)
	{
		cout << "High scores" << endl;
		while (file >> num)
		{
			cout << num << endl;
		}
	}
	else
	{
		cout << "High scores cant be displayed." << endl;
	}
}