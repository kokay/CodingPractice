#include <iostream>
#include <vector>

using namespace std;

class SpiralRoute {
public:
  vector<int> thronePosition(int width, int length) {
    vector<vector<bool>> palace(length, vector<bool>(width, false));
    int y = 0, x = -1;
    bool move = true;
    while (move) {
      move = false;
      while (x + 1 < palace[y].size() && !palace[y][x + 1]) {
        palace[y][++x] = true;
        move = true;
      }
      while (y + 1 < palace.size() && !palace[y + 1][x]) {
        palace[++y][x] = true;
        move = true;
      }
      while (x - 1 >= 0 && !palace[y][x - 1]) {
        palace[y][--x] = true;
        move = true;
      }
      while (y - 1 >= 0 && !palace[y - 1][x]) {
        palace[--y][x] = true;
        move = true;
      }
    }
    return vector<int>({ x, y });
  }
};