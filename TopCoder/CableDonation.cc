#include <iostream>
#include <queue>
#include <functional>
#include <set>

using namespace std;

struct Edge {
  int s, d, w;
  bool operator<(const Edge& rhs) const {
    if (w != rhs.w) return w < rhs.w;
    return true;
  }
  bool operator>(const Edge& rhs) const {
    if (w != rhs.w) return w > rhs.w;
    return true;
  }
};

class CableDonation {
public:
  int cable(vector<string> lengths) {
    edges.resize(lengths.size());
    total = 0;
    for (int i = 0; i < lengths.size(); ++i) 
    for (int j = 0; j < lengths[i].size(); ++j) {
      int weight = convert(lengths[i][j]);
      total += weight;
      if (i != j && weight != 0) {
        edges[i].push_back({ i, j, weight });
        edges[j].push_back({ j, i, weight });
      }
    }

    prim();
    if (minEdges.size() != lengths.size() - 1) return -1;
    for (int i = 0; i < minEdges.size(); ++i)
      total -= minEdges[i].w;
    return total;
  }

private:
  vector<vector<Edge>> edges;
  vector<Edge> minEdges;
  int total;

  int convert(char w) {
    if (w == '0') return 0;
    if (w < 'a') return w - 'A' + 1 + 26;
    return w - 'a' + 1;
  }

  void prim () {
    vector<bool> vis(edges.size(), false);
    vis[0] = true;
    priority_queue<Edge, vector<Edge>, greater<Edge>> 
      pq(edges[0].begin(), edges[0].end());

    while (!pq.empty()) {
      Edge e = pq.top(); pq.pop();
      if (vis[e.d]) continue;
      
      vis[e.d] = true;
      minEdges.push_back(e);

      for (Edge candidate : edges[e.d]) {
        if (!vis[candidate.d])
          pq.push(candidate);
      }
    }
  }

  void prim2 () {
    vector<bool> vis(edges.size(), false);
    vis[0] = true;
    multiset<Edge> ms(edges[0].begin(), edges[0].end());

    while (!ms.empty()) {
      Edge e = *ms.begin(); ms.erase(ms.begin());
      if (vis[e.d]) continue;
      
      vis[e.d] = true;
      minEdges.push_back(e);

      for (Edge candidate : edges[e.d]) {
        if (!vis[candidate.d])
          ms.insert(candidate);
      }
    }
  }
};

//int main() {
//  CableDonation cd;
//  cout << cd.cable(
//  { "abc",
//    "def",
//    "ghi" }
//  ) << endl;
//}
//
