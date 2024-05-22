/*
    An array is considered special if every pair of its adjacent elements contains two numbers with different parity.
    You are given an array of integers nums. Return true if nums is a special array, otherwise, return false.
    
    Example 1:
    Input: nums = [2,1,4]
    Output: true
    Explanation:
    There is only two pairs: (2,1) and (1,4), and both of them contain numbers with different parity. So the answer is true.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();

        if(n == 1)
            return true;
        
        for(int i=0; i<n-1; i++) {
            int curr = nums[i];
            int next = nums[i+1];

            if( (curr%2 == 0 && next%2 == 0) || (curr%2 == 1 && next%2 == 1))
                return false;
        }

        return true;
    }
};