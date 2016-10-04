#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class RollingDiceDivTwo {
public:
  int minimumFaces(vector<string> rolls) {
    for (int i = 0; i < rolls.size();++i) 
      sort(rolls[i].begin(), rolls[i].end());

    int sum = 0, local;
    for (int i = 0; i < rolls[0].size(); ++i) {
      local = 0;
      for (int j = 0; j < rolls.size(); ++j) 
        local = max(local, rolls[j][i] - '0');

      sum += local;
    }
    return sum;
  }
};