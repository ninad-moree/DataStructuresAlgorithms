/*
    You are given an integer array nums and an integer k. Rotate only the non-negative elements of the array to the left by k positions, in a cyclic manner. All negative 
    elements must stay in their original positions and must not move. After rotation, place the non-negative elements back into the array in the new order, filling only the 
    positions that originally contained non-negative values and skipping all negative positions. Return the resulting array.

    Example 1:
    Input: nums = [1,-2,3,-4], k = 3
    Output: [3,-2,1,-4]
    Explanation:​​​​​​​ The non-negative elements, in order, are [1, 3]. Left rotation with k = 3 results in: [1, 3] -> [3, 1] -> [1, 3] -> [3, 1]
    Placing them back into the non-negative indices results in [3, -2, 1, -4].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> posi;
        for(auto i : nums) {
            if(i >= 0)
                posi.push_back(i);
        }

        int n = posi.size();

        if(n == 0)
            return nums;

        k  = k % n;
        
        reverse(posi.begin(), posi.begin() + k);
        reverse(posi.begin() + k, posi.end());
        reverse(posi.begin(), posi.end());

        int idx = 0;

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] >= 0) {
                nums[i] = posi[idx];
                idx++;
            }
        }

        return nums;
    }
};