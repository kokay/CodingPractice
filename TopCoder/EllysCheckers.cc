#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

map<string, int> memo;

class EllysCheckers {
public:
  string getWinner(string board) {
    board[board.size() - 1] = '.';
    int bestCount = solve(board);
    return bestCount ? "YES" : "NO";
  }

private:
  int solve(string& theBoard) {
    if (memo.find(theBoard) != memo.end()) return memo[theBoard];

    int bestStep = 0;
    for (int i = 0; i < theBoard.size() - 1; ++i) {
      if (theBoard[i] == '.') continue;

      if (theBoard[i + 1] == '.') {
        string board = theBoard; board[i] = '.';
        if (i + 1 < board.size() - 1) board[i + 1] = 'o';
        if (!solve(board)) bestStep = 1;
      }
      else if (i + 3 < theBoard.size() - 1 && theBoard[i + 1] == 'o' && theBoard[i + 2] == 'o' && theBoard[i + 3] == '.') {
        string board = theBoard; board[i] = '.';
        if (i + 3 < board.size() - 1) board[i + 3] = 'o';
        if (!solve(board)) bestStep = 1;
      }
    }
    memo[theBoard] = bestStep;
    return memo[theBoard];
  }
};