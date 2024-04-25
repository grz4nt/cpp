#include "funkcje2.h"
#include <iostream>
using namespace std;

void initializeBoard(char board[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void getPlayerMove(char player, char board[3][3], int &row, int &col) {
    while (true)
    {
        cout << "Gracz " << player << ", wpisz wiersz (1-3): ";
        cin >> row;
        cout << "Gracz " << player << ", wpisz kolumne (1-3): ";
        cin >> col;
        row--;
        col--;

        if (validateMove(row, col, board)) {
            break;
        } else {
            cout << "Nieprawidlowy ruch. Wprowadz ponownie\n";
        }
    }
}

bool validateMove(int row, int col, char board[3][3]) {
    if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
        return false;
    } else {
        return true;
    }
}

void makeMove(char player, char board[3][3], int row, int col) {
    board[row][col] = player;
}

void switchPlayer(char &player) {
    player = (player == 'X') ? 'O' : 'X';
}

bool checkDraw0(int turn, char board[3][3]) {
    if (turn == 9 && !checkWinPionPoziom(board, 'X') && !checkWinPionPoziom(board, 'O')) {
        cout << "Remis!\n";
        return true;
    }
    return false;
}

bool checkDraw1(int turn, char board[3][3]) {
    if (turn == 9 && !checkWinPionPoziom(board, 'X') && !checkWinPionPoziom(board, 'O') && !checkWinPrzekatna(board, 'X') && !checkWinPrzekatna(board, 'O')) {
        cout << "Remis!\n";
        return true;
    }
    return false;
}

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

bool checkWinPionPoziom(char board[3][3], char player)
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    return false;
}

bool checkWinPrzekatna(char board[3][3], char player)
{
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}

bool hasEmptyCells(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return true;
            }
        }
    }
    return false;
}

int scoreBoard(char board[3][3]) {
    if (checkWinPionPoziom(board, 'X')) return -1;
    if (checkWinPrzekatna(board, 'X')) return -1;
    if (checkWinPionPoziom(board, 'O')) return 1;
    if (checkWinPrzekatna(board, 'O')) return 1;
    return 0;
}

int minimax(char board[3][3], int depth, bool isMaximizing) {
    int score = scoreBoard(board);

    if (score == 1) return score;
    if (score == -1) return score;
    if (!hasEmptyCells(board)) return 0;

    if (isMaximizing) {
        int bestScore = -1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'O';
                    int score = minimax(board, depth + 1, false);
                    board[i][j] = ' ';
                    bestScore = max(score, bestScore);
                }
            }
        }
        return bestScore;
    } else {
        int bestScore = 1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'X';
                    int score = minimax(board, depth + 1, true);
                    board[i][j] = ' ';
                    bestScore = min(score, bestScore);
                }
            }
        }
        return bestScore;
    }
}

void computerMove(char board[3][3]) {
    int bestScore = -1000;
    int move[2] = {-1, -1};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'O';
                int score = minimax(board, 0, false);
                board[i][j] = ' ';
                if (score > bestScore) {
                    bestScore = score;
                    move[0] = i;
                    move[1] = j;
                }
            }
        }
    }
    board[move[0]][move[1]] = 'O';
}