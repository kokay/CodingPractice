#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string.h>

using namespace std;

class RGBStreet {
public:
  int estimateCost(vector<string> houses) {
    int r, g, b;
    vector<vector<int>> costs;
    for (int i = 0; i < houses.size(); ++i) {
      istringstream ss(houses[i]);
      ss >> r >> g >> b;
      costs.push_back({ r, g, b });
    }

    int memo[20][3];
    for (int i = 0; i < 3; ++i)
      memo[0][i] = costs[0][i];

    for (int i = 1; i < costs.size(); ++i) {
      memo[i][0] = min(memo[i - 1][1], memo[i - 1][2]) + costs[i][0];
      memo[i][1] = min(memo[i - 1][0], memo[i - 1][2]) + costs[i][1];
      memo[i][2] = min(memo[i - 1][0], memo[i - 1][1]) + costs[i][2];
    }

    int minCost = 10000000;
    for (int i = 0; i < 3; ++i)
      minCost = min(minCost, memo[costs.size() - 1][i]);
    return minCost;
  }
};