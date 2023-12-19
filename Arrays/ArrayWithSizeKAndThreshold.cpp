/*
    Given an array of integers arr and two integers k and threshold, return the number 
    of sub-arrays of size k and average greater than or equal to threshold.
    
    Example 1:
    Input: arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4
    Output: 3
    Explanation: Sub-arrays [2,5,5],[5,5,5] and [5,5,8] have averages 4, 5 and 6 respectively. 
    All other sub-arrays of size 3 have averages less than 4 (the threshold).
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int i=0;
        int j=i+k-1;
        int ans = 0;
        int sum = 0; 

        for (int l = i; l <= j; l++) {
            sum += arr[l];
        }

        while (j < arr.size()) {
            double avg = static_cast<double>(sum) / k; 

            if (avg >= threshold)
                ans++;

            sum -= arr[i];
            i++;
            j++;
            if (j < arr.size()) {
                sum += arr[j];
            }
        }
        return ans;
    }
};