#include <iostream>
#include <vector>

using namespace std;

class LetterStrings {
public:
  int sum(vector<string> s) {
    int count = 0;
    for (int i = 0; i < s.size(); ++i) {
      for (int j = 0; j < s[i].size(); ++j)
        count += s[i][j] != '-';
    }

    return count;
  }
};