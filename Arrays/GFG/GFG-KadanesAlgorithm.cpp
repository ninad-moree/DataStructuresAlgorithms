/*
    Given an array Arr[] of N integers. Find the contiguous sub-array(containing at least one number) which has the maximum sum and return its sum.

    Example 1:
    Input: N = 5, Arr[] = {1,2,3,-2,5}
    Output: 9
    Explanation:
    Max subarray sum is 9
    of elements (1, 2, 3, -2, 5) which 
    is a contiguous subarray.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    long long maxSubarraySum(int arr[], int n){
        long long maxSum = arr[0]; 
        long long currSum = arr[0]; 
    
        for (int i = 1; i < n; i++) {
            currSum = max((long long)arr[i], currSum + (long long)arr[i]);
            maxSum = max(maxSum, currSum);
        }
    
        return maxSum;
    }
};