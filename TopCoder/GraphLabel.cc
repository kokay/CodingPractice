#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class GraphLabel {
public:
  int adjacentDifference(vector<string> graph) {
    vector<int> labels;
    for (int i = 1; i <= graph.size(); ++i)
      labels.push_back(i);

    int best = 10000;
    do {
      best = min(best, findMinAdjacentDifference(labels, graph));
    } while (next_permutation(labels.begin(), labels.end()));
    return best;
  }

private:
  int findMinAdjacentDifference(vector<int>& labels, vector<string>& graph) {
    int maxDiff = 0;
    for (int i = 0; i < graph.size(); ++i) {
      for (int j = 0; j < graph.size(); ++j)
        if(graph[i][j] == '1')
          maxDiff = max(maxDiff, abs(labels[i] - labels[j]));
    }
    return maxDiff;
  }
};