#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class ColorfulRoad {
public:
  char nextColor(char color) {
    switch (color) {
      case 'R': return 'G';
      case 'G': return 'B';
      default : return 'R';
    }
  }

  int getMin(string road) {
    vector<int> cost(road.size(), 100000);
    cost[0] = 0;

    for (int i = 1; i < road.size(); ++i) {
      for (int j = 0; j < i; ++j)
        if (nextColor(road[j]) == road[i])
          cost[i] = min(cost[i], cost[j] + (i - j) * (i - j));
    }
    return cost.back() == 100000 ? -1 : cost.back();
  }
};
