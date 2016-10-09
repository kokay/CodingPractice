#include <iostream>
#include <vector>
#include <string>

using namespace std;

class PrefixCode {
public:
  string isOne(vector<string> words) {
    for (int i = 0; i < words.size(); ++i) {
      for (int j = 0; j < words.size(); ++j) {
        if (i != j && words[i] == words[j].substr(0, words[i].size()))
          return "No, " + to_string(i);
      }
    }
    return "Yes";
  }
};

//int main() {
//  PrefixCode p;
//  cout << p.isOne({ "10001", "011", "100", "001", "10" }
//  ) << endl;
//}