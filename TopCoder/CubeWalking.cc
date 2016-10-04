#include <iostream>
#include <vector>
#include <string>

using namespace std;

class CubeWalking {
public:
  string finalPosition(string movement) {
    UP = { -1, 0 }, DOWN = { 1, 0 }, RIGHT = { 0, -1 }, LEFT = { 0, 1 };
    vector<vector<string>> face {
      {"RED",  "BLUE",  "RED"},
      {"BLUE", "GREEN", "BLUE"},
      {"RED",  "BLUE",  "RED"}
    };

    int x = 1, y = 1;
    pair<int, int> direction(UP);
    for (int i = 0; i < movement.size(); ++i) {
      if (movement[i] == 'L' || movement[i] == 'R') {
        direction = getNewDirection(direction, movement[i]);
      } else {
        y = (y + direction.first + 3) % 3;
        x = (x + direction.second + 3) % 3;
      }
    }
    return face[y][x];
  }

private:
  pair<int, int> UP, DOWN, LEFT, RIGHT;

  pair<int, int> getNewDirection(pair<int, int> direction, char movement) {
    if (direction == UP) {
      if (movement == 'L') return LEFT;
      return RIGHT;
    } else if (direction == DOWN) {
      if (movement == 'L') return RIGHT;
      return LEFT;
    } else if (direction == RIGHT) {
      if (movement == 'L') return UP;
      return DOWN;
    } else {
      if (movement == 'L') return DOWN;
      return UP;
    }
  }
};