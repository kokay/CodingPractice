#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class CarolsSinging {
public:
  int choose(vector<string> lyrics) {
    this->lyrics = lyrics;
    return checkAll(0, set<int>(), 0);
  }

private:
  vector<string> lyrics;
  int checkAll(int idx, set<int> member, int numCrarols) {
    if (idx == lyrics[0].size()) {
      if (member.size() == lyrics.size()) return numCrarols;
      else return 11;
    }

    int nonInclude = checkAll(idx + 1, member, numCrarols);
    for (int i = 0; i < lyrics.size(); ++i)
      if (lyrics[i][idx] == 'Y') member.insert(i);
    return min(nonInclude, checkAll(idx + 1, member, numCrarols + 1));
  }
};