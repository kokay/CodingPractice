#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

class XMarksTheSpot {
public:
  int countArea(vector<string> board) {
    vector<pair<int, int>> v;
    int top = board.size() - 1, bottom = 0, left = board[0].size() - 1, right = 0;
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[i].size(); ++j) {
        if (board[i][j] == '?') v.push_back({ i, j });
        if (board[i][j] == 'O') {
          top = min(top, i);
          bottom = max(bottom, i);
          left = min(left, j);
          right = max(right, j);
        }
      }
    }
    return tryAll(v, 0, top, bottom, left, right);
  }

  int tryAll(vector<pair<int, int>>& v, int idx, int top, int bottom, int left, int right) {
    if (idx >= v.size())
      return (bottom - top + 1) * (right - left + 1);

    int total = tryAll(v, idx + 1, top, bottom, left, right);
    int newTop = min(top, v[idx].first);
    int newBottom = max(bottom, v[idx].first);
    int newLeft = min(left, v[idx].second);
    int newRight = max(right, v[idx].second);
    total += tryAll(v, idx + 1, newTop, newBottom, newLeft, newRight);
    return total;
  }
};