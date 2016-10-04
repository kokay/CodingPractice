#include <iostream>
#include <vector>

using namespace std;

class TwoTurtledoves {
public:
  int presentType(int n) {
    int day = 1, currentN = 1, type = -1;
    while (true) {
      for (int i = day; i >= 1; --i) {
        type = i;
        for (int j = 0; j < i; ++j) {
          if (currentN == n) return type;
          currentN++;
        }
      }
      day++;
    }
  }

  int presentType2(int n) {
    int currentN = 0;
    for (int day = 1;; ++day) {
      for (int i = day; i >= 1; --i) {
        currentN += i;
        if (currentN >= n) return i;
      }
    }
  }
};
