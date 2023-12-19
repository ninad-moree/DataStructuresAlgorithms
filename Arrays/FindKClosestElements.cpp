/*
    Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. 
    The result should also be sorted in ascending order.
    An integer a is closer to x than an integer b if:
    |a - x| < |b - x|, or
    |a - x| == |b - x| and a < b
    
    Example 1:

    Input: arr = [1,2,3,4,5], k = 4, x = 3
    Output: [1,2,3,4]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    vector<int> findClosestElements(vector<int>& arr, int& k, int x) {
        int left = 0;
        int right = arr.size()-1;

        while(right - left >= k) {
            if(abs(arr[left]-x) <= abs(arr[right]-x))
                right--;
            else 
                left++;
        }

        vector<int> ans(arr.begin()+left, arr.begin()+left+k);

        return ans;
    }
};