/*
    Given an array of integers arr, replace each element with its rank. The rank represents how large the element is. The rank has the following 
    rules: Rank is an integer starting from 1. The larger the element, the larger the rank. If two elements are equal, their rank must be the same.
    Rank should be as small as possible.

    Example 1:
    Input: arr = [40,10,20,30]
    Output: [4,1,2,3]
    Explanation: 40 is the largest element. 10 is the smallest. 20 is the second smallest. 30 is the third smallest.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size() == 0)
            return {};
        vector<pair<int, int>> temp;

        for(int i=0; i<arr.size(); i++)
            temp.push_back({arr[i], i});

        sort(temp.begin(), temp.end());

        vector<int> ans(arr.size());
        int rank = 1;
        
        ans[temp[0].second] = rank;
        for(int i=1; i<arr.size(); i++) {
            if(temp[i].first != temp[i-1].first)
                rank++;
            ans[temp[i].second] = rank;
        }

        return ans;
    }
};