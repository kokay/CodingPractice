#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Monster {
  int life;
  int damege;
  double priority;
  static bool sortCriteria(const Monster m1, const Monster m2) {
    return m1.priority < m2.priority;
  }
};

class OneFight {
public:
  int monsterKilling(vector<int> life, vector<int> damage, int yourDamege) {
    vector<Monster> monsters;
    int totalDamege = 0;
    for (int i = 0; i < life.size(); ++i) {
      monsters.push_back({ life[i], damage[i], damage[i] / ceil(life[i] / double(yourDamege)) });
      totalDamege += damage[i];
    }

    sort(monsters.begin(), monsters.end(), Monster::sortCriteria);
    int playerLife = 1;
    while (!monsters.empty()) {
      playerLife += totalDamege;
      monsters.back().life -= yourDamege;
      if (monsters.back().life <= 0) {
        totalDamege -= monsters.back().damege;
        monsters.pop_back();
      }
    }
    return playerLife;
  }
};

class OneFight2 {
public:
  int monsterKilling(vector<int> life, vector<int> damage, int yourDamege) {
    int minimumLife = 1, totalDamage = 0;
    vector<pair<double, double>> monsters;
    for (int i = 0; i < life.size(); ++i) {
      monsters.push_back({ life[i], damage[i] });
      totalDamage = damage[i];
    }

    sort(monsters.begin(), monsters.end(), BestOrderToKill(yourDamege));
    for (int i = 0; i < monsters.size(); ++i) {
      while (monsters[i].first > 0) {
        minimumLife += totalDamage;
        monsters[i].first -= yourDamege;
      }
      totalDamage -= monsters[i].second;
    }
    return minimumLife;
  }

private:
  struct BestOrderToKill {
    int yourDamage;
    BestOrderToKill(int damage) : yourDamage(damage) {}
    bool operator() (const pair<double, double>& m1, const pair<double, double>& m2) {
      int numAttackNeededM1 = ceil(m1.first / yourDamage);
      int numAttackNeededM2 = ceil(m2.first / yourDamage);

      return (m1.second / numAttackNeededM1) > (m2.second / numAttackNeededM2);
    }
  };
};