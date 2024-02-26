/*
    You are given positive integers n and target.
    An array nums is beautiful if it meets the following conditions:
    nums.length == n.
    nums consists of pairwise distinct positive integers.
    There doesn't exist two distinct indices, i and j, in the range [0, n - 1], such that nums[i] + nums[j] == target.
    Return the minimum possible sum that a beautiful array could have modulo 109 + 7.

    Example 1:
    Input: n = 2, target = 3
    Output: 4
    Explanation: We can see that nums = [1,3] is beautiful.
    - The array nums has length n = 2.
    - The array nums consists of pairwise distinct positive integers.
    - There doesn't exist two distinct indices, i and j, with nums[i] + nums[j] == 3.
    It can be proven that 4 is the minimum possible sum that a beautiful array could have.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        long long sum = 0;
        long long num = 1;
        int MOD = 1e9+7;

        map<int, int> mp;

        for(int i=0; i<n; i++) {
            while(mp.find(target-num) != mp.end())
                num++;
            mp[num]++;
            sum += num;
            num++;
        }
        
        return sum%MOD;
    }
};