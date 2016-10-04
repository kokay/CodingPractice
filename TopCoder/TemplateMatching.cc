#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class TemplateMatching {
public:
  string bestMatch(string text, string prefix, string suffix) {
    string result = "";
    int x = -1, y = -1;
    for (int i = 0; i < text.length(); ++i) {
      for (int j = i; j < text.length(); ++j) {
        string s = text.substr(i, j - i + 1);
        int a = min(s.length(), prefix.length());
        while (a > 0) {
          string sSub = s.substr(0, a);
          string preSub = prefix.substr(prefix.size() - a);
          if (s.substr(0, a) == prefix.substr(prefix.length() - a)) {
            break;
          }
          --a;
        }
        int b = min(s.length(), suffix.length());
        while (b > 0) {
          string sSub = s.substr(s.size() - b);
          string preSub = prefix.substr(0, b);
          if (s.substr(s.length() - b) == suffix.substr(0, b)) {
            break;
          }
          --b;
        }
        if ((a + b > x + y) || ((a + b == x + y) && ((a > x) || ((a == x) && (s < result))))) {
          result = s;
          x = a;
          y = b;
        }
      }
    }
    return result;
  }
};

//int main() {
//  TemplateMatching t;
//  //cout << t.bestMatch("cabacbaddadaaddbabccaddaddbdacadbabddbbcdacdcbc", "dbddaddaaadacadabdaadbbcaadddaaaabcbdabadaabcdcdb", "dbddaddaaadacadabdaadbbcaadddaaaabcbdabadaabcdcdb") << endl;
//  //cout << t.bestMatch("something", "awesome", "ingenious") << endl;
//  cout << t.bestMatch("havka", "eto", "papstvo") << endl;
//
//}