/*
    Suppose you have n integers labeled 1 through n. A permutation of those n integers perm (1-indexed) is considered a beautiful arrangement if for every i (1 <= i <= n), 
    either of the following is true: perm[i] is divisible by i OR i is divisible by perm[i].
    Given an integer n, return the number of the beautiful arrangements that you can construct.

    Example 1:
    Input: n = 2
    Output: 2
    Explanation:  The first beautiful arrangement is [1,2]: - perm[1] = 1 is divisible by i = 1 - perm[2] = 2 is divisible by i = 2
    The second beautiful arrangement is [2,1]: - perm[1] = 2 is divisible by i = 1 - i = 2 is divisible by perm[2] = 1
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int idx, vector<int> nums) {
        if(idx > nums.size()) 
            return 1;
        
        int cnt = 0;

        for(int i=idx; i<=nums.size(); i++) {
            int num = nums[i-1];

            if(num % idx != 0 && idx % num != 0)
                continue;

            swap(nums[idx-1], nums[i-1]);
            cnt += solve(idx+1, nums);
            swap(nums[idx-1], nums[i-1]);
        }
        
        return cnt;
    }


    int countArrangement(int n) {
        vector<int> nums;

        for(int i=1; i<=n; i++)
            nums.push_back(i);

        return solve(1, nums);
    }
};