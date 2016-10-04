#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Soccer {
public:
  int maxPoints(vector<int> wins, vector<int> ties) {
    int maxPoints = 0;
    for (int i = 0; i < wins.size(); ++i) 
      maxPoints = max(maxPoints, 3 * wins[i] + ties[i]);

    return maxPoints;
  }
};