#include <iostream>
#include <vector>

using namespace std;

class Shuffling {
public:
  int position(int cards, vector<int> shuffle) {
    vector<bool> deck(cards, false), bottom, top;
    deck[0] = true;
    for (int i = 0; i < shuffle.size(); ++i) {
      bottom = vector<bool>(deck.begin(), deck.begin() + cards / 2);
      top = vector<bool>(deck.begin() + cards / 2, deck.end());

      if (shuffle[i] > 0) deck = makeDeck(bottom, top, abs(shuffle[i]));
      else				  deck = makeDeck(top, bottom, abs(shuffle[i]));
    }

    for (int i = 0; i < cards; ++i)
      if (deck[i]) return i;
    return -1;
  }
private:
  vector<bool> makeDeck(vector<bool> bottom, vector<bool> top, int shuffle) {
    vector<bool> deck;
    int bottomIdx = 0, topIdx = 0;
    for (; bottomIdx < shuffle; ++bottomIdx)
      deck.push_back(bottom[bottomIdx]);

    while (bottomIdx < bottom.size()) {
      deck.push_back(top[topIdx++]);
      deck.push_back(bottom[bottomIdx++]);
    }

    for (; topIdx < top.size(); ++topIdx) {
      deck.push_back(top[topIdx]);
    }
    return deck;
  }
};