/*
    You are given an integer array nums. An integer x is called special if: x appears exactly three times in nums. All three occurrences of x are equally spaced in nums. In 
    other words, if all occurrences of x are at indices i1 < i2 < i3, then i2 - i1 = i3 - i2. Return the number of distinct special integers in nums.

    Example 1:
    Input: nums = [1,8,1,5,1,5,8,5]
    Output: 2
    Explanation: 1 is special because it occurs exactly three times at equally spaced indices 0, 2, and 4. 5 is special because it occurs exactly three times at equally spaced 
    indices 3, 5, and 7. 8 is not special because it occurs only twice. Therefore, the answer is 2.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;

        for(int i=0; i<nums.size(); i++) 
            mp[nums[i]].push_back(i);

        int ans = 0;

        for(auto i : mp) {
            int n = i.first;
            vector<int> idx = i.second;

            if(idx.size() == 3) {
                int i1 = idx[0];
                int i2 = idx[1];
                int i3 = idx[2];

                if(i2 - i1 == i3 - i2)
                    ans++;
            }
        }

        return ans;
    }
};