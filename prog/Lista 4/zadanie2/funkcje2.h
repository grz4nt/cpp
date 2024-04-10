#ifndef FUNKCJE2_H
#define FUNKCJE2_H

void drawBoard(char board[3][3]);
bool checkWin(char board[3][3], char player);
bool hasEmptyCells(char board[3][3]);
int scoreBoard(char board[3][3]);
int minimax(char board[3][3], int depth, bool isMaximizing);
void computerMove(char board[3][3]);

#endif