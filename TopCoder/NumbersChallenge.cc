#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class NumbersChallenge {
public:
  // brute force
  int MinNumber(vector<int> S) {
    int sum = accumulate(S.begin(), S.end(), 0);
    vector<bool> check(sum + 1, false);
    tryAll(S, check, 0, 0);
    for (int i = 1; i <= sum; ++i) 
      if (!check[i]) return i;
    return -1;
  }

  int MinNumber2(vector<int> S) {
    int sum = accumulate(S.begin(), S.end(), 0);
    vector<bool> check(sum + 1, false);
    for (int subset = 0; subset < (1 << S.size()); ++subset) {
      sum = 0;
      for (int i = 0; i < S.size(); ++i)
        if (subset & (1 << i)) sum += S[i];

      check[sum] = true;
    }
    for (int i = 1; i <= sum; ++i) 
      if (!check[i]) return i;
    return -1;
  }


  //dynamic programming
  int MinNumber3(vector<int> S) {
    int sum = accumulate(S.begin(), S.end(), 0);
    vector<vector<bool>> memo(sum + 1, vector<bool>(S.size() + 1, false));
    for (int i = 0; i < memo[0].size(); ++i) memo[0][i] = true;

    for (int checkSum = 1; checkSum <= sum; ++checkSum) {
      for (int i = 1; i < memo[checkSum].size(); ++i) {
        memo[checkSum][i] = memo[checkSum][i - 1];
        if (checkSum >= S[i - 1] && memo[checkSum - S[i - 1]][i - 1])
          memo[checkSum][i] = true;
      }
      if (!memo[checkSum].back()) return checkSum;
    }
    return -1;
  }
  
private:
  void tryAll(vector<int>& S, vector<bool>& check, int idx, int sum) {
    if (idx == S.size()) {
      check[sum] = true;
    } else {
      tryAll(S, check, idx + 1, sum);
      tryAll(S, check, idx + 1, sum + S[idx]);
    }
  }
};