#include  <iostream>
#include  <vector>
#include  <sstream>
#include  <algorithm>

using namespace std;

struct Name {
  string first, last;
  static bool sort(Name& n1, Name& n2) {
    return n1.last < n2.last;
  }
};

class ClientsList {
public:
  vector<string> dataCleanup(vector<string> names) {
    vector<Name> formated;
    string s1, s2;
    for (string name : names) {
      stringstream ss(name);
      ss >> s1 >> s2;
      if (s1.back() == ',') formated.push_back({ s2, s1.substr(0, s1.size() - 1) });
      else formated.push_back({ s1, s2 });
    }
    sort(formated.begin(), formated.end(), Name::sort);

    vector<string> ret;
    for (int i = 0; i < formated.size(); ++i)
      ret.push_back(formated[i].first + " " + formated[i].last);

    return ret;
  }
};