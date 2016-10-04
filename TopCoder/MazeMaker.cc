#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class MazeMaker {
public:
  int longestPath(vector<string> maze, int startRow, int startCol, vector<int> moveRow, vector<int> moveCol) {
    return bfs(maze, startRow, startCol, moveRow, moveCol);
  }

private:
  int bfs(vector<string> maze, int startRow, int startCol, vector<int> moveRow, vector<int> moveCol) {
    vector<vector<int>> memo(maze.size(), vector<int>(maze[0].size(), -1));
    for (int i = 0; i < maze.size(); ++i)
      for (int j = 0; j < maze[i].size(); ++j)
        if (maze[i][j] == 'X') memo[i][j] = 1000;
    memo[startRow][startCol] = 0;
    queue<pair<int, int>> q;
    q.push({ startRow, startCol });
    while (!q.empty()) {
      pair<int, int> v = q.front(); q.pop();
      for (int i = 0; i < moveRow.size(); ++i) {
        int newRow = v.first + moveRow[i];
        int newCol = v.second + moveCol[i];
        if (newRow >= 0 && newRow < maze.size() && newCol >= 0 && newCol < maze[newRow].size() &&
          memo[newRow][newCol] == -1) {
          memo[newRow][newCol] = memo[v.first][v.second] + 1;
          q.push({ newRow, newCol });
        }
      }
    }

    int len = 0;
    for (int i = 0; i < maze.size(); ++i) {
      for (int j = 0; j < maze[i].size(); ++j) {
        if (memo[i][j] == 1000) continue;
        if (memo[i][j] == -1) return -1;
        len = max(len, memo[i][j]);
      }
    }
    return len;
  }
};