#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class CheckFunction {
public:
  int newFunction(string code) {
    static vector<int> memo{ 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
    
    int sum = 0;
    for (char cNum : code) 
      sum += memo[cNum - '0'];

    return sum;
  }
};

//int main() {
//  CheckFunction checkFunction;
//  cout << checkFunction.newFunction("13579") << endl;
//}

