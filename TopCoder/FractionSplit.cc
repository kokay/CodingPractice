#include <iostream>
#include <vector>
#include <string>

using namespace std;

class FractionSplit {
public:
  vector<string> getSum(int n, int d) {
    vector<string> sum;
    int denominator = 2;
    while (n != 0) {
      int newN = n * denominator;
      int newD = d * denominator;
      if (newN - d >= 0) {
        n = newN - d;
        d = newD;
        sum.push_back("1/" + to_string(denominator));
      }
      denominator++;
    }
    return sum;
  }
};