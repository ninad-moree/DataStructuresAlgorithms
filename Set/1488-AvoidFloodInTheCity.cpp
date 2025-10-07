/*
    Your country has an infinite number of lakes. Initially, all the lakes are empty, but when it rains over the nth lake, the nth lake becomes full of water. If it rains over a lake 
    that is full of water, there will be a flood. Your goal is to avoid floods in any lake. Given an integer array rains where:
    rains[i] > 0 means there will be rains over the rains[i] lake. rains[i] == 0 means there are no rains this day and you can choose one lake this day and dry it.
    Return an array ans where: ans.length == rains.length, ans[i] == -1 if rains[i] > 0. ans[i] is the lake you choose to dry in the ith day if rains[i] == 0.
    If there are multiple valid answers return any of them. If it is impossible to avoid flood return an empty array.

    Example 1:
    Input: rains = [1,2,3,4]
    Output: [-1,-1,-1,-1]
    Explanation: After the 1st day full lakes are [1] After the 2nd day full lakes are [1,2] After the 3rd day full lakes are [1,2,3] After the 4th day full lakes are [1,2,3,4]
    There's no day to dry any lake and there is no flood in any lake.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int> ans(rains.size(), 1);
        set<int> st;
        unordered_map<int, int> mp;

        for(int i=0; i<rains.size(); i++) {
            if(rains[i] == 0)
                st.insert(i);
            else {
                ans[i] = -1;

                if(mp.find(rains[i]) != mp.end()) {
                    auto it = st.lower_bound(mp[rains[i]]);
                    if(it == st.end())
                        return {};
                    
                    ans[*it] = rains[i];
                    st.erase(it);
                }

                mp[rains[i]] = i;
            }
        }
        
        return ans;
    }
};