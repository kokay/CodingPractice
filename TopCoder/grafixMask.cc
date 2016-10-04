#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;

class grafixMask {
public:
  vector<int> sortedAreas(vector<string> rectangles) {
    bool checked[400][600];
    int row1, col1, row2, col2;
    memset(checked, false, sizeof(checked));
    for (int i = 0; i < rectangles.size(); ++i) {
      istringstream ss(rectangles[i]);
      ss >> row1 >> col1 >> row2 >> col2;
      for (int row = row1; row <= row2; ++row) {
        for (int col = col1; col <= col2; ++col)
          checked[row][col] = true;
      }
    }

    vector<int> areas;
    for (int row = 0; row < 400; ++row) {
      for (int col = 0; col < 600; ++col) {
        if (!checked[row][col])
          areas.push_back(bfs(checked, row, col));
      }
    }
    sort(areas.begin(), areas.end());
    return areas;
  }

private:
  int bfs(bool checked[400][600], int row, int col) {
    int count = 1;
    checked[row][col] = true;
    queue<pair<int, int>> q;
    q.push({ row, col });

    pair<int, int> pos;
    while (!q.empty()) {
      pos = q.front();
      q.pop();

      if (pos.first - 1 >= 0 && !checked[pos.first - 1][pos.second]) {
        q.push({ pos.first - 1, pos.second });
        checked[pos.first - 1][pos.second] = true;
        ++count;
      }
      if (pos.second - 1 >= 0 && !checked[pos.first][pos.second - 1]) {
        q.push({ pos.first, pos.second - 1 });
        checked[pos.first][pos.second - 1] = true;
        ++count;
      }
      if (pos.first + 1 < 400 && !checked[pos.first + 1][pos.second]) {
        q.push({ pos.first + 1, pos.second });
        checked[pos.first + 1][pos.second] = true;
        ++count;
      }
      if (pos.second + 1 < 600 && !checked[pos.first][pos.second + 1]) {
        q.push({ pos.first, pos.second + 1 });
        checked[pos.first][pos.second + 1] = true;
        ++count;
      }
    }
    return count;
  }
};