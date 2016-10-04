#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class SubstitutionCipher {
public:
  string decode(string a, string b, string y) {
    vector<char> t(26, '?');
    vector<bool> checked(26, false);
    for (int i = 0; i < b.size(); ++i) {
      t[b[i] - 'A'] = a[i];
      checked[a[i] - 'A'] = true;
    }

    auto it = find(t.begin(), t.end(), '?');
    if(it != t.end() && count(t.begin(), t.end(), '?') == 1)
      for (int i = 0; i < 26; ++i) 
        if (!checked[i]) { *it = i + 'A'; break; }

    string x;
    for (int i = 0; i < y.size(); ++i) {
      if (t[y[i]] == '?') return "";
      x.push_back(t[y[i] - 'A']);
    }
    return x;
  }
};

//int main() {
//  SubstitutionCipher substitutionChipher;
//  string myAnswer = substitutionChipher.decode("THEQUICKBROWNFOXJUMPSOVERTHELAZYHOG", "UIFRVJDLCSPXOGPYKVNQTPWFSUIFMBAZIPH", "DIDYOUNOTICESKIPPEDLETTERDDD");
//  string answer = "CHCXNTMNSHBDRJHOODCKDSSDQCCC";
//  if (myAnswer == answer) cout << "Correct" << endl;
//  else cout << "Wrong" << endl; 
//}