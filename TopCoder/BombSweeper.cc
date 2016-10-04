#include <iostream>
#include <vector>

using namespace std;

class BombSweeper {
public:
  double winPercentage(vector<string> board) {
    int win = 0;
    int lose = 0;
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[i].size(); ++j) {
        if (board[i][j] == 'B') lose++;
        else win += isWin(board, i, j);
      }
    }
    return (win * 100.0) / (win + lose);
  }

private:
  bool isWin(vector<string>& board, int y, int x) {
    int startY = (y - 1 >= 0) ? y - 1 : 0;
    int endY = (y + 1 < board.size()) ? y + 1 : board.size() - 1;
    int startX = (x - 1 >= 0) ? x - 1 : 0;
    int endX = (x + 1 < board[0].size()) ? x + 1 : board[0].size() - 1;

    for (int i = startY; i <= endY; ++i) {
      for (int j = startX; j <= endX; ++j)
        if (board[i][j] == 'B') return false;
    }
    return true;
  }
};