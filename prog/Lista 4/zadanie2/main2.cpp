// main2.cpp
#include <iostream>
#include "funkcje2.h"
using namespace std;

int main()
{
	char board[3][3];
	initializeBoard(board);

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
			getPlayerMove(player, board, row, col);
			makeMove(player, board, row, col);
		} else {
			computerMove(board);
		}

		if (checkWin(board, player))
		{
			cout << "Gracz " << player << " wygrywa!\n";
			break;
		}

		switchPlayer(player);
	}
	drawBoard(board);

	checkDraw(turn, board);

	return 0;
}