#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Pronunciation {
public:
  string canPronounce(vector<string> words) {
    for (string word : words) {
      string checkWord;
      for (char c : word) checkWord += tolower(c);
      for (int i = 0; i < word.size(); ++i) {
        if (isVowel(checkWord[i])) {
          if (i + 1 < checkWord.size() && checkWord[i] != checkWord[i + 1] && isVowel(checkWord[i + 1]))
            return word;
        } else {
          if (i + 2 < checkWord.size() && !isVowel(checkWord[i + 1]) && !isVowel(checkWord[i + 2]))
            return word;
        }
      }
    }
    return "";
  }

  bool isVowel(char c) {
    if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o')
      return true;
    return false;
  }
};
