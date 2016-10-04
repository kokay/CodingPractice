#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <sstream>

using namespace std;

struct Point {
  int x, y, z;
};

class LightsCube {
public:
  vector<int> count(int N, vector<string> lights) {
    int cube[40][40][40];
    memset(cube, -1, sizeof(cube));

    queue<Point> q;
    int x, y, z;
    for (int i = 0; i < lights.size();++i) {
      stringstream ss(lights[i]);
      ss >> x >> y >> z;
      cube[y][x][z] = i;
      q.push({ x, y, z });
    }

    vector<int> countLights(lights.size(), 1);
    while (!q.empty()) {
      Point p = q.front();
      q.pop();
      if (p.y - 1 >= 0 && cube[p.y - 1][p.x][p.z] == -1) {
        cube[p.y - 1][p.x][p.z] = cube[p.y][p.x][p.z];
        q.push({ p.x, p.y - 1, p.z });
        countLights[cube[p.y][p.x][p.z]]++;
      }
      if (p.y + 1 < N && cube[p.y + 1][p.x][p.z] == -1) {
        cube[p.y + 1][p.x][p.z] = cube[p.y][p.x][p.z];
        q.push({ p.x, p.y + 1, p.z });
        countLights[cube[p.y][p.x][p.z]]++;
      }
      if (p.x - 1 >= 0 && cube[p.y][p.x - 1][p.z] == -1) {
        cube[p.y][p.x - 1][p.z] = cube[p.y][p.x][p.z];
        q.push({ p.x - 1, p.y, p.z });
        countLights[cube[p.y][p.x][p.z]]++;
      }
      if (p.x + 1 < N && cube[p.y][p.x + 1][p.z] == -1) {
        cube[p.y][p.x + 1][p.z] = cube[p.y][p.x][p.z];
        q.push({ p.x + 1, p.y, p.z });
        countLights[cube[p.y][p.x][p.z]]++;
      }
      if (p.z - 1 >= 0 && cube[p.y][p.x][p.z - 1] == -1) {
        cube[p.y][p.x][p.z - 1] = cube[p.y][p.x][p.z];
        q.push({ p.x, p.y, p.z - 1 });
        countLights[cube[p.y][p.x][p.z]]++;
      }
      if (p.z + 1 < N && cube[p.y][p.x][p.z + 1] == -1) {
        cube[p.y][p.x][p.z + 1] = cube[p.y][p.x][p.z];
        q.push({ p.x, p.y, p.z + 1 });
        countLights[cube[p.y][p.x][p.z]]++;
      }
    }
    return countLights;
  }
};