#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>

using namespace std;

class VolumeGuess {
public:
  int correctVolume(vector<string> queries, int numBoxes, int ithBox) {
    string strIdx1, strIdx2, strVol;
    vector<set<int>> memo(numBoxes + 1);
    vector<int> volumes(numBoxes + 1, -1);
    for (int i = 0; i < queries.size(); ++i) {
      istringstream ss(queries[i]);
      getline(ss, strIdx1, ',');
      getline(ss, strIdx2, ',');
      getline(ss, strVol, ',');

      int idx1 = stoi(strIdx1);
      int idx2 = stoi(strIdx2);
      int vol = stoi(strVol);

      if (memo[idx1].find(vol) == memo[idx1].end()) memo[idx1].insert(vol);
      else volumes[idx1] = vol;

      if (memo[idx2].find(vol) == memo[idx2].end()) memo[idx2].insert(vol);
      else volumes[idx2] = vol;
    }
    return volumes[ithBox];
  }
};

//int main() {
//  VolumeGuess v;
//  cout << v.correctVolume(
//  { "1,02,10","2,3,010","1,3,20" }
//    ,3
//    ,2) << endl;
//}
//
