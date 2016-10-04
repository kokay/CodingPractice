#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class OneEntrance {
public:
  int count(vector<int> a, vector<int> b, int s) {
    edges = generateEdges(a, b);
    vector<int> candidate;
    for (int i = 0; i < a.size() + 1; ++i)
      if(i != s) candidate.push_back(i);

    int countWays = 0;
    do {
      bool theOne = true;
      hasStaff = vector<bool>(a.size() + 1, false);
      for (int i = 0; i < candidate.size(); ++i) {
        visited = vector<bool>(a.size() + 1, false);
        if (reachable(s, candidate[i]))
          hasStaff[candidate[i]] = true;
        else {
          theOne = false;
          break;
        }
      }
      if (theOne) ++countWays;
    } while (next_permutation(candidate.begin(), candidate.end()));
    return countWays;
  }
private:
  vector<vector<int>> generateEdges(vector<int>& a, vector<int>& b) {
    vector<vector<int>> edges(a.size() + 1, vector<int>());
    for (int i = 0; i < a.size(); ++i) {
      edges[a[i]].push_back(b[i]);
      edges[b[i]].push_back(a[i]);
    }
    return edges;
  }

  bool reachable(int start, int goal) {
    if (start == goal) return true;
    visited[start] = true;
    for (int dest : edges[start]) {
      if (!visited[dest] && !hasStaff[dest])
        if(reachable(dest, goal))
           return true;
    }
    return false;
  }

  vector<vector<int>> edges;
  vector<bool> visited;
  vector<bool> hasStaff;
};

//int main() {
//  OneEntrance oneentrance;
//  cout << oneentrance.count({7, 4, 1, 0, 1, 1, 6, 0}, { 6, 6, 2, 5, 0, 3, 8, 4 }, 4) << endl;
//}