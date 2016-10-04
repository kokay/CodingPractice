#include <iostream>
#include <vector>

using namespace std;

class IsomorphicWords {
public:
  int countPairs(vector<string> words) {
    int count = 0;
    for (int i = 0; i < words.size() - 1; ++i) {
      for (int j = i + 1; j < words.size(); ++j) 
        count += areIsomorphicWords(words[i], words[j]);
    }
    return count;
  }
private:
  bool areIsomorphicWords(string w1, string w2) {
    vector<char> table1(26, '\0'), table2(26, '\0');
    for (int i = 0; i < w1.size(); ++i) {
      if (table1[w1[i] - 'a'] == '\0')
        table1[w1[i] - 'a'] = w2[i];
      else if (table1[w1[i] - 'a'] != w2[i])
        return false;

      if (table2[w2[i] - 'a'] == '\0')
        table2[w2[i] - 'a'] = w1[i];
      else if (table2[w2[i] - 'a'] != w1[i])
        return false;
    }
    return true;
  }
};