/*
    Given n non-negative integers representing an elevation map where the width of each bar is 1, 
    compute how much water it can trap after raining.

    Example 1:
    Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
    Output: 6
    Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
    In this case, 6 units of rain water (blue section) are being trapped.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        if(n==0) 
            return 0;

        int l = 0;
        int r = n-1;

        int lmax = height[l];
        int rmax = height[r];
        int res = 0;

        while(l<r) {
            if(lmax < rmax) {
                l++;
                lmax = max(lmax, height[l]);
                res += lmax - height[l];
            }
            else {
                r--;
                rmax = max(rmax, height[r]);
                res += rmax - height[r];
            }
        }
        return res;
    }
};