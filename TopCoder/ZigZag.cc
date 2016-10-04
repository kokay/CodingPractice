#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class ZigZag {
public:
  int longestZigZag(vector<int> sequence) {
    int longest = 0;
    vector<int> memoDown(sequence.size(), 1), memoUp(sequence.size(), 1);
    for (int i = 1; i < sequence.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        if (sequence[j] < sequence[i]) memoUp[i] = max(memoUp[i], memoDown[j] + 1);
        else if (sequence[j] > sequence[i]) memoDown[i] = max(memoDown[i], memoUp[j] + 1);
      }
      longest = max(longest, max(memoDown[i], memoUp[i]));
    }
    return longest;
  }
};