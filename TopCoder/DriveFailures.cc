#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DriveFailures {
public:
  vector<double> failureChances(vector<double> failureProb) {
    vector<double> probabilities(failureProb.size() + 1, 0);
    for (int i = 0; i < probabilities.size(); ++i) {
      probabilities[i] = getProbability(failureProb, i);
    }
    return probabilities;
  }

private:
  double getProbability(vector<double>& failureProb, int numberOfFailureDrives) {
    vector<bool> v(numberOfFailureDrives, false);
    for (int i = 0; i < failureProb.size() - numberOfFailureDrives; ++i)
      v.push_back(true);

    double prob = 0;
    do {
      double localProb = 1;
      for (int i = 0; i < v.size(); ++i) {
        if (v[i]) localProb *= 1 - failureProb[i];
        else      localProb *= failureProb[i];
      }
      prob += localProb;
    } while (next_permutation(v.begin(), v.end()));
    
    return prob;
  }
};

//int main() {
//  DriveFailures driveFailures;
//  for (auto prob : driveFailures.failureChances({ 0.92342446, 0.1231242, 0.6666346, 0.92342446, 0.1231242, 0.6666346, 0.92342446, 0.1231242, 0.6666346, 0.92342446, 0.1231242, 0.6666346, 0.92342446, 0.1231242, 0.6666346 })) {
//    cout << prob << endl;
//  }
//}