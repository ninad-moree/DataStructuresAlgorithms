/*
    You are given an array of strings words, where each string represents a word containing lowercase English letters. You are also given an integer array weights of length 26,
    where weights[i] represents the weight of the ith lowercase English letter. The weight of a word is defined as the sum of the weights of its characters. For each word, take
    its weight modulo 26 and map the result to a lowercase English letter using reverse alphabetical order (0 -> 'z', 1 -> 'y', ..., 25 -> 'a').
    Return a string formed by concatenating the mapped characters for all words in order.

    Example 1:
    Input: words = ["abcd","def","xyz"], weights = [5,3,12,14,1,2,3,2,10,6,6,9,7,8,7,10,8,9,6,9,9,8,3,7,7,2]
    Output: "rij"
    Explanation: The weight of "abcd" is 5 + 3 + 12 + 14 = 34. The result modulo 26 is 34 % 26 = 8, which maps to 'r'. The weight of "def" is 14 + 1 + 2 = 17. The result modulo
    26 is 17 % 26 = 17, which maps to 'i'. The weight of "xyz" is 7 + 7 + 2 = 16. The result modulo 26 is 16 % 26 = 16, which maps to 'j'. Thus, the string formed by 
    concatenating the mapped characters is "rij".
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n = words.size();
        vector<int> vals(n);

        for(int i=0; i<n; i++) {
            string word = words[i];
            int val = 0;

            for(auto i : word) 
                val += weights[i - 'a'];
            
            vals[i] = val % 26;
        }

        string ans = "";

        for(auto i : vals) {
            int val = 25 - i;
            char ch = 'a' + val;
            ans += ch;
        }

        return ans;
    }
};