#include <iostream>
#include <vector>

using namespace std;

class LeaguePicks {
public:
  vector<int> returnPicks(int position, int friends, int picks) {
    vector<int> recievingPicks;
    vector<bool> line(friends + 1, false);
    line[position] = true;

    int pos = 1;
    while (pos <= picks) {
      for (int i = 1; i <= friends; ++i) {
        if (pos > picks) break;
        if (line[i]) recievingPicks.push_back(pos);
        pos++;
      }
      for (int i = friends; i >= 1; --i) {
        if (pos > picks) break;
        if (line[i]) recievingPicks.push_back(pos);
        pos++;
      }
    }
    return recievingPicks;
  }
};