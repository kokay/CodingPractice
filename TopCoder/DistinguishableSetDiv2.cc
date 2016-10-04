#include <iostream>
#include <vector>
#include <set>

using namespace std;

class DistinguiableSetDiv2 {
public:
  int count(vector<string> answer) {
    int count = 0;
    for (int s = 0; s < (1 << answer[0].size()); ++s) {
      set<string> strSet;
      for (int i = 0; i < answer.size(); ++i)
        strSet.insert(getAnswer(answer[i], s));

      count += (strSet.size() == answer.size());
    }
    return count;
  }

  string getAnswer(string& s, int set) {
    string ans;
    for (int i = 0; i < s.size(); ++i)
      if (set & (1 << i))
        ans += s[i];
    return ans;
  }
};

//int main() {
//  DistinguiableSetDiv2 d;
//  cout << d.count({ "AAAAAAAAAA", "AAAAAAAAAA", "AAAAAAAAAA", "AAAAAAAAAA", "AAAAAAAAAA", "AAAAAAAAAA", "AAAAAAAAAA", "AAAAAAAAAA", "AAAAAAAAAA", "AAAAAAAAAA", "AAAAAAAAAA", "AAAAAAAAAA", "AAAAAAAAAA", "AAAAAAAAAA", "AAAAAAAAAA", "AAAAAAAAAA", "AAAAAAAAAA", "AAAAAAAAAA", "AAAAAAAAAA", "AAAAAAAAAA", "AAAAAAAAAA", "AAAAAAAAAA", "AAAAAAAAAA", "AAAAAAAAAA", "AAAAAAAAAA", "AAAAAAAAAA", "AAAAAAAAAA", "AAAAAAAAAA", "AAAAAAAAAA", "AAAAAAAAAA", "AAAAAAAAAA", "AAAAAAAAAA", "AAAAAAAAAA", "AAAAAAAAAA", "AAAAAAAAAA", "AAAAAAAAAA", "AAAAAAAAAA", "AAAAAAAAAA", "AAAAAAAAAA", "AAAAAAAAAA", "AAAAAAAAAA", "AAAAAAAAAA", "AAAAAAAAAA", "AAAAAAAAAA", "AAAAAAAAAA", "AAAAAAAAAA", "AAAAAAAAAA", "AAAAAAAAAA", "AAAAAAAAAA", "AAAAAAAAAA" }) << endl;
//}