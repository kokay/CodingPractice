#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int MAX_QUICKSUMS = 1000000;

class QuickSums {
public:
  int minSums(string numbers, int sum) {
    int bestCount = tryAll(numbers, 0, 0, sum);
    return (bestCount == MAX_QUICKSUMS) ? -1 : bestCount;
  }

private:
  int tryAll(string numbers, int count, int idx, long long sum) {
    if (idx == numbers.size()) {
      if (sum == 0) return count - 1;
      return MAX_QUICKSUMS;
    }

    int bestCount = MAX_QUICKSUMS;
    for (int i = 1; idx + i <= numbers.size(); ++i) {
      long long num = stoll(numbers.substr(idx, i));
      if ((sum - num) < 0) break;
      bestCount = min(bestCount, tryAll(numbers, count + 1, idx + i, sum - num));
    }
    return bestCount;
  }
};