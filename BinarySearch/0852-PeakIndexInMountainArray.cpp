/*
    You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease. Return the index of the 
    peak element. Your task is to solve it in O(log(n)) time complexity.

    Example 1:
    Input: arr = [0,10,5,2]
    Output: 1
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int ans;

        int l = 0;
        int h = arr.size()-1;
        int m = l+(h-l)/2;;

        while(l<h) {
            if(arr[m] < arr[m+1])
                l = m+1;
            else
                h = m;

            m = l+(h-l)/2;
        }

        return m;
    }
};