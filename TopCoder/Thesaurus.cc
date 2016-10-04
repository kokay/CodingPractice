#include <iostream>
#include <vector>
#include <set>
#include <sstream>
#include <algorithm>

using namespace std;

class Thesaurus {
public:
  vector<string> edit(vector<string> entry) {
    vector<set<string>> memo = generateMemo(entry);

    bool allProcessed = false;
    while (!allProcessed) {
      allProcessed = true;
      for (int i = 0; i < memo.size() - 1; ++i) {
        for (int j = i + 1; j < memo.size(); ++j) {
          if (has2moreSameWords(memo[i], memo[j])) {
            memo[i].insert(memo[j].begin(), memo[j].end());
            memo.erase(memo.begin() + j);
            allProcessed = false;
            break;
          }
        }
        if (!allProcessed) break;
      }
    }
    return format(memo);
  }
private:
  vector<set<string>> generateMemo(vector<string> entry) {
    vector<set<string>> memo(entry.size());
    string word;
    for (int i = 0; i < entry.size(); ++i) {
      stringstream ss(entry[i]);
      while (ss >> word)
        memo[i].insert(word);
    }
    return memo;
  }

  bool has2moreSameWords(set<string>& set1, set<string>& set2) {
    int count = 0;
    for (string word : set1) {
      if (set2.find(word) != set2.end())
        count++;
      if (count == 2)
        return true;
    }
    return false;
  }

  vector<string> format(vector<set<string>>& memo) {
    vector<string> formated;
    string str;
    for (set<string>& s : memo) {
      str = "";
      for (const string& word : s) 
        str += word + " ";

      formated.push_back(str.substr(0, str.size() - 1));
    }
    sort(formated.begin(), formated.end());
    return formated;
  }
};

//int main() {
//  Thesaurus thesaurus;
//  for (string& list : thesaurus.edit({ "ape monkey wrench", "wrench twist strain", "monkey twist frugue strain" })) {
//    cout << list << endl;
//  }
//}