#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class PatternOptimizer {
public:
  string optimize(string pattern) {
    string optimizedPattern, block;
    size_t idx = 0, lastBlockIdx;
    while (idx < pattern.size()) {
      if (pattern[idx] != '*' && pattern[idx] != '?') {
        lastBlockIdx = pattern.substr(idx).find_first_of("*?");
        block = pattern.substr(idx, lastBlockIdx);
        optimizedPattern += block;
      }
      else {
        lastBlockIdx = pattern.substr(idx).find_first_not_of("*?");
        block = pattern.substr(idx, lastBlockIdx);
        if (block.find("*") != string::npos) optimizedPattern += "*";
        optimizedPattern += string(count(block.begin(), block.end(), '?'), '?');
      }
      idx += block.size();
    }
    return optimizedPattern;
  }
};

//int main() {
//  PatternOptimizer po;
//  cout << po.optimize("suysq*kuuhyumei??c*yytqma?w*gck***?*u?*xeys**a?*z*") << endl;
//  cout << "suysq*kuuhyumei??c*yytqma?w*gck*?u*?xeys*a*?z*" << endl;
//}