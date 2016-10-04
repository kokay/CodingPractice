#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class CollectingRiders {
public:
  const vector<int> addX{ 1, 1, 2, 2,-1,-1,-2,-2 };
  const vector<int> addY{ 2,-2, 1,-1, 2,-2, 1,-1 };
  const int MAX = 10000000;

  int minimalMoves(vector<string> board) {
    vector<vector<vector<int>>> grids;
    for (int i = 0; i < board.size(); ++i)
    for (int j = 0; j < board[i].size(); ++j)
      if (board[i][j] != '.')
        grids.push_back(bfs(board, i, j));
    
    int best = MAX;
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[i].size(); ++j) {
        int local = 0;
        for (vector<vector<int>>& grid : grids)
          local += grid[i][j];

        best = min(best, local);
      }
    }

    if (best == MAX) return -1;
    return best;
  }

  vector<vector<int>> bfs(vector<string>& board, int y, int x) {
    vector<vector<int>> distance(board.size(), vector<int>(board[0].size(), MAX));
    queue<int> q;
    q.push(y), q.push(x), q.push(0);
    distance[y][x] = 0;

    while (!q.empty()) {
      int pY = q.front(); q.pop();
      int pX = q.front(); q.pop();
      int newStep = q.front() + 1; q.pop();
      for (int i = 0; i < addX.size(); ++i) {
        int newY = pY + addY[i];
        int newX = pX + addX[i];
        if (newY < board.size() && newY >= 0 && newX < board[newY].size() && newX >= 0 &&
          distance[newY][newX] == MAX) {

          distance[newY][newX] = (int) ceil((double) newStep / (board[y][x] - '0'));
          q.push(newY), q.push(newX), q.push(newStep);
        }
      }
    }
    return distance;
  }
};

//int main() {
//  CollectingRiders c;
//  cout << c.minimalMoves(
//
//  { ".1....1." }
//  ) << endl;
//}