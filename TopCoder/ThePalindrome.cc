#include <iostream>

using namespace std;

class ThePalindrome {
public:
  int find(string s) {
    for (int i = 0; i <= s.size(); ++i) {
      string addStr = s.substr(0, i);
      string checkStr = s + string(addStr.rbegin(), addStr.rend());
      if (isPalindrome(checkStr)) return checkStr.size();
    }
    return -1;
  }
private:
  bool isPalindrome(string checkStr) {
    for (int i = 0; i * 2 < checkStr.size(); ++i) {
      if (checkStr[i] != checkStr[checkStr.size() - 1 - i])
        return false;
    }
    return true;
  }
};