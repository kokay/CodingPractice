#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class AutoFix {
public:
  string lower(const string& word) {
    string lowerWord;
    for (char c : word) lowerWord.push_back(tolower(c));
    return lowerWord;
  }

  bool bothAreInDic(vector<string>& dictionary, const string& word1, const string& word2) {
    if (find(dictionary.begin(), dictionary.end(), lower(word1)) != dictionary.end() &&
      find(dictionary.begin(), dictionary.end(), lower(word2)) != dictionary.end()) {
      return true;
    }
    return false;
  }

  string fix(string sentence, vector<int> times, vector<string> dictionary) {
    size_t preSpaceIdx = 0, spaceIdx = 0;
    while ((spaceIdx = sentence.find(' ', spaceIdx)) != string::npos) {
      if (times[spaceIdx + 1] - times[spaceIdx] <= 20) {
        string word1 = sentence.substr(preSpaceIdx, spaceIdx - preSpaceIdx);
        string word2 = sentence.substr(spaceIdx + 1, sentence.find(' ', spaceIdx + 1) - (spaceIdx + 1));
        if (!bothAreInDic(dictionary, word1, word2) &&
          bothAreInDic(dictionary, word1 + word2[0], word2.substr(1))) {
          swap(sentence[spaceIdx], sentence[spaceIdx + 1]);
          ++spaceIdx;
        }
      }
      ++spaceIdx;
      preSpaceIdx = spaceIdx;
    }

    return sentence;
  }
};