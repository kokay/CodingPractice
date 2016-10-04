#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class VolumeDiscount {
public:
  const int MAX = 1000000000;

  int bestDeal(vector<string> priceList, int quentity) {
    vector<pair<int, int>> list;
    int unit, cost;;
    for (int i = 0; i < priceList.size(); ++i) {
      istringstream ss(priceList[i]);
      ss >> unit >> cost;
      list.push_back({ unit, cost });
    }

    vector<int> memo(quentity + 99, MAX);
    memo[0] = 0;
    for (int i = 0; i < quentity; ++i) {
      for (int j = 0; j < list.size(); ++j)
        memo[i + list[j].first] = min(memo[i + list[j].first], memo[i] + list[j].second);
    }

    int best = MAX;
    for (int i = quentity; i < quentity + 99; ++i) 
      best = min(best, memo[i]);
    return best;
  }
};
