#include <iostream>
#include <string>

using namespace std;

class DigitsSum {
public:
  int lastDigit(int n) {
    while (n >= 10) {
      string numStr = to_string(n);
      n = 0;
      for (char c : numStr) n += c - '0';
    }
    return n;
  }
};

//int main() {
//  DigitsSum digitsSum;
//  cout << digitsSum.lastDigit(314) << endl;
//}