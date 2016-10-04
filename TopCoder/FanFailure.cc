#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class FanFailure {
public:
  vector<int> getRange(vector<int> capacities, int minCooling) {
    vector<int> range(2, 0);
    sort(capacities.begin(), capacities.end());

    int total, total2;
    total = total2 = accumulate(capacities.begin(), capacities.end(), 0);
    for (int i = 0; i < capacities.size(); ++i) {
      if (total - capacities[i] < minCooling) break;
      total -= capacities[i];
      range[0]++;
    }

    for (int i = capacities.size() - 1; i >= 0; --i) {
      if (total2 - capacities[i] < minCooling) break;
      total2 -= capacities[i];
      range[1]++;
    }
    return range;
  }
};