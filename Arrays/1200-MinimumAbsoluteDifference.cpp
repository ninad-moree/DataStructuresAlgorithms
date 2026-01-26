/*
    Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements. Return a list of pairs in ascending order(with 
    respect to pairs), each pair [a, b] follows a, b are from arr
    - a < b
    - b - a equals to the minimum absolute difference of any two elements in arr
    
    Example 1:
    Input: arr = [4,2,1,3]
    Output: [[1,2],[2,3],[3,4]]
    Explanation: The minimum absolute difference is 1. List all pairs with difference equal to 1 in ascending order.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;

        sort(arr.begin(), arr.end());
        int mini = INT_MAX;
        for(int i=0; i<arr.size()-1; i++)
            mini = min(mini, arr[i+1] - arr[i]);

        for(int i=0; i<arr.size()-1; i++) {
            if(arr[i+1] - arr[i] == mini)
                ans.push_back({arr[i], arr[i+1]});
        }

        return ans;
    }
};