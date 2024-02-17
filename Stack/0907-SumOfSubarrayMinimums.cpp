/*
    Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. 
    Since the answer may be large, return the answer modulo 109 + 7.

    Example 1:
    Input: arr = [3,1,2,4]
    Output: 17
    Explanation: 
    Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
    Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
    Sum is 17.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        long long result = 0;  
        stack<int> s;  

        for (int i = 0; i <= n; ++i) {
            while (!s.empty() && (i == n || arr[i] < arr[s.top()])) {
                int j = s.top();
                s.pop();
                int k = s.empty() ? -1 : s.top();
                result = (result + static_cast<long long>(arr[j]) * (i - j) * (j - k)) % MOD;
            }
            s.push(i);
        }

        return static_cast<int>(result);
    }
};