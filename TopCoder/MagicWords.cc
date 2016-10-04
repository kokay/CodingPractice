#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class MagicWords {
public:
  int count(vector<string> S, int K) {
    vector<int> p;
    for (int i = 0; i < S.size(); ++i)
      p.push_back(i);

    int c = 0;
    do {
      string s = "";
      for (int idx : p) s += S[idx];

      c += isMagicWord(s, K);
    } while (next_permutation(p.begin(), p.end()));
    return c;
  }

  bool isMagicWord(string& s, int K) {
    for (int i = 1; i <= s.size(); ++i) {
      string s1 = s.substr(0, s.size() - i);
      string s2 = s.substr(i, s.size() - i);
      if (s.size() % i == 0 && s1 == s2) {
        return K == s.size() / i;
      }
    }
    return  K == 1;
  }
};
//
//int main() {
//  MagicWords m;
//  cout << m.count({ "AB", "RAAB", "RA" }, 2) << endl;
//}
//
