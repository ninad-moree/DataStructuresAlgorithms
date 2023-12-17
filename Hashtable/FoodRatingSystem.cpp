/*
    Design a food rating system that can do the following:
    Modify the rating of a food item listed in the system.
    Return the highest-rated food item for a type of cuisine in the system.
    Implement the FoodRatings class:

    FoodRatings(String[] foods, String[] cuisines, int[] ratings) Initializes the system. 
    The food items are described by foods, cuisines and ratings, all of which have a length of n.
    foods[i] is the name of the ith food,
    cuisines[i] is the type of cuisine of the ith food, and
    ratings[i] is the initial rating of the ith food.

    void changeRating(String food, int newRating) Changes the rating of the food item with the name food.

    String highestRated(String cuisine) Returns the name of the food item that has the highest rating for the given type of cuisine. 
    If there is a tie, return the item with the lexicographically smaller name.

    Note that a string x is lexicographically smaller than string y if x comes before y in dictionary order, that is, 
    either x is a prefix of y, or if i is the first position such that x[i] != y[i], then x[i] comes before y[i] in alphabetic order.

    Input
    ["FoodRatings", "highestRated", "highestRated", "changeRating", "highestRated", "changeRating", "highestRated"]
    [[["kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"], ["korean", "japanese", "japanese", "greek", "japanese", "korean"], 
    [9, 12, 8, 15, 14, 7]], ["korean"], ["japanese"], ["sushi", 16], ["japanese"], ["ramen", 16], ["japanese"]]
    
    Output
    [null, "kimchi", "ramen", null, "sushi", null, "ramen"]
*/

#include<bits/stdc++.h>
using namespace std;

class FoodRatings {
    using item = pair<int, string>; // (rating, food), (rating, cuisine)
    unordered_map<string, set<item>> Rated;
    unordered_map<string, item> mp;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            string food = foods[i], cuisine = cuisines[i];
            int rating = ratings[i];
            mp[food] = {-rating, cuisine}; 
            Rated[cuisine].insert({-rating, food});
        }
    }

    void changeRating(string food, int newRating) {
        string& cuisine = mp[food].second;
        int i = mp[food].first;
        Rated[cuisine].erase({i, food});
        Rated[cuisine].insert({-newRating, food});
        mp[food] = {-newRating, cuisine};
    }

    string highestRated(string cuisine) {
        return Rated[cuisine].begin()->second;
    }
};