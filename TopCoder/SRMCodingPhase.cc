#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SRMCodingPhase {
public:
  int countScore(vector<int> points, vector<int> skills, int luck) {
    this->points = points;
    this->skills = skills;
    this->muls = { 2, 4, 8 };
    return tryAll(luck, 0, 75, 0);
  }

private:
  vector<int>points, skills, muls;

  int tryAll(int luck, int idx, int timeRem, int totalScore) {
    if (idx == 4) return totalScore;

    int tryToSolve = 0;
    for (int i = 0; i <= luck; ++i) {
      if (timeRem - (skills[idx] - i) < 0 || skills[idx] - i <= 0) continue;

      int newLuck = luck - i;
      int newTimeRem = timeRem - (skills[idx] - i);
      int newTotalScore = totalScore + points[idx] - (muls[idx] * (skills[idx] - i));
      tryToSolve = max(tryToSolve, tryAll(newLuck, idx + 1, newTimeRem, newTotalScore));
    }
    int tryToNotSolve = tryAll(luck, idx + 1, timeRem, totalScore);
    return max(tryToSolve, tryToNotSolve);
  }
};