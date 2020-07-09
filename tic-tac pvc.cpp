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
	int depen[2][8];

public:
	tic_tac() {
		for (int i = 0; i < 9; i++)
			valtable[i] = ' ';
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 8; j++)
				depen[i][j] = 0;
		play();
	}
	void disp();
	void play();
	void comp(char p2,int i);
	void updateval(int entry, int who);
	int win();

};

void tic_tac::updateval(int entry, int who) {
	if (entry == 0)
	{
		depen[0][0]++;
		depen[0][3]++;
		depen[0][6]++;
	}
	else if (entry == 1)
	{
		depen[0][0]++;
		depen[0][4]++;
	}
	else if (entry == 2)
	{
		depen[0][0]++;
		depen[0][5]++;
		depen[0][7]++;
	}
	else if (entry == 3)
	{
		depen[0][1]++;
		depen[0][3]++;
	}
	else if (entry == 4)
	{
		depen[0][1]++;
		depen[0][4]++;
		depen[0][6]++;
		depen[0][7]++;
	}
	else if (entry == 5)
	{
		depen[0][1]++;
		depen[0][5]++;
	}
	else if (entry == 6)
	{
		depen[0][2]++;
		depen[0][3]++;
		depen[0][7]++;
	}
	else if (entry == 7)
	{
		depen[0][2]++;
		depen[0][4]++;
	}
	else if (entry == 8)
	{
		depen[0][2]++;
		depen[0][5]++;
		depen[0][6]++;
	}

	if (who == 0)
	{
		if (entry == 0)
		{
			depen[1][0]++;
			depen[1][3]++;
			depen[1][6]++;
		}
		else if (entry == 1)
		{
			depen[1][0]++;
			depen[1][4]++;
		}
		else if (entry == 2)
		{
			depen[1][0]++;
			depen[1][5]++;
			depen[1][7]++;
		}
		else if (entry == 3)
		{
			depen[1][1]++;
			depen[1][3]++;
		}
		else if (entry == 4)
		{
			depen[1][1]++;
			depen[1][4]++;
			depen[1][6]++;
			depen[1][7]++;
		}
		else if (entry == 5)
		{
			depen[1][1]++;
			depen[1][5]++;
		}
		else if (entry == 6)
		{
			depen[1][2]++;
			depen[1][3]++;
			depen[1][7]++;
		}
		else if (entry == 7)
		{
			depen[1][2]++;
			depen[1][4]++;
		}
		else if (entry == 8)
		{
			depen[1][2]++;
			depen[1][5]++;
			depen[1][6]++;
		}
	}

}

void tic_tac::disp()
{
	ClearScreen();
	printf("\n\n\t%c\t|\t%c\t|\t%c\t\n\n", valtable[0], valtable[1], valtable[2]);
	cout << "    __________________________________________\n";
	printf("\n\n\t%c\t|\t%c\t|\t%c\t\n\n", valtable[3], valtable[4], valtable[5]);
	cout << "    __________________________________________\n";
	printf("\n\n\t%c\t|\t%c\t|\t%c\t\n\n", valtable[6], valtable[7], valtable[8]);
}

void tic_tac::comp(char p2,int i) {
	if (i == 0)
	{
		int turn;
		while (true)
		{
			turn = rand() % 10;
			if (turn < 9 && turn >= 0)
				break;
		}
		valtable[turn] = p2;
		updateval(turn, 0);
	}
	else
	{
		int turn = -1, count = 0, subcount = 0;
		for (int i = 0; i < 8; i++)
		{
			subcount = depen[1][i];
			if (count <= subcount && depen[0][i]<3)
			{
				count = subcount;
				turn = i;
			}
		}
	
		if (turn == 0)
		{
			if (valtable[0] == ' ')
				valtable[0] = p2;
			else if (valtable[1] == ' ')
				valtable[1] = p2;
			else if (valtable[2] == ' ')
				valtable[2] = p2;
			updateval(turn, 0);
		}
		if (turn == 1)
		{
			if (valtable[3] == ' ')
				valtable[3] = p2;
			else if (valtable[4] == ' ')
				valtable[4] = p2;
			else if (valtable[5] == ' ')
				valtable[5] = p2;
			updateval(turn, 0);
		}
		if (turn == 2)
		{
			if (valtable[6] == ' ')
				valtable[6] = p2;
			else if (valtable[7] == ' ')
				valtable[7] = p2;
			else if (valtable[8] == ' ')
				valtable[8] = p2;
			updateval(turn, 0);
		}
		if (turn == 3)
		{
			if (valtable[0] == ' ')
				valtable[0] = p2;
			else if (valtable[3] == ' ')
				valtable[3] = p2;
			else if (valtable[6] == ' ')
				valtable[6] = p2;
			updateval(turn, 0);
		}
		if (turn == 4)
		{
			if (valtable[1] == ' ')
				valtable[1] = p2;
			else if (valtable[4] == ' ')
				valtable[4] = p2;
			else if (valtable[7] == ' ')
				valtable[7] = p2;
			updateval(turn, 0);
		}
		if (turn == 5)
		{
			if (valtable[2] == ' ')
				valtable[2] = p2;
			else if (valtable[5] == ' ')
				valtable[5] = p2;
			else if (valtable[8] == ' ')
				valtable[8] = p2;
			updateval(turn, 0);
		}
		if (turn == 6)
		{
			if (valtable[0] == ' ')
				valtable[0] = p2;
			else if (valtable[4] == ' ')
				valtable[4] = p2;
			else if (valtable[8] == ' ')
				valtable[8] = p2;
			updateval(turn, 0);
		}
		if (turn == 7)
		{
			if (valtable[2] == ' ')
				valtable[2] = p2;
			else if (valtable[4] == ' ')
				valtable[4] = p2;
			else if (valtable[6] == ' ')
				valtable[6] = p2;
			updateval(turn, 0);
		}


	}

}

void tic_tac::play() {

	char p1, p2,ct;
	int choice, i = 0, entry;

	ClearScreen();
	cout << "\nSelect a character to represent player 1:\n1. X\n2. O\nyour choice : ";
	cin >> choice;

	p1 = (choice == 1) ? 'X' : 'O';
	p2 = (p1 == 'X') ? 'O' : 'X';

	ct = rand() % 2;

	while (i < 9)
	{

		disp();
		if (ct == 0)
			cout << "\nThe computer goes first";
		else cout << "\nThe player goes first";

		if (i % 2 == ct)
			comp(p2,i);

		else
		{

		x: cout << "\nEneter input of player ( 1 to 9 ) : ";
			cin >> entry;
			entry -= 1;
			if (valtable[entry] != ' ' || entry > 8 || entry < 0)
			{
				cout << "\nInvalid input!";
				goto x;
			}
			else
			{
				valtable[entry] = p1;
				updateval(entry,1);
			}

		}
		if (win() == 1)
		{
			if (i % 2 == ct)
			{
				disp();
				cout << "\nComputer won!, Better luck next time!";
			}
			else
			{
				disp();
				cout << "\nCongrats the player won!";
			}
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
	srand(time(0));
	do
	{
		tic_tac ob;
		cout << "\nDo you wish to play another round? y/n : ";
		cin >> choice;
	} while (choice == 'y');
	return 0;
}