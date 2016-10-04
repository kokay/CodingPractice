#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class SortBooks {
public:
  vector<int> checkManually(vector<string> field1, vector<string> field2) {
    vector<int> checkIdxs;
    for (int i = 0; i < field1.size(); ++i) {
      if(isTitle(field1[i]) == isTitle(field2[i]))
        checkIdxs.push_back(i);
    }
    return checkIdxs;
  }

private:
  bool isTitle(string field) {
    for (int i = 0; i < field.size(); ++i)
      field[i] = toupper(field[i]);

    stringstream ss(field);
    string word;
    int count = 0;
    while (ss >> word) {
      for (string theWord : {"THE", "AND", "OF"})
        if (word == theWord) return true;

      count++;
    }
    return count >= 4;
  }
};