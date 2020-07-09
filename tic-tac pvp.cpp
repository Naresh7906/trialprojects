#include<iostream>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

using namespace std;

void ClearScreen()
{
	int n;
	for (n = 0; n < 10; n++)
		printf("\n\n\n\n\n\n\n\n\n\n");
}

class tic_tac {

	char valtable[9];

public:
	tic_tac() {
		for (int i = 0; i < 9; i++)
			valtable[i] = ' ';
		play();
	}
	void disp();
	void play();
	int win();

};

void tic_tac::disp()
{
	ClearScreen();
	printf("\n\n\t%c\t|\t%c\t|\t%c\t\n\n", valtable[0], valtable[1], valtable[2]);
	cout << "    __________________________________________\n";
	printf("\n\n\t%c\t|\t%c\t|\t%c\t\n\n", valtable[3], valtable[4], valtable[5]);
	cout << "    __________________________________________\n";
	printf("\n\n\t%c\t|\t%c\t|\t%c\t\n\n", valtable[6], valtable[7], valtable[8]);
}

void tic_tac::play() {
	
	char p1, p2;
	int choice,i=0,entry;

	ClearScreen();
	cout << "\nPlayer 1 goes first!\nSelect a character to represent player 1:\n1. X\n2. O\nyour choice : ";
	cin >> choice;

	p1 = (choice == 1) ? 'X' : 'O';
	p2 = (p1 == 'X') ? 'O' : 'X';

	while (i < 9)
	{

		disp();

		x: cout << "\nEneter input of player " << i % 2 + 1 << " ( 1 to 9 ) : ";
		cin >> entry;
		entry -= 1;
		if (valtable[entry] != ' ' || entry > 8 || entry < 0)
		{
			cout << "\nInvalid input!";
			goto x;
		}
		else
			valtable[entry] = (i % 2 == 0) ? p1 : p2;

		if (win() == 1)
		{
			disp();
			cout << "\nCongrats player " << i % 2 + 1 << " won!";
			break;
		}
		
		i++;
	}

	if (i == 9) {
		disp();
		cout << "\nIts a draw!";
	}

}

int tic_tac::win() {
	if (valtable[0] == valtable[1] && valtable[1] == valtable[2] && valtable[0] != ' ')
		return 1;
	if (valtable[3] == valtable[4] && valtable[4] == valtable[5] && valtable[3] != ' ')
		return 1;
	if (valtable[6] == valtable[7] && valtable[7] == valtable[8] && valtable[6] != ' ')
		return 1;
	if (valtable[0] == valtable[3] && valtable[3] == valtable[6] && valtable[0] != ' ')
		return 1;
	if (valtable[1] == valtable[4] && valtable[4] == valtable[7] && valtable[1] != ' ')
		return 1;
	if (valtable[2] == valtable[5] && valtable[5] == valtable[8] && valtable[2] != ' ')
		return 1;
	if (valtable[0] == valtable[4] && valtable[4] == valtable[8] && valtable[0] != ' ')
		return 1;
	if (valtable[2] == valtable[4] && valtable[4] == valtable[6] && valtable[2] != ' ')
		return 1;

	return 0;
}

int main()
{
	char choice = 'y';
	
	do
	{
		tic_tac ob;
		cout << "\nDo you wish to play another round? y/n : ";
		cin >> choice;
	} while (choice == 'y');
	return 0;
}