#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class PaperRockScisQuals {
public:
  int whoPassed(vector<string> players) {
    vector<double> points(players.size(), 0);
    for (int i = 0; i < players.size(); ++i) {
      for (int j = i + 1; j < players.size(); ++j) {
        int iWins = 0, jWins = 0;
        for (int k = 0; k < 5; ++k) {
          if      (players[i][k] == 'P' && players[j][k] == 'R') iWins += 1;
          else if (players[i][k] == 'R' && players[j][k] == 'S') iWins += 1;
          else if (players[i][k] == 'S' && players[j][k] == 'P') iWins += 1;
          else if (players[j][k] == 'P' && players[i][k] == 'R') jWins += 1;
          else if (players[j][k] == 'R' && players[i][k] == 'S') jWins += 1;
          else if (players[j][k] == 'S' && players[i][k] == 'P') jWins += 1;
        }
        if      (iWins > jWins) points[i] += 1;
        else if (iWins < jWins) points[j] += 1;
        else points[i] += 0.5, points[j] += 0.5;
      }
    }

    return max_element(points.begin(), points.end()) - points.begin();
  }
};