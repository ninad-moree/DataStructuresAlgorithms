/*
    You are given a 0-indexed integer array nums and an integer k. You have a starting score of 0.
    In one operation:
    choose an index i such that 0 <= i < nums.length,
    increase your score by nums[i], and replace nums[i] with ceil(nums[i] / 3).
    Return the maximum possible score you can attain after applying exactly k operations.
    The ceiling function ceil(val) is the least integer greater than or equal to val.

    Example 1:
    Input: nums = [10,10,10,10,10], k = 5
    Output: 50
    Explanation: Apply the operation to each array element exactly once. The final score is 10 + 10 + 10 + 10 + 10 = 50.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;

        for(auto i : nums)
            pq.push(i);

        long long score = 0;
        
        while(k > 0) {
            int top = pq.top();
            pq.pop();

            score += top;
            
            int ele;
            if(top%3 == 0)
                ele = top/3 ;
            else
                ele = top/3 + 1;
                
            pq.push(ele);

            k--;
        }

        return score;
    }
};