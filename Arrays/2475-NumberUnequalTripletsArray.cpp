/*
    You are given a 0-indexed array of positive integers nums. Find the number of triplets (i, j, k) that meet the following conditions:
    0 <= i < j < k < nums.length nums[i], nums[j], and nums[k] are pairwise distinct.
    In other words, nums[i] != nums[j], nums[i] != nums[k], and nums[j] != nums[k].
    Return the number of triplets that meet the conditions.

    Example 1:
    Input: nums = [4,4,2,4,3]
    Output: 3
    Explanation: The following triplets meet the conditions:
    - (0, 2, 4) because 4 != 2 != 3
    - (1, 2, 4) because 4 != 2 != 3
    - (2, 3, 4) because 2 != 4 != 3
    Since there are 3 triplets, we return 3.
    Note that (2, 0, 4) is not a valid triplet because 2 > 0.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        int ans = 0;

        for(int i=0; i<nums.size(); i++) {
            for(int j=i+1; j<nums.size(); j++) {
                for(int k=j+1; k<nums.size(); k++) {
                    int n1 = nums[i];
                    int n2 = nums[j];
                    int n3 = nums[k];

                    if(n1 != n2 && n2 != n3 && n3 != n1) 
                        ans++;
                }
            }
        }

        return ans;
    }
};