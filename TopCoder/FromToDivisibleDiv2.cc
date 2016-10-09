#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <sstream>
#include <queue>
#include <algorithm>

using namespace std;

class FromToDivisibleDiv2 {
public:
  int shortest(int N, int S, int T, vector<int> a, vector<int> b) {
    vector<vector<bool>> edges(N + 1);
    for (int i = 1; i <= N; ++i) {
      for (int j = 1; j <= N; ++j) {
        if (i == j) continue;
        if (!divisibleBy(i, j, a, b)) continue;

        edges[i].push_back(j);
      }
    }

    vector<int> distance(N + 1, -1);
    queue<int> q;
    q.push(S);
    distance[S] = 0;
    while (!q.empty()) {
      int v = q.front(); q.pop();
      for(int i=0;i<edges[v].size();++i) {
        int t = edges[v][i];
        if(distance[t] == -1) {
          distance[t] = distance[v] + 1;
          if (t == T) return distance[t];
          q.push(t);
        }
      }
    }
    return -1;
  }

  bool divisibleBy(int i, int j, vector<int> a, vector<int> b) {
    for (int idx = 0; idx < a.size(); ++idx) {
      if (i % a[idx] == 0 && j % b[idx] == 0) return true;
    }
    return false;
  }
};