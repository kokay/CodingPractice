#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Matching {
public:
  string findLeft(int type, string& first, string& second) {
    static vector<vector<string>> table({ 
      { "CIRCLE", "SQUIGGLE", "DIAMOND" }, 
      { "RED", "BLUE", "GREEN" }, 
      { "SOLID", "STRIPED", "EMPTY" }, 
      { "ONE", "TWO", "THREE" }});

    for (string word : table[type]) 
      if (word != first && word != second)
        return word;

    return "ERROR";
  }

  vector<string> findMatch(vector<string> first, vector<string> second) {
    vector<string> third;
    for (int i = 0; i < first.size(); ++i) {
      if (first[i] == second[i]) third.push_back(first[i]);
      else third.push_back(findLeft(i, first[i], second[i]));
    }
    return third;
  }
};