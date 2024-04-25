#ifndef FUNKCJE2_H
#define FUNKCJE2_H

void initializeBoard(char board[3][3]);
void getPlayerMove(char player, char board[3][3], int &row, int &col);
bool validateMove(int row, int col, char board[3][3]);
void makeMove(char player, char board[3][3], int row, int col);
void switchPlayer(char &player);;
bool checkDraw0(int turn, char board[3][3]);
bool checkDraw1(int turn, char board[3][3]);
void drawBoard(char board[3][3]);
bool checkWinPionPoziom(char board[3][3], char player);
bool checkWinPrzekatna(char board[3][3], char player);
bool hasEmptyCells(char board[3][3]);
int scoreBoard(char board[3][3]);
int minimax(char board[3][3], int depth, bool isMaximizing);
void computerMove(char board[3][3]);

#endif