/*
    You are given an array of strings products and a string searchWord.
    Design a system that suggests at most three product names from products after each 
    character of searchWord is typed. Suggested products should have common prefix with 
    searchWord. If there are more than three products with a common prefix return the three 
    lexicographically minimums products.
    Return a list of lists of the suggested products after each character of searchWord is 
    typed.

    Example 1:
    Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
    Output: 
        [
            ["mobile","moneypot","monitor"],
            ["mobile","moneypot","monitor"],
            ["mouse","mousepad"],
            ["mouse","mousepad"],
            ["mouse","mousepad"]
        ]
        Explanation: products 
        sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"].
        After typing m and mo all products match and we show user ["mobile","moneypot","monitor"].
        After typing mou, mous and mouse the system suggests ["mouse","mousepad"].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans;

        sort(products.begin(), products.end());

        string prefix = "";
        for (char c : searchWord) {
            prefix += c;
            vector<string> suggested;
            auto it = lower_bound(products.begin(), products.end(), prefix);
            for (int i = 0; i < 3 && it + i != products.end(); ++i) {
                if (it[i].find(prefix) == 0) {
                    suggested.push_back(it[i]);
                } else {
                    break;
                }
            }
            ans.push_back(suggested);
        }
        return ans; 
    }
};