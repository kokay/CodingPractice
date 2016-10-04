#include <iostream>
#include <vector>

using namespace std;

class NumberofFiboCalls {
public:
  vector<int> fiboCallsMade(int n) {
    vector<int> memo0(41, 0), memo1(41, 0);
    memo0[0] = 1, memo1[1] = 1;

    for (int i = 2; i <= n; ++i) {
      memo0[i] = memo0[i - 1] + memo0[i - 2];
      memo1[i] = memo1[i - 1] + memo1[i - 2];
    }
    return vector<int>({ memo0[n], memo1[n] });
  }
};
