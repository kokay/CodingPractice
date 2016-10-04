#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class StandInLine {
public:
  vector<int> reconstruct(vector<int> left) {
    vector<int> order(left.size(), 100);
    for (int i = 0; i < left.size(); ++i) {
      int count = 0;
      for (int j = 0; j < order.size(); ++j) {
        if (count == left[i] && order[j] == 100) {
          order[j] = i + 1;
          break;
        }
        if (order[j] > i + 1) count++;
      }
    }
    return order;
  }
};