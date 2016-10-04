#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class FibonacciDiv2 {
public:
  int find(int N) {
    vector<int> memo { 0, 1 };
    
    int i = 1;
    while (memo[i] < N) {
      ++i;
      memo.push_back(memo[i - 1] + memo[i - 2]);
    }

    return min(memo[i] - N, N - memo[i - 1]);
  }
};