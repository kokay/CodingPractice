#include <iostream>
#include <vector>

using namespace std;

class FibonacciPositioning {
public:
  double getFPosition(int n) {
    vector<int> memo(3, 1);
    while (memo.back() < n)
      memo.push_back(memo[memo.size() - 1] + memo[memo.size() - 2]);

    if (memo.back() == n) return memo.size() - 1;
    int lastIdx = memo.size() - 1, secondLastIdx = memo.size() - 2;
    return secondLastIdx +
      (n - memo[secondLastIdx]) / double((memo[lastIdx] - memo[secondLastIdx]));
  }
};