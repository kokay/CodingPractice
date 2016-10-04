#include <iostream>
#include <vector>

using namespace std;

class grafixCorrupt {
public:
  int selectWord(vector<string> dictionary, string candidate) {
    int idx = -1, bestMatch = 0, match = 0;
    for (int i = 0; i < dictionary.size(); ++i) {
      match = countMatch(dictionary[i], candidate);
      if(bestMatch < match) {
        bestMatch = match;
        idx = i;
      }
    }
    return idx;
  }

  int selectWord2(vector <string> dictionary, string candidate) {
    int bestIdx = -1, bestNumberOfMatch = 0, numberOfMatch = 0;
    for (int i = 0; i < dictionary.size(); ++i) {
      numberOfMatch = 0;
      for (int c = 0; c < candidate.size(); ++c) {
        if (dictionary.at(i).at(c) == candidate.at(c)) {
          ++numberOfMatch;
        }
      }

      if (bestNumberOfMatch < numberOfMatch) {
        bestNumberOfMatch = numberOfMatch;
        bestIdx = i;
      }
    }
    return bestIdx;
  }

private:
  int countMatch(string& word1, string& word2) {
    int count = 0;
    for (int i = 0; i < word1.size(); ++i) {
      if (word1[i] == word2[i])
        ++count;
    }
    return count;
  }
};

//int main() {
//
//}