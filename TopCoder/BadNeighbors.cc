#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class BadNeighbors {
public:
  int maxDonations(vector<int> donations) {
    int best = 0;
    vector<int> memo = donations;
    vector<bool> firstIn(donations.size(), false);
    firstIn[0] = true;
    for (int i = 2; i < donations.size() - 1; ++i) {
      for (int j = 0; j < i - 1; ++j) {
        if (memo[j] + donations[i] > memo[i]) {
          memo[i] = memo[j] + donations[i];
          if (firstIn[j]) firstIn[i] = true;
          else firstIn[i] = false;
        }
      }
      best = max(best, memo[i]);
    }

    int lastIdx = donations.size() - 1;
    for (int j = 1; j < lastIdx - 1; ++j) {
      if (!firstIn[j] && memo[j] + donations[lastIdx] > memo[lastIdx])
        memo[lastIdx] = memo[j] + donations[lastIdx];
    }
    return max(best, memo[lastIdx]);
  }
};

//int main() {
//  BadNeighbors badNeighbors;
//  cout << badNeighbors.maxDonations(
//  { 930, 235, 680, 718, 932, 471, 908, 14, 754, 695, 76, 601, 388, 606, 957, 580, 961, 512, 510, 979, 442, 602, 341, 641, 153, 196, 974, 937, 936, 487, 820, 243, 738, 313 }
//  ) << endl;
//}