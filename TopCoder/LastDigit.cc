#include <iostream>

using namespace std;

class LastDigit {
public:
  long long findX(long long S) {
    long long lo = 0, hi = S - 1;
    while (lo <= hi) {
      long long mid = lo + (hi - lo) / 2;
      long long x = generateX(mid);

      if      (x < S) lo = mid + 1;
      else if (x > S) hi = mid - 1;
      else            return mid;
    }
    return -1;
  }

  long long generateX(long long num) {
    long long x = 0;
    while (num > 0) {
      x += num;
      num /= 10;
    }
    return x;
  }
};

//int main() {
//  LastDigit ld;
//  cout << ld.findX(564) << endl;
//}