#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class PalindromeMaker {
public:
  string make(string baseString) {
    sort(baseString.begin(), baseString.end());

    char center = ' ';
    string palindrome;
    size_t idx = 0;
    while (idx < baseString.size()) {
      char checkC = baseString[idx];
      size_t size = findSize(baseString.substr(idx), checkC);
      if (size % 2 == 1) {
        if (center != ' ') return "";
        center = checkC;
      }
      palindrome += string(size / 2, checkC);
      idx += size;
    }
    if (center != ' ') palindrome += center;
    palindrome += string(palindrome.rbegin() + 1, palindrome.rend());
    return palindrome;
  }

private:
  size_t findSize(string sub, char checkC) {
    int size = 0;
    for (int i = 0; sub.size(); ++i) {
      if (sub[i] == checkC) size++;
      else break;
    }
    return size;
  }
};