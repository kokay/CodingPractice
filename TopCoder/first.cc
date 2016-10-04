#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <string.h>
#include <iterator>
#include <sstream>

using namespace std;

class Initials {
public:
  string getInitials(string name) {
    istringstream ss(name);
    string ret = "", n;
    while (ss >> n)
      ret += n.front();
    return ret;
  }

private:
};


