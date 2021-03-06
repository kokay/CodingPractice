#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

struct Info {
  int y, x, cost, bombs;
  bool operator<(const Info& rhs) const {
    return cost > rhs.cost;
  }
};
class BombMan {
public:
  int shortestPath(vector<string> maze, int bombs) {
    bool vis[50][50][101];
    memset(vis, false, sizeof(vis));
    int startY = 0, startX = 0;
    for (int i = 0; i < maze.size(); ++i)
      for (int j = 0; j < maze[i].size(); ++j)
        if (maze[i][j] == 'B') {
          startY = i;
          startX = j;
        }

    int dy[4] = { 1, 0, -1, 0 };
    int dx[4] = { 0, 1, 0, -1 };
    priority_queue<Info> pq;
    pq.push({ startY, startX, 0, bombs });

    while (!pq.empty()) {
      Info p = pq.top(); pq.pop();
      if (maze[p.y][p.x] == 'E') return p.cost;
      if (vis[p.y][p.x][p.bombs]) continue;

      vis[p.y][p.x][p.bombs] = true;
      for (int i = 0; i < 4; ++i) {
        int newY = p.y + dy[i], newX = p.x + dx[i];
        if (newY < 0 || newY >= maze.size() || newX < 0 || newX >= maze[newY].size()) continue;

        if (maze[newY][newX] == '#')
          if (p.bombs >= 1) pq.push({ newY, newX, p.cost + 3, p.bombs - 1 });
        else pq.push({ newY, newX, p.cost + 1, p.bombs });
      }
    }
    return -1;
  }
};
//int main() {
//  BombMan bm;
//  cout << bm.shortestPath(
//  { "B#################################################", "##################################################", "###########.######################################", "##################################.###############", "##################################################", "##################################################", "##########################.#######################", "##################################################", "####################.#############################", "##################################################", "##################################################", "##################################################", "###############.##############.###################", "##################################################", "##################################################", "##################################################", "##########.#######################################", "########################################.#########", "##################################################", "##################################################", "#####.########################.###################", "##################################################", "##################################################", "##################.#############.#################", "##########.#######################################", "##################################################", "#######################################.##########", "##################################################", "##################################################", "##################################################", "#########################################.########", "#########.###########.############################", "##################################################", "###########################################.######", "#############.####################################", "#########################################.########", "##################################################", "####.#############################################", "##################################################", "########################################.#########", "############.#####################################", "##################################################", "##################################################", "##################################################", "############################.#####.###############", "#########.########################################", "##################################################", "##################################################", "##################################################", "#################################################E" }, 90) << endl;
}