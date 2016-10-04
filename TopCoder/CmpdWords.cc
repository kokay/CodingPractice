#include <iostream>
#include <vector>
#include <set>

using namespace std;

class CmpdWords {
public:
  int ambiguous(vector<string> dictionary) {
    set<string> s(dictionary.begin(), dictionary.end());
    set<string> compoundWords;
    for (int i = 0; i < dictionary.size(); ++i) {
      for (int j = 0; j < dictionary.size(); ++j) {
        if (i == j) continue;
        string compoundWord = dictionary[i] + dictionary[j];
        if (s.find(compoundWord) == s.end()) s.insert(compoundWord);
        else compoundWords.insert(compoundWord);
      }
    }
    return compoundWords.size();
  }
};