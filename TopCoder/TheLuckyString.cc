#include <iostream>
#include <algorithm>

using namespace std;

class TheLuckyString {
public:
  int count(string s) {
    sort(s.begin(), s.end());
    int count = 0;
    do {
      count += isLuckyString(s);
    } while (next_permutation(s.begin(), s.end()));
    return count;
  }
private:
  bool isLuckyString(string& s) {
      for (int i = 0; i < s.size() - 1; ++i)
        if (s[i] == s[i + 1]) return false;
      return true;
  }
};