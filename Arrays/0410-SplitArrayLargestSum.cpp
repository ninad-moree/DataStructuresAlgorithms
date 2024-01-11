/*
    Given an integer array nums and an integer k, split nums into k non-empty subarrays such 
    that the largest sum of any subarray is minimized.
    Return the minimized largest sum of the split.
    A subarray is a contiguous part of the array.

    Example 1:
    Input: nums = [7,2,5,10,8], k = 2
    Output: 18
    Explanation: There are four ways to split nums into two subarrays.
    The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& arr, int k, int mid) {
        int pageCnt = 0;
        int studentCnt = 1;
        for(int i=0;i<arr.size();i++) {
            if(pageCnt + arr[i] <= mid) {
                pageCnt += arr[i];
            }
            else {
                studentCnt++;
                if(studentCnt>k || arr[i] > mid ) 
                    return false;
                pageCnt = arr[i];
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int sum = 0;
        for(int i=0;i<nums.size();i++) 
            sum+=nums[i];
        
        int s = 0;
        int e = sum;
        int m = s+(e-s)/2;

        int ans=-1;
        while(s<=e) {
            if(isPossible(nums, k, m)) {
                e = m-1;
                ans = m;
            }
            else 
                s = m+1;

            m = s+(e-s)/2;
        }
        return ans;
    }
};