/*
    You are given a binary array rain of length n, where rain[i] == 1 means it rains on day i, and rain[i] == 0 means it does not. Alice and Bob share a single umbrella over 
    these n days. On each day i: Alice needs the umbrella on day i if rain[i] == rain[i + 1] == 1 for 0 <= i < n - 1. Bob needs the umbrella if rain[i] == 1.
    At most one of them can receive the umbrella. If only one person needs it, that person receives it. If both need it, it goes to whoever has received it fewer times so far. 
    If they are tied, it goes to Alice. If neither needs it, no one receives it. A person's cnt increases only on a day they receive the umbrella. Initially, both counts are 0.
    Return a string array answer of length n, where answer[i] is "Alice", "Bob", or "None", denoting who receives the umbrella on day i.
    
    Example 1:
    Input: rain = [1,1,0,1,1]
    Output: ["Alice","Bob","None","Alice","Bob"]
    Explanation: Day 0: rain[0] == 1 and rain[1] == 1, so both need it. Counts are tied, so Alice receives it. Day 1: rain[1] == 1, so Bob needs it, but rain[2] == 0, so Alice 
    does not need it. Therefore Bob receives it. Day 2: No rain, so no one receives it. Day 3: rain[3] == 1 and rain[4] == 1, so both need it. Counts are tied at 1, so Alice 
    receives it. Day 4: Last day, so only Bob needs it, and he receives it. Therefore, answer = ["Alice", "Bob", "None", "Alice", "Bob"].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> assignUmbrella(vector<int>& rain) {
        vector<string> ans(rain.size(), "None");
        int alice = 0;
        int bob = 0;

        for(int i=0; i<rain.size(); i++) {
            if(rain[i] == 1) {
                if(i < rain.size() - 1) {
                    if((rain[i] == 1 && rain[i+1] == 1) && (alice <= bob)) {
                        alice++;
                        ans[i] = "Alice";
                    } else {
                        bob++;
                        ans[i] = "Bob";
                    }
                } else  {
                    bob++;
                    ans[i] = "Bob";
                }
            }
        }

        return ans;
    }
};