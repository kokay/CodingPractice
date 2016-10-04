#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Meal {
  int idx, protein, carbs, fat, calorie;
  static bool carbsComparison(Meal m1, Meal m2) { return m1.carbs < m2.carbs; }
  static bool proteinComparison(Meal m1, Meal m2) { return m1.protein < m2.protein; }
  static bool fatComparison(Meal m1, Meal m2) { return m1.fat < m2.fat; }
  static bool calorieComparison(Meal m1, Meal m2) { return m1.calorie < m2.calorie; }
};

class HealthFood {
public:
  vector<int> selectMeals(vector<int> protein, vector<int> carbs, vector<int> fat, vector<string> dietPlans) {
    vector<int> selectedMeals;
    vector<Meal> allCandidates = getAllCandidates(protein, carbs, fat);
    for (int i = 0; i < dietPlans.size(); ++i) {
      vector<Meal> candidates =  allCandidates;
      for (int j = 0; j < dietPlans[i].size(); ++j) {
        candidates = getNewCandidates(candidates, dietPlans[i][j]);
        if (candidates.size() == 1) break;
      }
      selectedMeals.push_back(candidates.front().idx);
    }
    return selectedMeals;
  }

private:
  vector<Meal> getAllCandidates(vector<int> protein, vector<int> carbs, vector<int> fat) {
    vector<Meal> candidates;
    for (int i = 0; i < protein.size(); ++i)
      candidates.push_back({ i, protein[i], carbs[i], fat[i], protein[i] * 5 + carbs[i] * 5 + fat[i] * 9});
    return candidates;
  }

  vector<Meal> getNewCandidates(vector<Meal> candidates, char type) {
    vector<Meal> newCandidates;
    int value = 0;
    switch (type) {
    case 'C':
      value = max_element(candidates.begin(), candidates.end(), Meal::carbsComparison)->carbs;
      for (int i = 0; i < candidates.size(); ++i) {
        if (candidates[i].carbs == value)
          newCandidates.push_back(candidates[i]);
      }
      break;
    case 'c':
      value = min_element(candidates.begin(), candidates.end(), Meal::carbsComparison)->carbs;
      for (int i = 0; i < candidates.size(); ++i) {
        if (candidates[i].carbs == value)
          newCandidates.push_back(candidates[i]);
      }
      break;
    case 'P':
      value = max_element(candidates.begin(), candidates.end(), Meal::proteinComparison)->protein;
      for (int i = 0; i < candidates.size(); ++i) {
        if (candidates[i].protein == value)
          newCandidates.push_back(candidates[i]);
      }
      break;
    case 'p':
      value = min_element(candidates.begin(), candidates.end(), Meal::proteinComparison)->protein;
      for (int i = 0; i < candidates.size(); ++i) {
        if (candidates[i].protein == value)
          newCandidates.push_back(candidates[i]);
      }
      break;
    case 'F':
      value = max_element(candidates.begin(), candidates.end(), Meal::fatComparison)->fat;
      for (int i = 0; i < candidates.size(); ++i) {
        if (candidates[i].fat == value)
          newCandidates.push_back(candidates[i]);
      }
      break;
    case 'f':
      value = min_element(candidates.begin(), candidates.end(), Meal::fatComparison)->fat;
      for (int i = 0; i < candidates.size(); ++i) {
        if (candidates[i].fat == value)
          newCandidates.push_back(candidates[i]);
      }
      break;
    case 'T':
      value = max_element(candidates.begin(), candidates.end(), Meal::calorieComparison)->calorie;
      for (int i = 0; i < candidates.size(); ++i) {
        if (candidates[i].calorie == value)
          newCandidates.push_back(candidates[i]);
      }
      break;
    case 't':
      value = min_element(candidates.begin(), candidates.end(), Meal::calorieComparison)->calorie;
      for (int i = 0; i < candidates.size(); ++i) {
        if (candidates[i].calorie == value)
          newCandidates.push_back(candidates[i]);
      }
      break;
    }
    return newCandidates;
  }
};