#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

class CuttingBitString {
public:
  int getmin(string s) {
    int minCut = solve(s);
    return minCut == MAX ? -1 : minCut;
  }

private:
  int MAX = 10000;
  map<string, int> m;

  int solve(string s) {
    if (m.find(s) != m.end()) return m[s];
    if (s.empty()) return 0;
    if (s.front() == '0') return MAX;

    int minCut = MAX;
    for (int size = 1; size <= s.size(); ++size) {
      if (isPowerOf5(stoll(s.substr(0, size), nullptr, 2)))
        minCut = min(minCut, 1 + solve(s.substr(size)));
    }
    return m[s] = minCut;
  }

  bool isPowerOf5(long long n) {
    while (n > 1) {
      if (n % 5 != 0) return false;
      n /= 5;
    }
    return n == 1;
  }
};

//int main() {
//  CuttingBitString c;
//  for (int i = 0; i < 10000; ++i) {
//    c.getmin("11110011100111011100111100110110110111100110111001");
//  }
//}
