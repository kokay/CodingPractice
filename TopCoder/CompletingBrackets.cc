#include <stack>
#include <string>

using namespace std;

class CompletingBrackets {
public:
  string complete(string text) {
    string result = text;
    stack<char> st;
    for (int i = 0; i < text.size(); ++i) {
      if (text[i] == ']') {
        if(st.empty()) result.insert(result.begin(), '[');
        else st.pop();
      }
      else {
        st.push('[');
      }
    }
    result += string(st.size(), ']');
    return result;
  }
};