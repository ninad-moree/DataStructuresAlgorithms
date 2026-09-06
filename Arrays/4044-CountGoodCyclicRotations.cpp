/*
    You are given an integer array nums of even length n. A cyclic rotation of nums is obtained by choosing a prefix of nums whose length is between 0 and n - 1 (inclusive), 
    and moving it to the end of the array while preserving the order of all elements. A cyclic rotation is good if the sum of its first n / 2 elements is strictly greater than 
    the sum of its last n / 2 elements. Return the number of cyclic rotations of nums that are good.

    Example 1:
    Input: nums = [1,2,3,4,5,6]
    Output: 3
    Explanation: The cyclic rotations of nums are: Cyclic rotation	Sum of first n / 2 elements	Sum of last n / 2 elements
    [1, 2, 3, 4, 5, 6]	1 + 2 + 3 = 6	4 + 5 + 6 = 15
    [2, 3, 4, 5, 6, 1]	2 + 3 + 4 = 9	5 + 6 + 1 = 12
    [3, 4, 5, 6, 1, 2]	3 + 4 + 5 = 12	6 + 1 + 2 = 9
    [4, 5, 6, 1, 2, 3]	4 + 5 + 6 = 15	1 + 2 + 3 = 6
    [5, 6, 1, 2, 3, 4]	5 + 6 + 1 = 12	2 + 3 + 4 = 9
    [6, 1, 2, 3, 4, 5]	6 + 1 + 2 = 9	3 + 4 + 5 = 12
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        long long totalSum = 0;
        
        vector<int> arr(2*n);

        for(int i=0; i<n; i++) {
            arr[i] = nums[i];
            arr[i + n] = nums[i];

            totalSum += nums[i];
        }

        int ans = 0;
        long long sum = 0;

        for(int i=0; i<n/2; i++)
            sum += arr[i];

        if(sum > totalSum - sum)
            ans++;

        int i = 1;
        int j = n/2;

        while(i < n) {
            sum -= arr[i-1];
            sum += arr[j];

            if(sum > totalSum - sum)
                ans++;

            i++;
            j++;
        }

        return ans;
    }
};