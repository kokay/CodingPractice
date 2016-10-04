#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class AustrianLotto {
public:
  vector<int> evaluate(string drawing, vector<string> picks) {
    vector<int> ans(7, 0);
    stringstream ss(drawing);
    int num;
    vector<bool> draw(46, false);
    while (ss >> num) draw[num] = true;

    for (int i = 0; i < picks.size(); ++i) {
      stringstream ss(picks[i]);
      int count = 0;
      while(ss >> num)
        if (draw[num]) ++count;

      ++ans[count];
    }
    return ans;
  }
};