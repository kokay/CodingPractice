#include <iostream>

using namespace std;

class TandemRepeats {
public:
  int maxLength(string dna, int k) {
    for (int length = dna.size() / 2; length > 0; --length) {
      for (int i = 0; i + length + length <= dna.size(); ++i) {
        string base = dna.substr(i, length);
        string test = dna.substr(i + length, length);
        if (hasTandemRepeat(base, test, k)) return length;
      }
    }
    return 0;
  }

private:
  bool hasTandemRepeat(string& base, string& test, int k) {
    int misMatch = 0;
    for (int i = 0; i < base.size(); ++i) {
      if (base[i] != test[i]) ++misMatch;
      if (misMatch > k) return false;
    }
    return true;
  }
};