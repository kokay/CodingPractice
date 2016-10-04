#include <iostream>
#include <string>

using namespace std;

class LargestSubsequence {
public:
  string getLargest(string s) {
    string largest;
    size_t idx = 0;
    while ((idx = findLastCharIdx(s, idx)) != string::npos) {
      largest += s[idx++];
    }
    return largest;
  }

private:
  size_t findLastCharIdx(string s, size_t idx) {
    size_t theIdx = string::npos;
    char theChar = 'a' - 1;
    for (size_t i = idx; i < s.size(); ++i) {
      if (theChar < s[i]) {
        theChar = s[i];
        theIdx = i;
      }
    }
    return theIdx;
  }
};

//int main() {
//  LargestSubsequence largestSubsequence;
//  cout << largestSubsequence.getLargest("example") << endl;
//}
