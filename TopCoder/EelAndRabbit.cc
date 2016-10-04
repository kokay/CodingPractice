#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class EelAndRabbit {
public:
  int getmax(vector<int> l, vector<int> t) {
    vector<int> candidateTimes;
    for (int i = 0; i < l.size(); ++i) {
      candidateTimes.push_back(t[i]);
      candidateTimes.push_back(t[i] + l[i]);
    }
    candidateTimes.erase(unique(candidateTimes.begin(), candidateTimes.end()), candidateTimes.end());
    sort(candidateTimes.begin(), candidateTimes.end());
    
    int best = 1;
    for (int i = 0; i < candidateTimes.size(); ++i) {
      int firstTime = candidateTimes[i];
      for (int j = i + 1; j < candidateTimes.size(); ++j) { 
        int secondTime = candidateTimes[j];
        int count = 0;
        for (int k = 0; k < l.size(); ++k) {
          if (firstTime >= t[k] && firstTime <= t[k] + l[k])
            count++;
          else if (secondTime >= t[k] && secondTime <= t[k] + l[k])
            count++;
        }
        best = max(best, count);
      }
    }
    return best;
  }
};