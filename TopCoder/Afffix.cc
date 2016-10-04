#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Arrfix {
public:
  int mindiff(vector<int> a, vector<int> b, vector<int> f) {
    vector<int> need, correct, fleft;
    for (int i = 0; i < a.size(); ++i) {
      if (a[i] == b[i]) 
        correct.push_back(b[i]);
      else 
        need.push_back(b[i]);
    }

    for (int i = 0; i < f.size(); ++i) {
      vector<int>::iterator it;
      if ((it = find(need.begin(), need.end(), f[i])) != need.end())
        need.erase(it);
      else if ((it = find(correct.begin(), correct.end(), f[i])) != correct.end())
        correct.erase(it);
      else
        fleft.push_back(f[i]);
    }

    return max(need.size(), fleft.size());
  }
};

//int main() {
//  Arrfix a;
//  cout << a.mindiff({ 375, 837, 597, 837, 837, 603, 21, 375, 597, 351, 351, 837, 837, 597, 292, 42, 375, 42, 292, 597, 375, 21, 603, 375, 351, 375, 42, 597, 292, 42, 603, 597, 837, 21, 597, 42, 42, 837 }, { 603, 375, 21, 292, 375, 375, 597, 292, 292, 351, 597, 42, 42, 351, 351, 837, 837, 21, 603, 375, 21, 603, 375, 42, 21, 351, 837, 21, 292, 21, 603, 21, 597, 597, 42, 837, 597, 351 }, { 351, 42, 597, 42, 21, 351, 21, 292, 603 }) << endl;
//}