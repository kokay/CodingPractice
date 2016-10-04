#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Animation {
public:
  vector<string> animate(int speed, string init) {
    vector<string> animation;
    string currentState = init;
    while (hasParticles(currentState)) {
      animation.push_back(convert(currentState));
      currentState = getNextState(speed, currentState);
    }
    animation.push_back(currentState);
    return animation;
  }

private:
  bool hasParticles(string& currentState) {
    for (char c : currentState) {
      if (c == 'L' || c == 'R' || c == 'B')
        return true;
    }
    return false;
  }

  string convert(string& currentState) {
    string state;
    for (char c : currentState) {
      if (c == 'L' || c == 'R' || c == 'B')
        state.push_back('X');
      else
        state.push_back('.');
    }
    return state;
  }

  string getNextState(int speed, string& currentState) {
    string nextState(currentState.size(), '.');
    for (int i = 0; i < currentState.size(); ++i) {
      if ((currentState[i] == 'L' || currentState[i] == 'B') && i - speed >= 0) {
        if (nextState[i - speed] == '.') nextState[i - speed] = 'L';
        else nextState[i - speed] = 'B';
      }
      
      if ((currentState[i] == 'R' || currentState[i] == 'B') && i + speed < nextState.size()) {
        if (nextState[i + speed] == '.') nextState[i + speed] = 'R';
        else nextState[i + speed] = 'B';
      }
    }
    return nextState;
  }
};

//int main() {
//  Animation animation;
//  for (string state : animation.animate(3, "RR..LRL")) {
//    cout << state << endl;
//  }
//}