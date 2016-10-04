#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Glossary {
public:
  vector<string> buildGlossary(vector<string> items) {
    vector<string> glossaryLeft, glossaryRight;
    sort(items.begin(), items.end());
    for (int i = 0; i < items.size(); ++i) {
      if (toupper(items[i].front()) < 'N') {
        if (i > 0 && toupper(items[i - 1].front()) == toupper(items[i].front())) {
          glossaryLeft.push_back("  " + items[i] + string(19 - 2 - items[i].size(), ' '));
        } else {
          glossaryLeft.push_back(string(1, toupper(items[i].front())) + string(18, ' '));
          glossaryLeft.push_back(string(19, '-'));
          glossaryLeft.push_back("  " + items[i] + string(19 - 2 - items[i].size(), ' '));
        }
      } else {
        if (i > 0 && toupper(items[i - 1].front()) == toupper(items[i].front())) {
          glossaryRight.push_back(items[i] + string(19 - 2 - items[i].size(), ' '));
        } else {
          glossaryRight.push_back(string(1, toupper(items[i].front())) + string(18, ' '));
          glossaryRight.push_back(string(19, '-'));
          glossaryRight.push_back("  " + items[i] + string(19 - 2 - items[i].size(), ' '));
        }
      }
    }
    vector<string> glossary;
    if (glossaryLeft.size() >= glossaryRight.size()) {
      for (int i = 0; i < glossaryLeft.size(); ++i) {
        if (i < glossaryRight.size()) glossary.push_back(glossaryLeft[i] + "  " + glossaryRight[i]);
        else glossary.push_back(glossaryLeft[i]);
      }
    } else {
      for (int i = 0; i < glossaryRight.size(); ++i) {
        if (i < glossaryLeft.size()) glossary.push_back(glossaryLeft[i] + "  " + glossaryRight[i]);
        else glossary.push_back(string(21, ' ') + glossaryRight[i]);
      }
    }
    return glossary;
  }
};

//int main() {
//  Glossary glossary;
//  for (string s : glossary.buildGlossary({ "Canada", "France", "Germany", "Italy", "Japan", "Russia", "United Kingdom", "United States" })) {
//    cout << s << endl;
//  }
//
//}