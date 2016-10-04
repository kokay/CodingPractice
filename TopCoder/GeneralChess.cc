#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <set>
#include <iterator>

using namespace std;

struct Place {
  int x, y;
  bool operator<(const Place& rhs) const {
    if (this->x != rhs.x) return this->x < rhs.x;
    return this->y < rhs.y;
  }
};

class GeneralChess {
public:
  vector<string> attackPositions(vector<string> pieces) {
    set<Place> s1, s2, intersect;
    insertThreatenedPositions(s1, pieces[0]);
    for (int i = 1; i < pieces.size(); ++i) {
      s2.clear(); intersect.clear();
      insertThreatenedPositions(s2, pieces[i]);
      set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(),
        inserter(intersect, intersect.begin()));
      s1 = intersect;
    }

    vector<string> returnPositions;
    for (Place p : s1)
      returnPositions.push_back(to_string(p.x) + "," + to_string(p.y));
    return returnPositions;
  }

private:
  void insertThreatenedPositions(set<Place>& s, string& piece) {
    int x, y;
   // sscanf(piece.c_str(), "%d,%d", &x, &y);
    s.insert({ x + 2, y + 1 });
    s.insert({ x + 2, y - 1 });
    s.insert({ x + 1, y + 2 });
    s.insert({ x + 1, y - 2 });
    s.insert({ x - 2, y + 1 });
    s.insert({ x - 2, y - 1 });
    s.insert({ x - 1, y + 2 });
    s.insert({ x - 1, y - 2 });
  }
};