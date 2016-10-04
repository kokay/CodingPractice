#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int MAX = 1000000;

class PowerPlants {
public:
  int minCost(vector<string> connectionCost, string plantList, int numPlants) {
    costs = makeCosts(connectionCost); 
    memo = vector<unordered_map<string, int>>(costs.size());

    best = MAX;
    int numWorkingPlants = 0;
    for (int i = 0; i < plantList.size(); ++i)
      if (plantList[i] == 'Y')
        ++numWorkingPlants;

    if (numWorkingPlants == numPlants)
      return 0;

    checkAll(plantList, numPlants - numWorkingPlants, 0);
    return best;
  }

private:
  unordered_map<string, int> memo2;
  int count = 0;
  void checkAll(string& plantList, int reminder, int total) {
    count++;
    if (memo2.find(plantList) != memo2.end() && memo2[plantList] <= total)
      return;
    
    memo2[plantList] = total;
    if (reminder == 0) {
      best = min(best, total);
      return;
    }

    int bestCost;
    for (int i = 0; i < costs.size(); ++i) {
      if (plantList[i] == 'Y')
        continue;
      for (int j = 0; j < costs.size(); ++j) {
        if (plantList[j] == 'Y') {
          plantList[i] = 'Y';
          checkAll(plantList, reminder - 1, total + costs[j][i]);
          plantList[i] = 'N';
        }
      }
    }
  }

  vector<vector<int>> makeCosts(vector<string>& connectionCost) {
    vector<vector<int>> costs(connectionCost.size(), vector<int>(connectionCost.size()));
    for (int i = 0; i < connectionCost.size(); ++i) {
      for (int j = 0; j < connectionCost.size(); ++j)
        costs[i][j] = convert(connectionCost[i][j]);
    }
    return costs;
  }

  int convert(char c) {
    if (c >= '0' && c <= '9')
      return c - '0';
    return c - 'A' + 10;
  }


  int getBestCost(string& plantList, int restartPlant) {
    if (memo[restartPlant].find(plantList) != memo[restartPlant].end())
      return memo[restartPlant][plantList];

    int best = 100;
    for (int i = 0; i < costs.size(); ++i) {
      if (i != restartPlant && plantList[i] == 'Y') {
        best = min(best, costs[i][restartPlant]);
      }
    }
    memo[restartPlant][plantList] = best;
    return best;
  }

  int best;
  vector<vector<int>> costs;
  vector<unordered_map<string, int>> memo;
};

//int main() {
//  PowerPlants powerPlants;
//  cout << powerPlants.minCost({ "ABCDEF1234567890", "ABCDEF1234567890", "ABCDEF1234567890", "ABCDEF1234567890", "ABCDEF1234567890", "ABCDEF1234567890", "ABCDEF1234567890", "ABCDEF1234567890", "ABCDEF1234567890", "ABCDEF1234567890", "ABCDEF1234567890", "ABCDEF1234567890", "ABCDEF1234567890", "ABCDEF1234567890", "ABCDEF1234567890", "ABCDEF1234567890" }, "YNNNNNNNNNNNNNNN", 16) << endl;
//}