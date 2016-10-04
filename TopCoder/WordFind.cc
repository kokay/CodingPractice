#include <iostream>
#include <vector>
#include <string>

using namespace std;

class WordFind {
public:
  vector<string> findWords(vector<string> grid, vector<string> wordList) {
    vector<string> wordPositions;
    for (int i = 0; i < wordList.size(); ++i) {
      wordPositions.push_back(findPosition(grid, wordList[i]));
    }
    return wordPositions;
  }

private:
  string findPosition(vector<string>& grid, string word) {
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[i].size(); ++j) {
        if (findWord(grid, i, j, word))
          return to_string(i) + " " + to_string(j);
      }
    }
    return "";
  }

  bool findWord(vector<string>& grid, int row, int col, string word) {
    bool found = true;
    for (int i = 0; i < word.size(); ++i) {
      if (row + i >= grid.size() || word[i] != grid[row + i][col]) {
        found = false;
        break;
      }
    }
    if (found) return true;
    found = true;
    for (int i = 0; i < word.size(); ++i) {
      if (col + i >= grid[0].size() || word[i] != grid[row][col + i]) {
        found = false;
        break;
      }
    }
    if (found) return true;
    found = true;
    for (int i = 0; i < word.size(); ++i) {
      if (row + i >= grid.size() || col + i >= grid[0].size() || word[i] != grid[row + i][col + i]) {
        found = false;
        break;
      }
    }
    if (found) return true;
    return false;
  }
};