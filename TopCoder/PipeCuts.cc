#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class PipeCuts {
public:
  double probability(vector<int> weldLocation, int L) {
    double prob = 0;
    sort(weldLocation.begin(), weldLocation.end());
    for (int i = 0; i < weldLocation.size(); ++i) {
      for (int j = i + 1; j < weldLocation.size(); ++j) {
        int first = weldLocation[i];
        int second = weldLocation[j] - first;
        int third = 100 - (first + second);
        if (first > L || second > L || third > L)
          prob += 1;
      }
    }
    return prob / ((weldLocation.size()  * (weldLocation.size() - 1)) / 2);
  }
};

//int main() {
//  PipeCuts pipeCuts;
//  cout << pipeCuts.probability({25, 50, 75}, 25) << endl;
//}