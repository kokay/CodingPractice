#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

class SortingGame {
public:
  int fewestMoves(vector<int> board, int k) {
    set<vector<int>> processed;
    processed.insert(board);
    queue<pair<vector<int>, int>> q;
    q.push({ board, 0 });
    while (!q.empty()) {
      pair<vector<int>, int> v = q.front();
      q.pop();
      if (is_sorted(v.first.begin(), v.first.end()))
        return v.second;

      for (int i = 0; i < v.first.size() - k + 1; ++i) {
        reverse(v.first.begin() + i, v.first.begin() + i + k);
        if (processed.find(v.first) == processed.end()) {
          q.push({ v.first, v.second + 1 });
          processed.insert(v.first);
        }
        reverse(v.first.begin() + i, v.first.begin() + i + k);
      }
    }
    return -1;
  }
};