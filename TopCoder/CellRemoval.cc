#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class CellRemoval {
public:
  int cellsLeft(vector<int> parent, int deletedCell) {
    int count = 0;
    int startIdx = -1;
    vector<vector<int>> edges = getEdges(parent, &startIdx);
    queue<int> q;
    q.push(startIdx);
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      if (v == deletedCell) continue;
      if (edges[v].size() == 0) count++;
      for (int nextV : edges[v])
        q.push(nextV);
    }
    return count;
  }

private:
  vector<vector<int>> getEdges(vector<int> parent, int* startIdx) {
    vector<vector<int>> edges(parent.size(), vector<int>());
    for (int i = 0; i < parent.size(); ++i) {
      if (parent[i] == -1) *startIdx = i;
      else edges[parent[i]].push_back(i);
    }
    return edges;
  }
};