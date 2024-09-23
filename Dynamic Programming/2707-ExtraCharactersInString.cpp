/*
    You are given a 0-indexed string s and a dictionary of words dictionary. You have to break s into one or more non-overlapping substrings such 
    that each substring is present in dictionary. There may be some extra characters in s which are not present in any of the substrings.
    Return the minimum number of extra characters left over if you break up s optimally.

    Example 1:
    Input: s = "leetscode", dictionary = ["leet","code","leetcode"]
    Output: 1
    Explanation: We can break s in two substrings: "leet" from index 0 to 3 and "code" from index 5 to 8. There is only 1 unused character 
    (at index 4), so we return 1.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        set<string> dict;
        for(auto i : dictionary)
            dict.insert(i);

        vector<int> dp(s.size()+1);

        for(int i=s.size()-1; i>=0; i--) {
            dp[i] = dp[i+1] + 1;

            for(int j=1; j<=s.size()-i; j++) {
                string substr = s.substr(i, j);
                if(dict.find(substr) != dict.end())
                    dp[i] = min(dp[i], dp[i+j]);
            }
        }

        return dp[0];
    }
};