// !!
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class SMSLanguage {
public:
  string translate(string text) {
    text.erase(remove(text.begin(), text.end(), '.'), text.end());
    text.erase(remove(text.begin(), text.end(), ','), text.end());
    text.erase(remove(text.begin(), text.end(), '?'), text.end());
    text.erase(remove(text.begin(), text.end(), '!'), text.end());
    for (int i = 0; i < text.size(); ++i) text[i] = tolower(text[i]);
    size_t idx;
    while ((idx = text.find("and")) != string::npos) text.replace(idx, 3, "&");
    while ((idx = text.find("ate")) != string::npos) text.replace(idx, 3, "8");
    while ((idx = text.find("at")) != string::npos)  text.replace(idx, 2, "@");
    while ((idx = text.find("you")) != string::npos) text.replace(idx, 3, "U");
    return text;
  }

  string translate2(string text) {
    for (int i = 0; i < text.size(); ++i)
      if (text[i] == '.' || text[i] == ',' || text[i] == '?' || text[i] == '!')
        text[i] = '#';

    text.erase(remove(text.begin(), text.end(), '#'), text.end());
    for (int i = 0; i < text.size(); ++i) text[i] = tolower(text[i]);
    size_t idx;
    while ((idx = text.find("and")) != string::npos) text.replace(idx, 3, "&");
    while ((idx = text.find("ate")) != string::npos) text.replace(idx, 3, "8");
    while ((idx = text.find("at")) != string::npos)  text.replace(idx, 2, "@");
    while ((idx = text.find("you")) != string::npos) text.replace(idx, 3, "U");
    return text;
  }
  
  string translate3(string text) {
    size_t idx;
    while ((idx = text.find(",")) != string::npos) text.replace(idx, 1, "");
    while ((idx = text.find(".")) != string::npos) text.replace(idx, 1, "");
    while ((idx = text.find("?")) != string::npos) text.replace(idx, 1, "");
    while ((idx = text.find("!")) != string::npos) text.replace(idx, 1, "");
    for (int i = 0; i < text.size(); ++i) text[i] = tolower(text[i]);
    while ((idx = text.find("and")) != string::npos) text.replace(idx, 3, "&");
    while ((idx = text.find("ate")) != string::npos) text.replace(idx, 3, "8");
    while ((idx = text.find("at")) != string::npos)  text.replace(idx, 2, "@");
    while ((idx = text.find("you")) != string::npos) text.replace(idx, 3, "U");
    return text;
  }
};

//int main() {
//  SMSLanguage s;
//  cout << s.translate2(
//    "What is the weather like today?"
//  ) << endl;
//}
