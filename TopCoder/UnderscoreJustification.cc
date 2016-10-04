#include <iostream>
#include <vector>
#include <string>

using namespace std;

class UnderscoreJustfication {
public:
  string justifyLine(vector<string> words, int width) {
    string line = words[0];
    int numOfPlaces = words.size() - 1;
    int spaces = width - getNumOfAllLetters(words);;
    int eachSpaceSize = spaces / numOfPlaces;
    int rem = spaces % numOfPlaces;

    for (int i = 1; i < words.size();++i) {
      line += string(eachSpaceSize, '_');
      if ((words[i][0] > '_' && rem != 0 ) || rem >= words.size() - i) {
        line += string(1, '_');
        --rem;
      }
      line += words[i];
    }

    return line;
  }

private:
  int getNumOfAllLetters(vector<string> words) {
    int count = 0;
    for (string& word : words)
      count += word.size();
    return count;
  }

};