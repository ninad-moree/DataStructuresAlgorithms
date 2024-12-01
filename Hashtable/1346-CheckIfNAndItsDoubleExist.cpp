/*
    Given an array arr of integers, check if there exist two indices i and j such that :
    i != j
    0 <= i, j < arr.length
    arr[i] == 2 * arr[j]

    Example 1:
    Input: arr = [10,2,5,3]
    Output: true
    Explanation: For i = 0 and j = 2, arr[i] == 10 == 2 * 5 == 2 * arr[j]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(int i=0; i<arr.size(); i++)
            mp[arr[i]] = i;;

        bool ans = false;

        for(int i=0; i<arr.size(); i++) {
            int n = arr[i] * 2;
            if(mp.find(n) != mp.end() && i != mp[n])
                ans = true;
        }

        return ans;
    }
};