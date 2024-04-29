/*
    You are given two integer arrays nums1 and nums2 of equal length n and an integer k. You can perform the following operation on nums1:
    Choose two indexes i and j and increment nums1[i] by k and decrement nums1[j] by k. In other words, nums1[i] = nums1[i] + k and 
    nums1[j] = nums1[j] - k. nums1 is said to be equal to nums2 if for all indices i such that 0 <= i < n, nums1[i] == nums2[i].
    Return the minimum number of operations required to make nums1 equal to nums2. If it is impossible to make them equal, return -1.

    Example 1:
    Input: nums1 = [4,3,1,4], nums2 = [1,3,7,1], k = 3
    Output: 2
    Explanation: In 2 operations, we can transform nums1 to nums2.
    1st operation: i = 2, j = 0. After applying the operation, nums1 = [1,3,4,4].
    2nd operation: i = 2, j = 3. After applying the operation, nums1 = [1,3,7,1].
    One can prove that it is impossible to make arrays equal in fewer operations.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        if(k == 0) 
            return nums1 == nums2 ? 0 : -1;

        bool ans = true;

        long long inc = 0;
        long long dec = 0;

        for(int i=0; i<nums1.size(); i++) {
            int diff;

            if(nums1[i] >= nums2[i]) {
                diff = nums1[i] - nums2[i];
                if(diff%k != 0) {
                    ans = false;
                    break;
                }
                dec += (diff) / k;
            } else {
                diff = nums2[i] - nums1[i];
                if(diff%k != 0) {
                    ans = false;
                    break;
                }
                inc += (diff)/k;
            }
        }

        if(!ans)
            return -1;
        
        return dec == inc ? inc : -1;
    }
};