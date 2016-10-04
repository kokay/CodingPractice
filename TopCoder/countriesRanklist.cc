#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <map>

using namespace std;

struct Info {
  string country;
  int totalScore;
  int totalContestants;
  int bestRank;
  int worstRank;
};

class CountriesRanklist {
public:
  vector<Info> getTable(vector<string>& knownPoints, int* minimum) {
    vector<Info> table;
    string country, contestant;
    int score;
    for (int i = 0; i < knownPoints.size(); ++i) {
      stringstream ss(knownPoints[i]);
      ss >> country >> contestant >> score;
      *minimum = min(*minimum, score);
      auto it = find_if(table.begin(), table.end(), [&](const Info& i) {return i.country == country; });
      if (it == table.end())
        table.push_back({ country, score, 1, 0, 0 });
      else {
        (*it).totalScore += score;
        (*it).totalContestants += 1;
      }
    }
    return table;
  }

  int getBestRank(vector<Info> table, int idx, int minimum) {
    table[idx].totalScore += (minimum - 1) * (4 - table[idx].totalContestants);
    int count = count_if(table.begin(), table.end(), [&](const Info& i)
    { return i.totalScore > table[idx].totalScore; });
    return count + 1;
  }

  int getWorstRank(vector<Info> table, int idx, int minimum) {
    for (int i = 0; i < table.size(); ++i) {
      if (i != idx)
        table[i].totalScore += (minimum - 1) * (4 - table[i].totalContestants);
    }
    int count = count_if(table.begin(), table.end(), [&](const Info& i)
    { return i.totalScore > table[idx].totalScore; });
    return count + 1;
  }

  vector<string> findPlaces(vector<string> knownPoints) {
    int minimum = 601;
    vector<Info> table = getTable(knownPoints, &minimum);

    for (int i = 0; i < table.size(); ++i) {
      table[i].bestRank = getBestRank(table, i, minimum);
      table[i].worstRank = getWorstRank(table, i, minimum);
    }

    sort(table.begin(), table.end(),
      [](const Info& i1, const Info& i2) {return i1.country < i2.country; });

    vector<string> places;
    for (Info& info : table)
      places.push_back(info.country + " "
        + to_string(info.bestRank) + " " + to_string(info.worstRank));

    return places;
  }
};


//int main() {
//  CountriesRanklist countriesRanklist;
//  for (string& list : countriesRanklist.findPlaces({ "Slovakia Marian 270", "Hungary Istvan 24", "Poland Krzysztof 100",
//    "Hungary Gyula 30", "Germany Tobias 27", "Germany Juergen 27" }
//  )) {
//    cout << list << endl;
//  }
