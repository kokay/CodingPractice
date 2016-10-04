#include <iostream>
#include <math.h>

using namespace std;

class TrafficCongestionDivTwo {
public:
  long long theMinCars(int treeHeight) {
    long long cars = 0, idx = treeHeight - 1;
    while (idx >= 0) {
      cars += (long long)pow(2, idx);
      idx -= 2;
    }
    if (idx == -1) cars += 1;
    return cars;
  }
};