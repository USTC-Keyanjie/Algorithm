#include <bits/stdc++.h>

using namespace std;



class FoodRatings {
    struct food {
        string cuisine;
        int rating;
    };
public:
    map<string, food> record;

    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings) {
        int n = foods.size();
        for (int i = 0; i < n; ++i) {
            record[foods[i]].cuisine = cuisines[i];
            record[foods[i]].rating = ratings[i];
        }
    }

    void changeRating(string food, int newRating) {
        record[food].rating = newRating;
    }

    string highestRated(string cuisine) {
        int max_rate = 0;
        string name = "";
        for (auto it = record.begin(); it != record.end(); ++it) {
            if (it->second.cuisine == cuisine && it->second.rating > max_rate) {
                max_rate = it->second.rating;
                name = it->first;
            }
        }
        return name;
    }
};
