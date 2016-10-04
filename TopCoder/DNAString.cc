#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DNAString {
public:
  int minChanges(int maxPeriod, vector<string> dna) {
    int best = 1000000;
    string s;
    for (int j = 0; j < dna.size(); ++j)
      s += dna[j];

    for (int i = maxPeriod; i > 0; --i) {
      int local = 0;
      for (int j = 0; j < i; ++j) {
        int numA = 0, numC = 0, numG = 0, numT = 0, total = 0;
        for (int idx = j; idx < s.size(); idx += i) {
          switch (s[idx]) {
            case 'A': ++numA; break;
            case 'C': ++numC; break;
            case 'G': ++numG; break;
            case 'T': ++numT; break;
          }
          ++total;
        }
        local += total - max(max(numA, numC), max(numG, numT));
      }
      best = min(best, local);
    }
    return best;
  }
};