/*
    You are given an array of integers nums of length n and a positive integer k. The power of an array is defined as:
    Its maximum element if all of its elements are consecutive and sorted in ascending order. -1 otherwise. You need to find the power of all 
    subarrays of nums of size k. Return an integer array results of size n - k + 1, where results[i] is the power of nums[i..(i + k - 1)].

    Example 1:
    Input: nums = [1,2,3,4,3,2,5], k = 3
    Output: [3,4,-1,-1,-1]
    Explanation:
    There are 5 subarrays of nums of size 3:
    [1, 2, 3] with the maximum element 3.
    [2, 3, 4] with the maximum element 4.
    [3, 4, 3] whose elements are not consecutive.
    [4, 3, 2] whose elements are not sorted.
    [3, 2, 5] whose elements are not consecutive.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n-k+1);

        vector<int> window(k);
        for(int i=0; i<k; i++)
            window[i] = nums[i];
        
        bool isPower = true;
        for(int i=0; i<k-1; i++) {
            if(window[i+1] - window[i] != 1)
                isPower = false;
        }
        ans[0] = isPower ? window[k-1] : -1;
        int idx = 1;

        for(int i=k; i<n; i++) {
            window.erase(window.begin()+0);
            window.push_back(nums[i]);

            bool isPowerArr = true;
            for(int j=0; j<k-1; j++) {
                if(window[j+1] - window[j] != 1)
                    isPowerArr = false;
            }
            ans[idx] = isPowerArr ? window[k-1] : -1;
            idx++;
        }

        return ans;
    }
};