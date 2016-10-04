#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <stdlib.h>
#include <string>

using namespace std;

class bloggoHyphenate {
public:
  vector<string> correct(vector<string> dictionary, vector<string> candidates) {
    map<string, string> memo;
    for (string word : dictionary)
      memo.insert({ removeLetter(word, ' '), word });
   
    vector<string> results;
    for (int i = 0; i < candidates.size(); ++i) {
      string correct = memo[removeLetter(candidates[i], '-')];
      results.push_back(check(correct, candidates[i]));
    }
    return results;
  }

private:
  string removeLetter(string word, char c) {
    word.erase(remove(word.begin(), word.end(), c), word.end());
    return word;
  }

  string check(string correct, string candidate) {
    if (correct.find(' ') == string::npos) return correct;

    istringstream ss(correct);
    vector<string> parts;
    string part, corrected;
    while (ss >> part) parts.push_back(part);

    size_t idx = candidate.find('-');
    int minDis = 1000;
    for (int i = 1; i < parts.size(); ++i) {
      string tmp;
      for (int j = 0; j < i; ++j) tmp += parts[j];
      tmp += '-';
      for (int j = i; j < parts.size(); ++j) tmp += parts[j];

      size_t tmpIdx = tmp.find('-');
      int distance = abs(int(tmpIdx - idx));
      if (distance == 0) return "correct";
      if (distance < minDis) {
        minDis = distance;
        corrected = tmp;
      }
    }
    return corrected;
  }
};