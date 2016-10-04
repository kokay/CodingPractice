#include <iostream>
#include <vector>
#include <string>

using namespace std;

class PalindromeDecoding {
public:
  string decode(string code, vector<int> position, vector<int> length) {
    for (int i = 0; i < position.size(); ++i) {
      string subCode = code.substr(position[i], length[i]);
      code.insert(code.begin() + position[i] + length[i], subCode.rbegin(), subCode.rend());
    }
    return code;
  }
};

//int main() {
//  PalindromeDecoding palindromeDecoding;
//  cout << palindromeDecoding.decode("ab", {0}, {2} ) << endl;
//}