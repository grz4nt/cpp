// modyfikacja: czy normalna gra czy tylko pionowe/poziome wygrywaja

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
	bool przekatna;
	cout << "Czy chcesz grac z komputerem? (1 - tak, 0 - nie): ";
	cin >> playWithComputer;
	cout << "Czy chcesz, aby mozna bylo wygrac po przekatnej? (1 - tak, 0 - nie): ";
	cin >> przekatna;

	for (turn = 0; turn < 9; turn++)
	{
		drawBoard(board);

		if (!playWithComputer || player == 'X') {
			getPlayerMove(player, board, row, col);
			makeMove(player, board, row, col);
		} else {
			computerMove(board);
		}

		if (!przekatna) {
			if (checkWinPionPoziom(board, player))
			{
				cout << "Gracz " << player << " wygrywa!\n";
				break;
			}
		}
		else {
			if (checkWinPrzekatna(board, player))
			{
				cout << "Gracz " << player << " wygrywa!\n";
				break;
			}
		}


		switchPlayer(player);
	}
	drawBoard(board);
	if (!przekatna) checkDraw0(turn, board);
	else checkDraw1(turn, board);

	return 0;
}