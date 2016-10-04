#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class PaternityTest {
public:
  bool checkIdxs(vector<int>& idxs, string& child, string& man) {
    for (int idx : idxs) {
      if (child[idx] != man[idx])
        return false;
    }
    return true;
  }

  vector<int> possibleFathers(string child, string mother, vector<string> men) {
    vector<int> idxs;
    for (int i = 0; i < child.size(); ++i) {
      if (child[i] != mother[i])
        idxs.push_back(i);
    }

    vector<int> fathers;
    for (int i = 0; i < men.size(); ++i) {
      int count = 0;
      for (int j = 0; j < men[i].size(); ++j) 
        if (men[i][j] == child[j]) ++count;

      if (count >= (child.size() / 2) && checkIdxs(idxs, child, men[i]))
        fathers.push_back(i);
    }

    return fathers;
  }
};

//int main() {
//  PaternityTest paternityTest;
//  for (int idx : paternityTest.possibleFathers("ABCDEFGHIJKLMNOPQRST", "ABCDEFGHIJKLMNOPQRST", { "ABCDEFGHIJKLMNOPQRST", "ABCDEFGHIJKLMNOPQRSU", "ABCDEFGHIJKLMNOPQRSX", "ABCDEFGHIJKLMNOPQRSZ", "ABCDEFGHIJKLMNOPQRST" })) {
//    cout << idx << " ";
//  }
//  cout << endl;
//}