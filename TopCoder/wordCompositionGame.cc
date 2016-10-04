#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class WordCompositionGame {
public:
  string score(vector<string> listA, vector<string> listB, vector<string> listC) {
    vector<unordered_set<string>> sets({
      {listA.begin(), listA.end()},
      {listB.begin(), listB.end()},
      {listC.begin(), listC.end()},
    });

    string points;
    for (int i = 0; i < sets.size();++i) {
      int totalPoint = 0;
      for (const string& word : sets[i]) {
        int point = 3;
        for (int j = 0; j < sets.size(); ++j) {
          if (i != j && sets[j].find(word) != sets[j].end())
            --point;
        }
        totalPoint += point;
      }
      points += to_string(totalPoint) + "/";
    }

    return points.substr(0, points.size() - 1);
  }
};


//int main() {
//  WordCompositionGame wordCompositionGame;
//  cout << wordCompositionGame.score({ "cat", "dog", "pig", "mouse" }, { "cat", "pig" }, { "dog", "cat" }) << endl;
//}