#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <sstream>
#include <queue>
#include <algorithm>

using namespace std;

class UpDownHiking {
public:
  int maxHeight(int N, int A, int B) {
    int best = 0;
    for (int day = 1; day <= N; ++day) {
      for (int local = A * (day - 1); local <= A * day; ++local) {
        if (local - (B * (N - day)) <= 0)
          best = max(best, local);
      }
    }
    return best;
  }
};
