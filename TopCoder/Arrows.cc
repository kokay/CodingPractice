#include <iostream>
#include <algorithm>

using namespace std;

class Arrows {
public:
  int longestArrow(string s) {
    int count = -1;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '<') {
        int idx = i + 1;
        while (idx < s.size() && s[idx] == '-') ++idx;
        count = max(count, idx - i);
        idx = i + 1;
        while (idx < s.size() && s[idx] == '=') ++idx;
        count = max(count, idx - i);
      }
      else if (s[i] == '>') {
        int idx = i - 1;
        while (idx >= 0 && s[idx] == '-') --idx;
        count = max(count, i - idx);
        idx = i - 1;
        while (idx >= 0 && s[idx] == '=') --idx;
        count = max(count, i - idx);
      }
    }
    return count;
  }
};
//
//int main() {
//  Arrows a;
//  cout << a.longestArrow("<----=====>") << endl;
//}