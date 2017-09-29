/*Tic Tac Toe by Nicholas Rich
date
Lets the user play tic tac toe
*/
#include <iostream>
#include <cstring>

using namespace std;
void printBoard();
bool checkWin(char player);
bool checkTie();
struct utpb {
  char b[3][4];
}board;
int main() {
  char str[3];
  board.b[0][0] = 'a';
  board.b[1][0] = 'b';
  board.b[2][0] = 'c';
  bool stillPlaying = true;
  bool xTurn = true;
  char playagain;
  int xWins = 0;
  int oWins = 0;
  for (int r = 0; r < 3; r++) {
    for (int c = 1; c <4; c++) {
      board.b[r][c] = ' ';
    }
  }
  while (stillPlaying == true) {
    while ((checkWin('x') == false) && (checkWin('o') == false) && (checkTie() == false)) {
      //while check wins and ties
      printBoard();
      cin.get(str,3);
      cin.get();
      int r = ((int)str[0]) - 97;
      int c = ((int)str[1]) - 48;
      if ((r < 0) || (r > 3) || (c < 1) || (c > 4)) {
	cout << "Input a lower case letter followed by a number" << endl;
      }
      else {
	if (xTurn == true) {
	  if (board.b[r][c] != 'o') {
	    board.b[r][c] = 'x';
	    xTurn = false;
	  }
	}
	else if (xTurn == false) {
	  if (board.b[r][c] != 'x') {
	    board.b[r][c] = 'o';
	    xTurn = true;
	  }
	}
	if (xTurn == true) {
	  cout << "x turn";
	}
	else {
	  cout << "o turn";
	}
	cout << endl;
      }
    }
    if (checkWin('x') == true) {
      xWins++;
    }
    if (checkWin('o') == true) {
      oWins++; 
    }
    cout << "X has:" << xWins << " wins" << endl;
    cout << "O has:" << oWins << " wins" << endl;
    cout << "Play again?" << endl;
    cin >> playagain;
    cin.get();
    if (playagain == 'y') {
      for (int row = 0; row < 3; row++) {
	for (int col = 1; col < 4; col++) {
	  board.b[row][col] = ' ';
	  xTurn = true;
	}
      }
    }
    else {
      stillPlaying = false;
    }
  }
  return 0;
}

void printBoard() {
  cout << " \t1\t2\t3" << endl;
  for (int row = 0; row < 3; row++) {
    for (int column = 0; column < 4; column++) {
      cout << board.b[row][column] << "\t";
    }
    cout << endl;
  }
}
bool checkWin(char player) {
  if ((board.b[0][1] == player) && (board.b[0][2] == player) && (board.b[0][3] == player)) {
    return true;
  }
  if ((board.b[1][1] == player) && (board.b[1][2] == player) && (board.b[1][3] == player)) {
    return true;
  }
  if ((board.b[2][1] == player) && (board.b[2][2] == player) && (board.b[2][3] == player)) {
    return true;
  }
  if ((board.b[0][1] == player) && (board.b[1][1] == player) && (board.b[2][1] == player)) {
    return true;
  }
  if ((board.b[0][2] == player) && (board.b[1][2] == player) && (board.b[2][2] == player)) {
    return true;
  }
  if ((board.b[0][3] == player) && (board.b[1][3] == player) && (board.b[2][3] == player)) {
    return true;
  }
  if ((board.b[0][1] == player) && (board.b[1][2] == player) && (board.b[2][3] == player)) {
    return true;
  }
  if ((board.b[0][3] == player) && (board.b[1][2] == player) && (board.b[2][1] == player)) {
    return true;
  }
  return false;
}
bool checkTie() {
  for (int row = 0; row < 3; row++) {
    for (int col = 1; col < 4; col++) {
      if (board.b[row][col] == ' ') {
	return false;
      }
    }
  }
    return true;
}
