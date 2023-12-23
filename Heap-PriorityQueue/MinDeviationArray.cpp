/*
    You are given an array nums of n positive integers.
    You can perform two types of operations on any element of the array any number of times:
    If the element is even, divide it by 2.
    For example, if the array is [1,2,3,4], then you can do this operation on the last element, and the array will be [1,2,3,2].
    If the element is odd, multiply it by 2.
    For example, if the array is [1,2,3,4], then you can do this operation on the first element, and the array will be [2,2,3,4].
    The deviation of the array is the maximum difference between any two elements in the array.

    Return the minimum deviation the array can have after performing some number of operations.

    Example 1:
    Input: nums = [1,2,3,4]
    Output: 1
    Explanation: You can transform the array to [1,2,3,2], then to [2,2,3,2], then the deviation will be 3 - 2 = 1.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;

        int mini = INT_MAX;

        for(auto i : nums) {
            if(i%2 == 1)
                i = i*2;
            pq.push(i);
            mini = min(mini, i);
        } 

        int diff = INT_MAX;
        
        while(true) {
            int maxi = pq.top();
            pq.pop();
            diff = min(diff, maxi-mini);
            if(maxi%2 == 1)
                break;
            maxi = maxi/2;
            mini = min(mini, maxi);
            pq.push(maxi);
        }

        return diff;
    }
};