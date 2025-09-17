/*
    Design a food rating system that can do the following: Modify the rating of a food item listed in the system. Return the highest-rated food item for
    a type of cuisine in the system. Implement the FoodRatings class:
    FoodRatings(String[] foods, String[] cuisines, int[] ratings) Initializes the system. 
    The food items are described by foods, cuisines and ratings, all of which have a length of n.
    foods[i] is the name of the ith food,
    cuisines[i] is the type of cuisine of the ith food, and
    ratings[i] is the initial rating of the ith food.
    void changeRating(String food, int newRating) Changes the rating of the food item with the name food.
    String highestRated(String cuisine) Returns the name of the food item that has the highest rating for the given type of cuisine. 
    If there is a tie, return the item with the lexicographically smaller name.

    Input
    ["FoodRatings", "highestRated", "highestRated", "changeRating", "highestRated", "changeRating", "highestRated"]
    [[["kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"], ["korean", "japanese", "japanese", "greek", "japanese", "korean"], 
    [9, 12, 8, 15, 14, 7]], ["korean"], ["japanese"], ["sushi", 16], ["japanese"], ["ramen", 16], ["japanese"]]
    Output: [null, "kimchi", "ramen", null, "sushi", null, "ramen"]
*/

#include<bits/stdc++.h>
using namespace std;

struct Comp {
    bool operator()(const pair<int,string>& a, const pair<int,string>& b) const {
        if (a.first == b.first)
            return a.second > b.second; 
        return a.first < b.first; 
    }
};

class FoodRatings {
public:
    unordered_map<string, string> foodCuisine; // food -> cuisine
    unordered_map<string, int> foodRating; // food -> rating
    unordered_map<string, priority_queue<pair<int,string>, vector<pair<int,string>>, Comp>> cuisineHeap;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0; i<foods.size(); i++) {
            foodCuisine[foods[i]] = cuisines[i];
            foodRating[foods[i]] = ratings[i];
            cuisineHeap[cuisines[i]].push({ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = foodCuisine[food];
        foodRating[food] = newRating;
        cuisineHeap[cuisine].push({newRating, food});
    }
    
    string highestRated(string cuisine) {
        auto &pq = cuisineHeap[cuisine];
        while (!pq.empty()) {
            auto f = pq.top();
            auto rating = f.first;
            auto food = f.second;
            
            if (foodRating[food] == rating) 
                return food;
            pq.pop(); 
        }
        return "";
    }
};
