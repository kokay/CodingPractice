#include <iostream>
#include <vector>
#include <string>

using namespace std;

class WordForm {
public:
  string getSequence(string word) {
    string sequence = isVowel(word, 0, ' ') ? "V" : "C";
    for (int i = 1; i < word.size(); ++i) {
      if (isVowel(word, i, sequence.back())) {
        if(sequence.back() != 'V') sequence += 'V';
      } else {
        if (sequence.back() != 'C') sequence += 'C';
      }
    }
    return sequence;
  }

private:
  bool isVowel(string& word, size_t idx, char sequenceLast) {
    if (word[idx] == 'a' || word[idx] == 'A' ||
      word[idx] == 'e' || word[idx] == 'E' ||
      word[idx] == 'i' || word[idx] == 'I' ||
      word[idx] == 'o' || word[idx] == 'O' ||
      word[idx] == 'u' || word[idx] == 'U') {
      return true;
    }
    else if ((word[idx] == 'y' || word[idx] == 'Y') && sequenceLast == 'C') {
      return true;
    }
    return false;
  }
};