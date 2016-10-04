#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class ScheduleStrength {
public:
  vector<string> calculate(vector<string> teams, vector<string> results) {
    vector<pair<double, string>> teamInfos;
    for (int i = 0; i < teams.size(); ++i)
      teamInfos.push_back({ -getStrength(i, results), teams[i] });

    sort(teamInfos.begin(), teamInfos.end());
    for (int i = 0; i < teams.size(); ++i)
      teams[i] = teamInfos[i].second;

    return teams;
  }

private:
  double getStrength(int teamIdx, vector<string>& results) {
    int win = 0, total = 0;
    for (int i = 0; i < results[teamIdx].size(); ++i) {
      if (results[teamIdx][i] == '-') continue;
      for (int j = 0; j < results[i].size(); ++j) {
        if (j == teamIdx || results[i][j] == '-') continue;
        if (results[i][j] == 'W') win++;
        total++;
      }
    }
    return win * 1.0 / total;
  }
};