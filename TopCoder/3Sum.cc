#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <numeric>

using namespace std;

class ThreeSum {
public:
  vector<vector<int>> threeSum(vector<int> nums) {
    vector<vector<int>> vs;
    if (nums.size() < 3) return vs;

    vector<bool> use(nums.size(), false);
    for (int i = 1; i <= 3; ++i) use[nums.size() - i] = true;

    set<vector<int>> ss;
    do {
      vector<int> v;
      for (int i = 0; i < use.size(); ++i) 
        if (use[i]) v.push_back(nums[i]);

      if (accumulate(v.begin(), v.end(), 0) == 0) {
        sort(v.begin(), v.end());
        ss.insert(v);
      }
    } while (next_permutation(use.begin(), use.end()));

    for (const vector<int>& v : ss) vs.push_back(v);
    return vs;
  }

  vector<vector<int>> threeSum2(vector<int> nums) {
    vector<vector<int>> vs;
    if (nums.size() < 3) return vs;

    sort(nums.begin(), nums.end());
    set<vector<int>> ss;
    for (int i = 0; i < nums.size(); ++i)
    for (int j = i + 1; j < nums.size(); ++j)
    for (int k = j + 1; k < nums.size(); ++k) 
      if (nums[i] + nums[j] + nums[k] == 0)
        ss.insert({ nums[i], nums[j], nums[k] });

    for (const vector<int>& v : ss) vs.push_back(v);
    return vs;
  }

  vector<vector<int>> threeSum3(vector<int> nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> vs;
    if (nums.size() < 3) return vs;
    if (nums.size() == 3 && accumulate(nums.begin(), nums.end(), 0) == 0) {
      vs.push_back(nums);
      return vs;
    }


    set<vector<int>> ss;
    for (int i = 0; i < nums.size() - 3; ++i) {
      int s = i + 1;
      int e = nums.size() - 1;
      while (s < e) {
        if (nums[i] + nums[s] + nums[e] == 0) {
          ss.insert({ nums[i], nums[s], nums[e] });
          e--;
        } else if (nums[i] + nums[s] + nums[e] > 0) {
          e--;
        } else {
          s++;
        } 
      }
    }

    for (const vector<int>& v : ss) vs.push_back(v);
    return vs;
  }
};

//int main() {
//  ThreeSum s;
//  vector<vector<int>> vs = s.threeSum3({0, 0, 0});
//  for(vector<int> v : vs) {
//    for (int i : v) cout << i << " ";
//    cout << endl;
//  }
//}