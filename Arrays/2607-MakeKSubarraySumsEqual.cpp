/*
    You are given a 0-indexed integer array arr and an integer k. The array arr is circular. In other words, the first element of the 
    array is the next element of the last element, and the last element of the array is the previous element of the first element.
    You can do the following operation any number of times: Pick any element from arr and increase or decrease it by 1.
    Return the minimum number of operations such that the sum of each subarray of length k is equal.
    
    Example 1:
    Input: arr = [1,4,1,3], k = 2
    Output: 1
    Explanation: we can do one operation on index 1 to make its value equal to 3.
*/

#include<bits/stdc++.h>
#include <numeric>
using namespace std;

class Solution {
public:
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        long long ans = 0;

        k = __gcd(arr.size(), k);

        for(int i=0; i<k; i++) {
            vector<int> res;

            for(int j=i; j<arr.size(); j+=k)
                res.push_back(arr[j]);
            
            sort(res.begin(), res.end());

            long long median = res[res.size() / 2];

            for(int j=i; j<arr.size(); j+=k)
                ans += abs(median - arr[j]);
        }

        return ans;
    }
};