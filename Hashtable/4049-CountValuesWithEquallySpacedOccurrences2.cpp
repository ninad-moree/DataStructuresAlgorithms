/*
    You are given an integer array nums. An integer x is called special if: x appears at least three times in nums. All occurrences of x are equally spaced in nums. In other 
    words, if all occurrences of x are at indices i1 < i2 < ... < im, then i2 - i1 = i3 - i2 = ... = im - im-1. Return the number of distinct special integers in nums.

    Example 1:
    Input: nums = [1,8,1,5,1,5,8,5]
    Output: 2
    Explanation: 1 is special because it occurs at equally spaced indices 0, 2, and 4. 5 is special because it occurs at equally spaced indices 3, 5, and 7.
    8 is not special because it occurs only twice. Therefore, the answer is 2.
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

            if(idx.size() >= 3) {
                int diff = idx[1] - idx[0];
                bool isSame = true;

                for(int j=1; j<idx.size()-1; j++) {
                    if(idx[j+1] - idx[j] != diff) {
                        isSame = false;
                        break;
                    }
                }

                ans += isSame;
            }
        }

        return ans;
    }
};