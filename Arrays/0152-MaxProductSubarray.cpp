/*
    Given an array Arr[] that contains N integers (may be positive, negative or zero). 
    Find the product of the maximum product subarray.

    Example 1:
    Input: Arr[] = {6, -3, -10, 0, 2}
    Output: 180
    Explanation: Subarray with maximum product is [6, -3, -10] which gives product as 180.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int prod = 1;

        for(int i=0; i<nums.size(); i++) {
            prod *= nums[i];

            ans = max(ans, prod);

            if(prod == 0)   
                prod = 1;
        }

        prod = 1;

        for(int i=nums.size()-1; i>=0; i--) {
            prod *= nums[i];

            ans = max(ans, prod);

            if(prod == 0)   
                prod = 1;
        }

        return ans;
    }
};