#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class BigBurger {
public:
  int maxWait(vector<int> arrival, vector<int> service) {
    int maxWaitTime = 0, currentTime = 0;
    for (int i = 0; i < arrival.size(); ++i) {
      if (currentTime > arrival[i]) {
        maxWaitTime = max(maxWaitTime, currentTime - arrival[i]);
        currentTime += service[i];
      } else {
        currentTime = arrival[i] + service[i];
      }
    }
    return maxWaitTime;
  }
};