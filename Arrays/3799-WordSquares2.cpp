/*
    You are given a string array words, consisting of distinct 4-letter strings, each containing lowercase English letters. A word square consists of 4 distinct words: top, 
    left, right and bottom, arranged as follows: top forms the top row. bottom forms the bottom row. left forms the left column (top to bottom). right forms the right column 
    (top to bottom). It must satisfy: top[0] == left[0], top[3] == right[0], bottom[0] == left[3], bottom[3] == right[3] Return all valid distinct word squares, sorted in 
    ascending lexicographic order by the 4-tuple (top, left, right, bottom)​​​​​​​.

    Example 1:
    Input: words = ["able","area","echo","also"]
    Output: [["able","area","echo","also"],["area","able","also","echo"]]
    Explanation: There are exactly two valid 4-word squares that satisfy all corner constraints: "able" (top), "area" (left), "echo" (right), "also" (bottom)
    top[0] == left[0] == 'a', top[3] == right[0] == 'e', bottom[0] == left[3] == 'a', bottom[3] == right[3] == 'o', "area" (top), "able" (left), "also" (right), "echo" (bottom)
    All corner constraints are satisfied. Thus, the answer is [["able","area","echo","also"],["area","able","also","echo"]].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        int n = words.size();
        vector<vector<string>> ans;

        for(int i=0; i<n; i++) {
            string top = words[i];
            char t0 = top[0];
            char t3 = top[3];

            for(int j=0; j<n; j++) {
                if(words[j] == top)
                    continue;

                string right = words[j];
                char r0 = right[0];
                char r3 = right[3];

                if(t3 != r0) 
                    continue;

                for(int k=0; k<n; k++) {
                    if(words[k] == words[i] || words[k] == words[j])
                        continue;

                    string bottom = words[k];
                    char b0 = bottom[0];
                    char b3 = bottom[3];

                    if(r3 != b3)
                        continue;

                    for(int l=0; l<n; l++) {
                        if(words[l] == words[i] || words[l] == words[j] || words[l] == words[k])
                            continue;

                        string left = words[l];
                        char l0 = left[0];
                        char l3 = left[3];

                        if(l3 != b0)
                            continue;
                        if(l0 != t0)
                            continue;

                        ans.push_back({top, left, right, bottom});
                    }
                }
            }
        }
        
        sort(ans.begin(), ans.end());

        return ans;
    }
};