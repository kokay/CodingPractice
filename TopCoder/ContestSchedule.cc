#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class ContestSchedule {
public:

  double expectedWinnings(vector<string> contests) {
    vector<Contest> contestInfos;
    int start, end, prob;
    for (int i = 0; i < contests.size(); ++i) {
      istringstream ss(contests[i]);
      ss >> start >> end >> prob;
      contestInfos.push_back({ start, end, prob / 100.0 });
    }
    sort(contestInfos.begin(), contestInfos.end());

    vector<double> memo(contests.size(), 0);
    memo[0] = contestInfos[0].prob;
    double bestProb = 0;
    for (int i = 1; i < contests.size(); ++i) {
      for (int j = 0; j < i ; ++j) {
        if (contestInfos[i].start >= contestInfos[j].end)
          memo[i] = max(memo[i], memo[j] + contestInfos[i].prob);
      }
      bestProb = max(bestProb, memo[i]);
    }
    return bestProb;
  }

private:
  struct Contest {
    int start, end;
    double prob;
    bool operator <(const Contest& rhs) const {
      return this->start < rhs.start;
    }
  };
};