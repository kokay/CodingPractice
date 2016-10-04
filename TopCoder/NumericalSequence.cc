#include <iostream>
#include <vector>

using namespace std;

class NumericalSequence {
public:
  int makePalindrome(vector<int> sequence) {
    int idx, operation = 0;
    while ((idx = findIdxForChange(sequence)) != -1) {
      if (idx < sequence.size() / 2)
        sequence[idx + 1] += sequence[idx];
      else 
        sequence[idx - 1] += sequence[idx];

      sequence.erase(sequence.begin() + idx);
      ++operation;
    }
    return operation;
  }

private:
  int findIdxForChange(vector<int>& sequence) {
    for (int i = 0; i < sequence.size() / 2; ++i) {
      int otherSideIdx = sequence.size() - 1 - i;
      if (sequence[i] != sequence[otherSideIdx]) {
        if (sequence[i] < sequence[otherSideIdx])
          return i;
        else
          return otherSideIdx;
      }
    }
    return -1;
  }
};

//int main() {
//  NumericalSequence numericalSequence;
//  cout << numericalSequence.makePalindrome({ 3,23,21,23,42,39,63,76,13,13,13,32,12,42,26 }) << endl;
//}