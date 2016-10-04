#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <stack>

using namespace std;

struct Edge {
  int dist;
  int weight;
};

class Circuits {
public:
  int howLong(vector<string> connects, vector<string> costs) {
    isStart = vector<bool>(connects.size(), true);
    vector<vector<Edge>> edges = generateEdges(connects, costs);
    stack<int> topologicalOrder = generateTopologicalOrder(edges);

    int best = -1000;
    vector<int> memo(connects.size(), -1000);
    for (int i = 0; i < isStart.size(); ++i)
      if (isStart[i]) memo[i] = 0;

    while (!topologicalOrder.empty()) {
      int vertex = topologicalOrder.top();
      topologicalOrder.pop();
      if (memo[vertex] == -1000) continue;
      for (Edge& edge : edges[vertex]) {
        if (memo[edge.dist] < memo[vertex] + edge.weight) {
          memo[edge.dist] = memo[vertex] + edge.weight;
          best = max(best, memo[edge.dist]);
        }
      }
    }
    return best;
  }

private:
  vector<vector<Edge>> generateEdges(vector<string> connects, vector<string> costs) {
    vector<vector<Edge>> edges(connects.size(), vector<Edge>());
    int dist, weight;
    for (int i = 0; i < connects.size(); ++i) {
      stringstream sConnect(connects[i]);
      stringstream sCost(costs[i]);
      while (sConnect >> dist && sCost >> weight) {
        edges[i].push_back({ dist, weight });
        isStart[dist] = false;
      }
    }
    return edges;
  }

  void DFSforTopological(int vertex, vector<vector<Edge>>& edges, vector<bool>& visited, stack<int>& topologicalOrder) {
    visited[vertex] = true;
    for (Edge& edge : edges[vertex]) {
      if (!visited[edge.dist])
        DFSforTopological(edge.dist, edges, visited, topologicalOrder);
    }
    topologicalOrder.push(vertex);
  }

  stack<int> generateTopologicalOrder(vector<vector<Edge>> edges) {
    stack<int> topologicalOrder;
    vector<bool> visited(edges.size(), false);

    for (int i = 0; i < edges.size(); ++i) {
      if (!visited[i])
        DFSforTopological(i, edges, visited, topologicalOrder);
    }
    return topologicalOrder;
  }

  vector<bool> isStart;
};
