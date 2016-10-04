#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class KingSort {
public:
  vector<string> getSortedList(vector<string> kings) {
    sort(kings.begin(), kings.end(), sortCriteria);
    return kings;
  }

private:
  static bool sortCriteria(const string& k1, const string& k2) {
    string k1Name = k1.substr(0, k1.find(' '));
    string k2Name = k2.substr(0, k2.find(' '));
    if (k1Name != k2Name) return k1Name < k2Name;

    string k1Num = k1.substr(k1.find(' ') + 1);
    string k2Num = k2.substr(k2.find(' ') + 1);
    return convert(k1Num) < convert(k2Num);
  }

  static int convert(const string& romanNumeral) {
    vector<string> romans { "L", "XL", "XXX", "XX", "X", "IX", "VIII", "VII", "VI", "V", "IV", "III", "II", "I" };
    vector<int> nums { 50, 40, 30, 20, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    int num = 0, idx = 0;
    while (idx < romanNumeral.size()) {
      for (int i = 0; i < romans.size(); ++i) {
        if (romanNumeral.substr(idx, romans[i].size()) != romans[i]) continue;

        num += nums[i];
        idx += romans[i].size();
        break;
      }
    }
    return num;
  }
};