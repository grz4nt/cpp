#include <iostream>
using namespace std;

void drawBoard(char board[3][3])
{
	cout << "\n   1   2   3\n";
	for (int i = 0; i < 3; i++)
	{
		cout << i + 1 << " ";
		for (int j = 0; j < 3; j++)
		{
			if (j < 2)
			{
				cout << " " << board[i][j] << " |";
			}
			else
			{
				cout << " " << board[i][j];
			}
		}
		cout << "\n";
		if (i < 2)
		{
			cout << "  -----------\n";
		}
	}
}

bool checkWin(char board[3][3], char player)
{
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
			return true;
		if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
			return true;
	}
	if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
		return true;
	if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
		return true;
	return false;
}

int main()
{
	char board[3][3] = {{' ', ' ', ' '},
						{' ', ' ', ' '},
						{' ', ' ', ' '}};
	char player = 'X';
	int row, col;
	int turn;

	for (turn = 0; turn < 9; turn++)
	{
		drawBoard(board);

		while (true)
		{
			cout << "Gracz " << player << ", wpisz wiersz (1-3): ";
			cin >> row;
			cout << "Gracz " << player << ", wpisz kolumne (1-3): ";
			cin >> col;
			row--;
			col--;

			if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ')
			{
				cout << "Nieprawidlowy ruch. Wprowadz ponownie\n";
			}
			else
			{
				break;
			}
		}

		board[row][col] = player;

		if (checkWin(board, player))
		{
			cout << "Gracz " << player << " wygrywa!\n";
			break;
		}

		player = (player == 'X') ? 'O' : 'X';
	}
	drawBoard(board);

	if (turn == 9 && !checkWin(board, 'X') && !checkWin(board, 'O'))
	{
		cout << "Remis!\n";
	}

	return 0;
}
