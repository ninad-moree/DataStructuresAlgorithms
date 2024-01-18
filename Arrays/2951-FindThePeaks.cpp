/*
    You are given a 0-indexed array mountain. Your task is to find all the peaks in the mountain array.
    Return an array that consists of indices of peaks in the given array in any order.
    Notes:
    A peak is defined as an element that is strictly greater than its neighboring elements.
    The first and last elements of the array are not a peak.
    
    Example 1:
    Input: mountain = [2,4,4]
    Output: []
    Explanation: mountain[0] and mountain[2] can not be a peak because they are first and last elements of the array.
    mountain[1] also can not be a peak because it is not strictly greater than mountain[2].
    So the answer is [].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findPeaks(vector<int>& mountain) {
        vector<int> ans;

        for(int i=1;i<mountain.size()-1;i++) {
            if(mountain[i-1] < mountain[i] && mountain[i] > mountain[i+1])
                ans.push_back(i);
        }

        return ans;
    }
};