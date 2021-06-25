#include<iostream>
#include<vector>
using namespace std;
//Written by Kevin Nguyen


bool ticTacToe(vector<vector<string>>& a, int player);
void DisplayBoard(vector<vector<string>>& a);
bool checkBoard(vector<vector<string>>& a, int player,int input);

int main()
{
	int turns = 0;
	int player = 1;
	bool winner = false;
	
	//fill up the 2d vector with "#"
	vector<vector <string>> a;
	for (int i = 0; i < 3; i++)
	{
		vector<string>b;
		for (int c = 0; c < 3; c++)
		{
			b.push_back("#");
		}
		a.push_back(b);
	}
	//checks if all 9 turns has passed 
	while (turns <9)
	{
		//if winner is found exit the loop
		winner = ticTacToe(a, player);
		if (winner == true)
		{
			break;
		}
		//else continue
		else
		{
			player = 2;
			turns++;
			winner = ticTacToe(a, player);
			player = 1;
			turns++;
		}

		
	}
	if (turns == 9 && winner == false)
	{
		cout << "It is a tie! " << endl;
	}
}

bool ticTacToe(vector<vector<string>>& a, int player)
{
	bool winner = false;
	int input;
	int row, col;
	string turn = "X";
	if (player == 1)
	{
		DisplayBoard(a);
		cout << endl;
		cout << "Player " << player << " Please enter your move ";
		cin >> input;
		//based on the input we preform "/" to get the row location example 1/3 = 0
		row = input / 3;
		//based on the input we preform the "%" to get the col location example 2%3 = 2
		col = input % 3;
		//checks if input has been taken
		if ((a[row][col] == "X") || (a[row][col] == "O"))
		{
			cout << "This spot is already taken " << endl;
		}
		else
		{
			a[row][col] = "X";
			winner = checkBoard(a, player,input);
		}
		if (winner == true)
		{

			return winner;
		}
		
	}
	if (player == 2)
	{
		DisplayBoard(a);
		cout << endl;
		cout << "Player " << player << " Please enter your move ";
		cin >> input;
		row = input / 3;
		col = input % 3;
		if ((a[row][col] == "X") || (a[row][col] == "O"))
		{
			cout << "This spot is already taken " << endl;
			ticTacToe(a, player);
		}
		else
		{
			a[row][col] = "O";
			checkBoard(a, player, input);
		}
		
	}
	if (winner == true)
	{
		return winner;
	}

}

void DisplayBoard(vector<vector<string>>& a)
{
	int num = 0;
	for (int i = 0; i < 3; i++)
	{
		vector<string>b;
		cout << "[ ";
		for (int c = 0; c < 3; c++)
		{
			cout << a[i][c] << " ";
		}
		cout << "]" << endl;
	}
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		vector<string>b;
		cout << "[ ";
		for (int c = 0; c < 3; c++)
		{
			cout << num << " ";
			num++;

		}
		cout << "]" << endl;

	}
}
bool checkBoard(vector<vector<string>>& a, int player, int input)
{
	bool winner = false;
	int row = input / 3;
	int col = input % 3;
	if (player == 1)
	{
		//check all the elements in the row
		if (a[row][0] == "X" && a[row][1] == "X" && a[row][2] == "X")
		{
			cout << "Player 1 wins " << endl;
			DisplayBoard(a);
			winner = true;
		}
		//check all the elements in the col
		else if (a[0][col] == "X" && a[1][col] == "X" && a[2][col] == "X")
		{
			cout << "Player 1 wins " << endl;
			DisplayBoard(a);
			winner = true;
		}

		//check all the elements left diagonally 
		else if (a[0][0] == "X" && a[1][1] == "X" && a[2][2] == "X")
		{
			cout << "Player 1 wins " << endl;
			DisplayBoard(a);
			winner = true;
		}
		//check all the elements right diagonally 
		else if (a[0][2] == "X" && a[1][1] == "X" && a[2][0] == "X")
		{
			cout << "Player 1 wins " << endl;
			DisplayBoard(a);
			winner = true;
		}

	}

	if (player == 2)
	{
		//check all the elements in the row
		if (a[row][0] == "O" && a[row][1] == "O" && a[row][2] == "O")
		{
			cout << "Player 2 wins " << endl;
			DisplayBoard(a);
			winner = true;
		}
		//check all the elements in the col
		else if (a[0][col] == "O" && a[1][col] == "O" && a[2][col] == "O")
		{
			cout << "Player 2 wins " << endl;
			DisplayBoard(a);
			winner = true;
		}

		//check all the elements left diagonally 
		else if (a[0][0] == "O" && a[1][1] == "O" && a[2][2] == "O")
		{
			cout << "Player 2 wins " << endl;
			DisplayBoard(a);
			winner = true;
		}
		//check all the elements right diagonally 
		else if (a[0][2] == "O" && a[1][1] == "O" && a[2][0] == "O")
		{
			cout << "Player 2 wins " << endl;
			DisplayBoard(a);
			winner = true;
		}

	}
	//return true once winner is found
	return winner;
	
}