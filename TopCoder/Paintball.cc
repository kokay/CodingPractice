#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct Player {
  string name;
  int score;
  static bool sortPlayer(const Player& p1, const Player& p2) {
    if (p1.score == p2.score) return p1.name < p2.name;
    else return p1.score > p2.score;
  }
};

struct Team {
  string name;
  int totalScore;
  vector<Player> players;
  static bool sortTeam(const Team& t1, const Team& t2) {
    if (t1.totalScore == t2.totalScore) return t1.name < t2.name;
    else return t1.totalScore > t2.totalScore;
  }
};

class Paintball {
public:
  vector<string> getLeaderboard(vector<string> players, vector<string> messages) {
    vector<Team> teams = getTeams(players, messages);
    sort(teams.begin(), teams.end(), Team::sortTeam);
    for (int i = 0; i < teams.size(); ++i)
      sort(teams[i].players.begin(), teams[i].players.end(), Player::sortPlayer);

    return getOutput(teams);
  }

private:
  vector<Team> getTeams(vector<string> players, vector<string> messages) {
    vector<Team> teams;
    unordered_map<string, int> memo;
    string teamName, playerName;
    for (int i = 0; i < players.size(); ++i) {
      stringstream ss(players[i]);
      ss >> playerName >> teamName;
      vector<Team>::iterator team;
      if ((team = find_if(teams.begin(), teams.end(), [&teamName](const Team& t) {
        return t.name == teamName;})) != teams.end()) {
        team->players.push_back({ playerName, 0 });
        memo[playerName] = team - teams.begin();
      }
      else {
        teams.push_back({ teamName, 0, vector<Player>(1,{ playerName, 0 }) });
        memo[playerName] = teams.end() - teams.begin() - 1;
      }
    }

    string playerName1, splattered, playerName2;
    for (int i = 0; i < messages.size(); ++i) {
      stringstream ss(messages[i]);
      ss >> playerName1 >> splattered >> playerName2;
      if (memo[playerName1] == memo[playerName2]) {
        find_if(teams[memo[playerName1]].players.begin(), teams[memo[playerName1]].players.end(), [&playerName1](const Player& p) {
          return p.name == playerName1; })->score--;
        teams[memo[playerName1]].totalScore--;
      }
      else {
        find_if(teams[memo[playerName1]].players.begin(), teams[memo[playerName1]].players.end(), [&playerName1](const Player& p) {
          return p.name == playerName1; })->score++;
        teams[memo[playerName1]].totalScore++;
        find_if(teams[memo[playerName2]].players.begin(), teams[memo[playerName2]].players.end(), [&playerName2](const Player& p) {
          return p.name == playerName2; })->score--;
        teams[memo[playerName2]].totalScore--;
      }
    }
    return teams;
  }

  vector<string> getOutput(vector<Team>& teams) {
    vector<string> output;
    for (int i = 0; i < teams.size(); ++i) {
      output.push_back(teams[i].name + " " + to_string(teams[i].totalScore));
      for (auto player : teams[i].players)
        output.push_back("  " + player.name + " " + to_string(player.score));
    }
    return output;
  }
};