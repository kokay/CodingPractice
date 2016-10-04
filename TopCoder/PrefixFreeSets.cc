#include <iostream>
#include <vector>
#include <set>

using namespace std;

class PrefixFreeSets {
public:
  int maxElements(vector<string> words) {
    set<string> s;
    for (int i = 0; i < words.size(); ++i) {
      bool isPreFix = false;
      for (int j = 0; j < words.size(); ++j) {
        if (i == j) continue;
        if (words[i].size() > words[j].size()) continue;
        if (words[i] != words[j].substr(0, words[i].size())) continue;
        if (words[i] == words[j]) continue;

        isPreFix = true;
        break;
      }
      if (!isPreFix) s.insert(words[i]);
    }
    return s.size();
  }
};
