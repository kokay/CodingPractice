#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class PlayGame {
public:
  int saveCreatures(vector<int> you, vector<int> computer) {
    sort(you.begin(), you.end());
    sort(computer.begin(), computer.end());
    int sumStrengths = 0;
    for (int i = you.size() - 1; i >= 0; --i) {
      for (int j = computer.size() - 1; j >= 0; --j)
        if (you[i] > computer[j]) {
          sumStrengths += you[i];
          computer.erase(computer.begin() + j);
          break;
        }
    }
    return sumStrengths;
  }
};