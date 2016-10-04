#include <iostream>
#include <math.h>

using namespace std;

class ScrabbleBet {
public:
  double estimate(int trials, int games, int winsNeeded, int winChance) {
    return 1 - pow(getProb(games, 0, winsNeeded, 0, winChance / 100.0), trials);
  }

private:
  double getProb(int games, int currentNumGame, int winNeeded, int currentNumWin, double winProb) {
    if (currentNumWin >= winNeeded) return 0.0;
    if (currentNumGame == games)
        return pow(winProb, currentNumWin) * pow((1 - winProb), games - currentNumWin);

    return getProb(games, currentNumGame + 1, winNeeded, currentNumWin, winProb) + 
      getProb(games, currentNumGame + 1, winNeeded, currentNumWin + 1, winProb);
  }
};