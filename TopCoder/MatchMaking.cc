#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MatchMaking {
public:
  string makeMatch(vector<string> namesWomen, vector<string> answersWomen,
    vector<string> namesMen, vector<string> answersMen, string queryWomen) {
    vector<pair<string, string>> women, men;
    for (int i = 0; i < namesWomen.size(); ++i) {
      women.push_back({ namesWomen[i], answersWomen[i] });
      men.push_back({ namesMen[i], answersMen[i] });
    }

    sort(women.begin(), women.end());
    for (int i = 0; i < women.size(); ++i) {
      sort(men.begin() + i, men.end(), menSort(women[i]));
      if (women[i].first == queryWomen)
        return men[i].first;
    }
    return "ERROR";
  }

private:
  struct menSort {
    pair<string, string> targetWomen;
    menSort(pair<string, string> women) : targetWomen(women) {}
    bool operator() (const pair<string, string>& m1, const pair<string, string>& m2) {
      int numMatchM1 = 0;
      int numMatchM2 = 0;
      for (int i = 0; i < targetWomen.second.size(); ++i) {
        if (m1.second[i] == targetWomen.second[i]) ++numMatchM1;
        if (m2.second[i] == targetWomen.second[i]) ++numMatchM2;
      }
      if (numMatchM1 != numMatchM2) return numMatchM1 > numMatchM2;
      return m1.first < m2.first;
    }
  };
};