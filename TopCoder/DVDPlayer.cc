#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class DVDPlayer {
public:
  vector<string> findMovies(vector<string> moviesWatched) {
    string DVDPlayer = " ";
    map<string, string> places;
    for (string movie : moviesWatched) places[movie] = movie;
    string inPlayer = moviesWatched[0];
    places[inPlayer] = DVDPlayer;
    for (int i = 1; i < moviesWatched.size();++i) {
      places[inPlayer] = places[moviesWatched[i]];
      places[moviesWatched[i]] = DVDPlayer;
      inPlayer = moviesWatched[i];
    }

    vector<string> ret;
    for (auto place : places) {
      if (place.first != place.second && place.second != DVDPlayer)
        ret.push_back(place.first + " is inside " + place.second + "'s case");
    }
    return ret;
  }
};