#include <iostream>
#include <string>

using namespace std;

class PrimeSoccer {
public:
  double getProbability(int skillOfTeamA, int skillOfTeamB) {
    int teamA = 0, teamB = 1;
    double probs[2][19][19];
    memset(probs, 0, sizeof(probs));

    probs[teamA][1][0] = (100 - skillOfTeamA) / 100.0;
    probs[teamA][1][1] = skillOfTeamA / 100.0;
    probs[teamB][1][0] = (100 - skillOfTeamB) / 100.0;
    probs[teamB][1][1] = skillOfTeamB / 100.0;

    for (int time = 1; time < 18; ++time) {
      for (int score = 0; score < 18; ++score) {
        if (probs[teamA][time][score] != 0) {
          probs[teamA][time + 1][score + 1] += probs[teamA][time][score] * skillOfTeamA / 100.0;
          probs[teamA][time + 1][score] += probs[teamA][time][score] * (100 - skillOfTeamA) / 100.0;
        }
        if (probs[teamB][time][score] != 0) {
          probs[teamB][time + 1][score + 1] += probs[teamB][time][score] * skillOfTeamB / 100.0;
          probs[teamB][time + 1][score] += probs[teamB][time][score] * (100 - skillOfTeamB) / 100.0;
        }
      }
    }

    double teamATotal = 0, teamBTotal = 0;
    for (int prime : {2, 3, 5, 7, 11, 13, 17}) {
      teamATotal += probs[teamA][18][prime];
      teamBTotal += probs[teamB][18][prime];
    }
    return teamATotal + teamBTotal - teamATotal * teamBTotal;
  }
};

//int main() {
//  PrimeSoccer p;
//  cout << p.getProbability(50, 50) << endl;
//}