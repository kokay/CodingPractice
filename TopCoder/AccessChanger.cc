#include <iostream>
#include <string>
#include <vector>

using namespace std;

class AccessChanger {
public:
  vector<string> convert(vector<string> program) {
    for (int i = 0; i < program.size(); ++i) 
      program[i] = convertHelper(program[i]);
    return program;
  }

  string convertHelper(string line) {
    size_t idx;
    while ((idx = line.find("->")) != string::npos) {
      if (line.substr(0, idx).find("//") != string::npos)
        return line;
      line.replace(idx, 2, ".");
    }
    return line;
  }

  vector<string> convert2(vector<string> program) {
    for (string& line : program) {
      for (int i = 0; i < line.size(); ++i) {
        if (line[i - 1] == '/' && line[i] == '/') break;
        if (line[i - 1] == '-' && line[i] == '>') 
          line.replace(i - 1, 2, ".");
      }
    }
    return program;
  }
};