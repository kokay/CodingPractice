#include <iostream>
#include <vector>

using namespace std;

class Generators {
public:
  vector<int> find(int p) {
    vector<int> allGenerators;
    for (int i = 2; i < p; i++)
      if (isGenerator(i, p))
        allGenerators.push_back(i);

    return allGenerators;
  }

private:
  bool isGenerator(int checkNum, int p) {
    vector<bool> s(p, false);
    for (int i = 1; i < p; i++) {
      int num = 1;
      for (int j = 0; j < i; ++j) {
        num *= checkNum;
        num %= p;
      }
      if (s[num]) return false;
      s[num] = true;
    }
    return true;
  }
};