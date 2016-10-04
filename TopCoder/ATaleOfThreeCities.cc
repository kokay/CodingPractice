#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class ATaleOfThreeCities {
public:
  double connect(vector<int> ax, vector<int> ay, vector<int> bx, vector<int> by, vector<int> cx, vector<int> cy) {
    double bestDistanceAtoB = getBestDistance(ax, ay, bx, by); 
    double bestDistanceAtoC = getBestDistance(ax, ay, cx, cy); 
    double bestDistanceBtoC = getBestDistance(bx, by, cx, cy);

    double candidate = min(bestDistanceAtoB + bestDistanceAtoC, bestDistanceAtoB + bestDistanceBtoC);
    return min(candidate, bestDistanceAtoC + bestDistanceBtoC);
  }

  double getBestDistance(vector<int> x1, vector<int> y1, vector<int> x2, vector<int> y2) {
    double bestDistance = 100000000;
    for (int i = 0; i < x1.size(); ++i) {
      for (int j = 0; j < x2.size(); ++j)
        bestDistance = min(bestDistance, hypot(x1[i] - x2[j], y1[i] - y2[j]));
    }
    return bestDistance;
  }
};