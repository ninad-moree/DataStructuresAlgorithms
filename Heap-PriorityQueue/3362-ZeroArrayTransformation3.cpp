/*
    You are given an integer array nums of length n and a 2D array queries where queries[i] = [li, ri]. Each queries[i] represents the following 
    action on nums: Decrement the value at each index in the range [li, ri] in nums by at most 1.
    The amount by which the value is decremented can be chosen independently for each index.
    A Zero Array is an array with all its elements equal to 0. Return the maximum number of elements that can be removed from queries, such that nums
    can still be converted to a zero array using the remaining queries. If it is not possible to convert nums to a zero array, return -1.

    Example 1:
    Input: nums = [2,0,2], queries = [[0,2],[0,2],[1,1]]
    Output: 1
    Explanation: After removing queries[2], nums can still be converted to a zero array.
    Using queries[0], decrement nums[0] and nums[2] by 1 and nums[1] by 0.
    Using queries[1], decrement nums[0] and nums[2] by 1 and nums[1] by 0.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(), queries.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });

        priority_queue<int> pq;
        vector<int> arr(nums.size() + 1, 0);
        int ans = 0;

        for(int i=0, j=0; i<nums.size(); i++) {
            ans += arr[i];

            while(j < queries.size() && queries[j][0] == i) {
                pq.push(queries[j][1]);
                j++;
            }

            while(ans < nums[i] && !pq.empty() && pq.top() >= i) {
                ans++;
                arr[pq.top() + 1]--;
                pq.pop();
            }

            if(ans < nums[i])
                return -1;
        }

        return pq.size();
    }
};