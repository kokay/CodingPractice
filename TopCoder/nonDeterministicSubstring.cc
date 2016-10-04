#include <iostream>
#include <unordered_set>

using namespace std;

class NonDeterministicSubstring {
public:
  long ways(string A, string B) {
    if (A.size() < B.size()) return 0;

    unordered_set<string> set;
    for (int i = 0; i <= A.size() - B.size(); ++i) {
      bool match = true;
      for (int j = 0; j < B.size(); ++j) {
        if (B[j] != '?' && A[i + j] != B[j]) {
          match = false;
          break;
        }
      }
      if (match) set.insert(A.substr(i, B.size()));
    }
    return set.size();
  }
};