#include<iostream>
#include<fstream>
#include<string>
#include<ctime>

using namespace std;

class getname
{
public: 
	string name;
	char filename[30];

	getname(void)
	{
		int count = 0;
		ifstream inf;
		inf.open("names.txt");
		while (inf)
		{
			inf.getline(filename,sizeof(filename));
			count++;
		}
		int randval = rand() % count;
		inf.close();
		inf.open("names.txt");
		for (int i = 0; i < randval-1; i++)
		{
			inf.getline(filename, sizeof(filename));
		}
		getline(inf, name);
	}

};
class setup:getname
{
public:
	char ch;
	string boll = "BOLLYWOOD";
	string correctgame;
	int size = name.size(), pos;

	setup(void)
	{
		for (int i = 0; i < size; i++)
		{
			if (name[i] == ' ')
				correctgame.push_back(' ');
			else if(rand()%3==0)
				correctgame.push_back(name[i]);
			else
				correctgame.push_back('_');
		}
		cout << "\n\n\tSTARTING GAME..... ";
		int i;
		for (i=0;i<9;)
		{
			cout << "\n" << boll<<"\n"<<correctgame;
			cout << "\nEnter the character: ";
			cin >> ch;
			pos = name.find(ch);
			x:if (pos != string::npos)
			{
				if (correctgame[pos] == '_')
				{
					cout << "correct value!";
				correctgame[pos] = name[pos];
				}
				else
				{
					pos = name.find(ch, pos + 1);
					goto x;
				}
			}
			else
			{
				cout << "\nWrong value";
				boll[i] = '-';
				i++;
			}
			if (correctgame.find('_') == string::npos)
			{
				cout << "\nCongrats you won the game";
				break;
			}
		}
		if (i == 9)
		{
			cout << "\nBetter luck next time!";
		}


	}
};

int main()
{
	srand(time(0));
	char yn='y';
	cout << "Remember to edit the 'names.txt' file to add or delete names used in this game :)";
	while (yn == 'y')
	{
		setup s;
		cout << "\nDo you wish to continue? y/n : ";
		cin >> yn;
	}
	return 0;
}
