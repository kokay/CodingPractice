#include <iostream>
#include <vector>
#include <string>

using namespace std;

class HuffmanDecoding {
public:
  string decode(string archive, vector<string> dictionary) {
    string decodedArchive;
    size_t idx = 0;
    while (idx < archive.size()) {
      for (int i = 0; i < dictionary.size();++i) {
        if (archive.substr(idx, dictionary[i].size()) != dictionary[i])
          continue;
        
        idx += dictionary[i].size();
        decodedArchive.push_back('A' + i);
        break;
      }
    }
    return decodedArchive;
  }
};

//int main() {
//  HuffmanDecoding huffmanDecoding;
//  cout << huffmanDecoding.decode("001101100101100110111101011001011001010", 
//        {"110", "011", "10", "0011", "00011", "111", "00010", "0010", "010", "0000"}) << endl;
//}