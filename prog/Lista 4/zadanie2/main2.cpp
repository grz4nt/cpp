#include <iostream>
#include "funkcje2.h"
using namespace std;

int main()
{
	char board[3][3] = {{' ', ' ', ' '},
						{' ', ' ', ' '},
						{' ', ' ', ' '}};
	char player = 'X';
	int row, col;
	int turn;

	bool playWithComputer;
	cout << "Czy chcesz grac z komputerem? (1 - tak, 0 - nie): ";
	cin >> playWithComputer;

	for (turn = 0; turn < 9; turn++)
	{
		drawBoard(board);

		if (!playWithComputer || player == 'X') {
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
		} else {
			computerMove(board);
		}

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