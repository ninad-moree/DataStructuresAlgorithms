/*
    You are given an array nums1 of n distinct integers. You want to construct another array nums2 of length n such that the elements in nums2 are either all odd or all even.
    For each index i, you must choose exactly one of the following (in any order): nums2[i] = nums1[i]​​​​​​​ nums2[i] = nums1[i] - nums1[j], for an index j != i, such that 
    nums1[i] - nums1[j] >= 1 Return true if it is possible to construct such an array, otherwise return false.

    Example 1:
    Input: nums1 = [1,4,7]
    Output: true
    Explanation:​​​​​​​​​​​​​​ Set nums2[0] = nums1[0] = 1. Set nums2[1] = nums1[1] - nums1[0] = 4 - 1 = 3. Set nums2[2] = nums1[2] = 7.
    nums2 = [1, 3, 7], and all elements are odd. Thus, the answer is true.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int even = 0;
        int odd = 0;
        int so = INT_MAX;
        int oi = -1;

        for(int i=0; i<n; i++) {
            if(nums1[i] % 2 == 0) 
                even++;
            else {
                odd++;

                if(nums1[i] < so) {
                    so = nums1[i];
                    oi = i;
                }
            }
        }

        if(even == 0 || odd == 0)
            return true;

        bool canEven = true;
        bool canOdd = true;

        // CHECK EVEN
        for(int i=0; i<n; i++) {
            if(nums1[i] % 2 == 1) {
                if(nums1[i] - so >= 1 && oi != i) 
                    continue;
                else {
                    canEven = false;
                    break;
                }
            } 
        }

        // CHECK ODD
        for(int i=0; i<n; i++) {
            if(nums1[i] % 2 == 0) {
                if(nums1[i] - so >= 1 && oi != i) 
                    continue;
                else {
                    canOdd = false;
                    break;
                }
            }
        }

        if(!canEven && !canOdd)
            return false;
        return true;
    }
};