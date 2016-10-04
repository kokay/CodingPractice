#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class DivisibleByDigits {
public:
  long long getContinuation(int n) {
    string nStr = to_string(n);
    string extra = "";

    while (!isDivisibleByDigits(nStr + extra, nStr)) {
      extra = nextExtra(extra);
    }
    return stoll(nStr + extra);
  }

private:
  bool isDivisibleByDigits(string numStr, string original) {
    long long num = stoll(numStr);
    for (char digit : original) {
      int numDigit = digit - '0';
      if (numDigit != 0 && num % numDigit != 0)
        return false;
    }
    return true;
  }

  string nextExtra(string extra) {
    if (extra.empty()) return "0";
    if (count(extra.begin(), extra.end(), '9') == extra.size())
      return string(extra.size() + 1, '0');

    string tmp = to_string(stoll(extra) + 1);
    return string(extra.size() - tmp.size(), '0') + tmp;
  }
};

//int main() {
//  DivisibleByDigits divisibleByDitis;
//  cout << divisibleByDitis.getContinuation(1000000000) << endl;
//}