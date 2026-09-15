/*
    You are given an integer array nums. In one operation, you remove the first three elements of the current array. If there are fewer than three elements remaining, all 
    remaining elements are removed. Repeat this operation until the array is empty or contains no duplicate values. Return an integer denoting the number of operations required.

    Example 1:
    Input: nums = [3,8,3,6,5,8]
    Output: 1
    Explanation: In the first operation, we remove the first three elements. The remaining elements [6, 5, 8] are all distinct, so we stop. Only one operation is needed.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mp;
        int duplicateCount = 0;

        for(int x : nums) {
            mp[x]++;

            if(mp[x] == 2)
                duplicateCount++;
        }

        int ans = 0;
        int i = 0;

        while(i < n && duplicateCount > 0) {
            for(int j = i; j < min(i + 3, n); j++) {
                if(mp[nums[j]] == 2)
                    duplicateCount--;

                mp[nums[j]]--;
            }

            ans++;
            i+=3;
        }

        return ans;
    }
};