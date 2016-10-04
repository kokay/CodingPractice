#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class TagalogDictionary {
public:
  vector<string> sortWords(vector<string> words) {
    sort(words.begin(), words.end(), TagalogDictionary::sortCriteria);
    return words;
  }

private:
  static bool sortCriteria(const string& s1, const string s2) {
    vector<string> s1tmp = getVecStr(s1);
    vector<string> s2tmp = getVecStr(s2);
    if (s1tmp.size() < s2tmp.size()) {
      for (int i = 0; i < s1tmp.size(); ++i) {
        int s1Rank = getRank(s1tmp[i]);
        int s2Rank = getRank(s2tmp[i]);
        if (s1Rank != s2Rank) return s1Rank < s2Rank;
      }
      return true;
    }
    else {
      for (int i = 0; i < s2tmp.size(); ++i) {
        int s1Rank = getRank(s1tmp[i]);
        int s2Rank = getRank(s2tmp[i]);
        if (s1Rank != s2Rank) return s1Rank < s2Rank;
      }
      return false;
    }
  }

  static int getRank(string letter) {
    if (letter == "ng") return 12;
    switch (letter[0]) {
    case 'a': return 1;
    case 'b': return 2;
    case 'k': return 3;
    case 'd': return 4;
    case 'e': return 5;
    case 'g': return 6;
    case 'h': return 7;
    case 'i': return 8;
    case 'l': return 9;
    case 'm': return 10;
    case 'n': return 11;
    case 'o': return 13;
    case 'p': return 14;
    case 'r': return 15;
    case 's': return 16;
    case 't': return 17;
    case 'u': return 18;
    case 'w': return 19;
    case 'y': return 20;
    default:  return 30;
    }
  }

  static vector<string> getVecStr(string s) {
    vector<string> vecStr;
    for (int i = 0; i < s.size(); ++i) {
      if (s.substr(i, 2) == "ng") {
        vecStr.push_back("ng");
        i++;
      }
      else {
        vecStr.push_back(s.substr(i, 1));
      }
    }
    return vecStr;
  }
};
