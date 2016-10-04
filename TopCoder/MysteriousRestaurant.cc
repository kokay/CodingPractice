#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MysteriousRestaurant {
public:

  int maxDays2(vector<string> prices, int budget) {
    return tryAll(prices, budget, 0, vector<int>(7, -1));
  }

  int INF = 10000000;
  int tr(char c) {
    if (isdigit(c)) return  0 + (c - '0');
    if (isupper(c)) return 10 + (c - 'A');
    if (islower(c)) return 36 + (c - 'a');
    return INF;
  }

  int maxDays(vector <string> prices, int budget) {
    int M = prices.size(), N = prices[0].size();
    int ans = 0;
    int days;
    int i, j, x;
    vector<int> memo(prices.size() + 1, 0);
    vector<int> memo2(prices.size() + 1, 0);

    for (days = 1; days <= M; ++days) {
      int sum = 0;
      for (i = 0; i < 7; ++i) {
        int sho = INF;
        for (x = 0; x < N; ++x) {
          int tmp = 0;
          for (j = i; j < days; j += 7) {
            memo[days]++;
            tmp += tr(prices[j][x]);
          }
          sho = min(sho, tmp);
        }
        sum += sho;
      }
      if (sum <= budget) {
        ans = max(ans, days);
      }
    }

    int total = 0;
    for (int i = 1; i <= prices.size(); ++i) {
      cout << i << " : " << memo[i] << " sho :" << memo2[i] << endl;
      total += memo[i];
    }
    cout << "total : " << total << endl;

    return ans;

  }
private:
  int tryAll(vector<string> prices, int budget, int days, vector<int> selectedDishes) {
    if (budget < 0) return days - 1;
    if (days == prices.size()) return days;

    int best = 0, newBudget;
    if (selectedDishes[days % 7] != -1) {
        newBudget = budget - getPrice(prices[days][selectedDishes[days % 7]]);
        return max(best, tryAll(prices, newBudget, days + 1, selectedDishes));
    }

    for (int i = 0; i < prices[days].size(); ++i) {
      selectedDishes[days] = i;
      newBudget = budget - getPrice(prices[days][i]);
      best = max(best, tryAll(prices, newBudget, days + 1, selectedDishes));
    }
    return best;
  }

  int getPrice(char p) {
    if (p >= '0' && p <= '9') return p - '0';
    if (p >= 'A' && p <= 'Z') return p - 'A' + 10;
    return p - 'a' + 36;
  }
};

//int main() {
//  MysteriousRestaurant mysteriousRestaurant;
//  cout << mysteriousRestaurant.maxDays({ "jVFtB9WxMCnBGt5lr74sT8DfLPu0INbf4Dfu30QIxbWkhQCT54", "qQ2vrxcR5Kb0ZwR0ScwLWDDQjaNSw5gV1qGEdBevYH0fgsUxzK", "WuKQH5AEfrQJdVDqECKC3z4vMA80ACHrCLSVFf9vfhYa7sAYHG", "gf6X9wUAMJPWkKndHZa0lMZ9usJ3LVoJiK76Oz65dNY89zMan2", "YkgAQUNLiCR5OOI3NV5g0krvAMbnDVEj9FLUphDBuo1YR6Onpl", "diPruDGNVBs52TdjWXX6QLBQ7vsnGUvhJEembz48F7B0n04j0O", "n5IDB5PZN28sttZXgzTOUv66O0Rmy12vmeZbv3l3OcsojHhpHm", "y1RgP8jN2ouFBX5LmrIZPB7Cs9YfBP26d9XLmtp0cAyVa5iPr3", "wb0i28FaRw7Uk0ys8UeiVJogyR3Opy2CtUDi16gFXfYe9jyYEC", "efS7PJK07H3X0HDtLF9iOvNFVQB6j16uDeMPiz6omUoDLWTztH", "l4HU1aCAhbPWRnZNx2v037JUqEyGPsQhLgkVIlgO4VKcsp57Hs", "PTFPb7TKUMwXh7KwfEeyEdnfOKHg2Ux32qTgHDHCsL5SYYGedj", "Jb7aVFcq3WAAwYtwKv8qs1VNDFosIEbjAevj4AHNZ6DXIyBZSG", "3eydxNv64zSsCHQoymqX0H10vJ01dj7AL59tZZXyBlfk6jOnpJ", "9RZvZlJ05sKnTz9NI7tzmOM1RpSXiOgqkrg95mm0OsIPRJIvan", "I17S4scEyolrVH0YnX6tkkqeI6yrGETuGXNHqqzSJbHpDeiUUl", "vVwgOyH1EXfUtmhNAtHwLfbNxNPmDupIxJEqbb4P2Q6ja3LdYZ", "YAKoeMSHWtzOZSYitEV7F0d4HyT7PVVFjOc8yTHUSSOX1QScOj", "KNU0pAneKloc3S8CYcymZE5sBaI1VkKripbrytSEWRyb6Ce935", "d6a4wYAmxhDDC0D9EbamsoKOSVcMdGGvzx0UHENZLvVAYQg12F", "J72kb2TwqC3QDSOPsqKURFYKtUPJnSSgIzOBg50YZ76XUJCTX0", "Zg01TjsKPJKrc9nnCCVuVS9HWwtCeE5NaCvYHIUJOVAqe1ABbS", "Dn7fFV4iiX4lO3pdcBAk6xKDankz9tinrfxAbAXEnYCWHWIh63", "hSF6NyswzoHfomktHBQeQJ4ZvdFSm7JP9u5RbsgW4CMYL8waQ9", "Ifi8fbVZ1JeP1fLqNoPT54lHJyGIJxR4EkafyDhQTrhTLM1ViJ", "k6ukAHkfliF8mKZT7OwDnziwCJ3QGiyiIvrSXDbZE3dIVDUf5T", "bj7l9OhZUKn6tR0RZH0cyPaw64qAAs6dyMWrD4vuvAxLEJqavb", "2atzChAjm3orsoPKoqV77gU06qKROX3ln5UBINhYljV3fSgljb", "OtFodbeuy1baT8iHxYpQ6ToRXh0cHOJowSpdrLKZHCNTWwldh6", "js34Yea7cpDD1jZ0E2iGdHiq91vdaCAYmFMnBklcpI5DBM3pOK", "pbYjhRr0WTdrWGnB9VYl5Q0W5r2JNZDFnLK671S12gJuKOOsbm", "35ByFNvVEj9Qqkqj87a6vLEZH7rE572IBOQv3lIrG3qFC3I7vi", "OaFdtWCugS7tcn8HOT7ZLUs3GEWypQx1U9YqW1GP1DkXp2ZzFx", "2IezIENg67d7NBzMMrptxZILFJlrCuTiOQBgcs2wezuXxd4wDs", "pMprpbQijtOPs8OfcA4mJFoaXaxAqh8BjLgoWlImAhZmnVuaht", "0z0HBUqEJ98jhV4RUUj5I5J6pAlJmXoU8DyiDFuiiO6CGsK6Op", "21IvAhiBPii92WRTf76sMpCALPBlf6PBhrWOlcapvISiOaUMzu", "BatnU0B5iyqOLsXoudXHqdTHI6pqyZ7ctt1R3f3DPDd5dO0ZCv", "tjtcf4SAwQYc0zJHiFtdlheJbJITxYjEgR10eES4aDUOlFF1oh", "38Wf80swyn0AXln2kxHc8ghlrD5xcMJHgFxiHuH1CZwCpPxT8w", "erwPJ6mnCuKGLbNB4GM3Ds4dmIWGXwWiQR9p6L9t1RUyiRJCmt", "KgS1BUJAu7sk1Yq5a9eEaBSgoFbb4FvCXlACsnsoOc712C0VBC", "SljKMUOlzwzHKLnVadbvtanCxIYL5Hd0KnI6G1t5wbvr9dW7t3", "XWZJChIQXi0RjCBOLaa0XXta0jjbSeoNYkyWKRFHNc69iNDpIX", "TwurV7V8zB76Hwl4Z1mbEiYHn6C0dEqB8GZKaXMa8CWwsMmHtL", "pGJIW1bSK9MkKrmAzZtl4Cwe3jPMdG8OFymnENMKXlEoe3NoHn", "4wLoiTXRaOECg5wDdqxw97c62R8qX0SnKih54jfQZeEtNNfMZw", "E8w5cMx6mCsZRtW1fP9PCnyZKeCJvwav1ZPrd1kkTQvahLQvAo", "TwNcNhlz2H6Kb8r9VMwrj8FK5iugW0FGnxDS7Fnq1zSgv63yER", "rvDsel8LdvLMRmyAI4Nl89LqN3Gdua2eXbuTzaEqNAsCO6WfcG" }, 10000) << endl;
//}