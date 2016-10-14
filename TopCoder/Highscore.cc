#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Highscore {
public:
  int getRank(vector<int> scores, int newscore, int places) {
    for (int i = 0; i < places; ++i) {
      if (i >= scores.size() || newscore > scores[i]) {
        for (int j = i - 1; j >= 0; --j)
          if (newscore != scores[j]) return j + 2;

        return 1;
      }
    }
    return -1;
  }
};
