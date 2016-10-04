#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class GoodString {
public:
  string isGood(string s) {
    string ab = "ab";
    if (s.empty()) return "Good";
    if (s.size() < ab.size()) return "Bad";
    if (memo.find(s) != memo.end()) return memo[s];

    for (int i = 0; i <= s.size() - ab.size(); ++i) {
      string sTmp = s;
      if (s.substr(i, ab.size()) == ab) {
        sTmp.erase(i, ab.size());
        if (isGood(sTmp) == "Good") {
          memo[sTmp] = "Good";
          return "Good";
        }
      }
    }
    memo[s] = "Bad";
    return "Bad";
  }

  string isGood2(string s) {
    size_t idx;
    while ((idx = s.find("ab")) != string::npos) {
      s.replace(idx, 2, "");
    }
    return s.empty() ? "Good" : "Bad";
  }
  
private:
  unordered_map<string, string> memo;
};