/*
    Given an integer array nums and an integer k, modify the array in the following way: choose an index i and replace nums[i] with -nums[i].
    You should apply this process exactly k times. You may choose the same index i multiple times.
    Return the largest possible sum of the array after modifying it in this way.

    Example 1:
    Input: nums = [4,2,3], k = 1
    Output: 5
    Explanation: Choose index 1 and nums becomes [4,-2,3].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto i : nums)
            pq.push(i);

        while(k--) {
            int f = pq.top();
            pq.pop();

            f = f * (-1);
            pq.push(f);
        }

        int sum = 0;
        while(!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }

        return sum;
    }
};