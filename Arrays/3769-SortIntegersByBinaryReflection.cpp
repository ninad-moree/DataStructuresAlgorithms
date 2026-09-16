/*
    You are given an integer array nums. The binary reflection of a positive integer is defined as the number obtained by reversing the order of its binary digits (ignoring any
    leading zeros) and interpreting the resulting binary number as a decimal. Sort the array in ascending order based on the binary reflection of each element. If two different 
    numbers have the same binary reflection, the smaller original number should appear first. Return the resulting sorted array.

    Example 1:
    Input: nums = [4,5,4]
    Output: [4,4,5]
    Explanation: Binary reflections are: 4 -> (binary) 100 -> (reversed) 001 -> 1, 5 -> (binary) 101 -> (reversed) 101 -> 5, 4 -> (binary) 100 -> (reversed) 001 -> 1
    Sorting by the reflected values gives [4, 4, 5].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int binaryReflection(int n) {
        int ans = 0;

        while(n) {
            int rem = n % 2;
            n /= 2;

            ans = ans * 2 + rem;
        }

        return ans;
    }

    vector<int> sortByReflection(vector<int>& nums) {
        vector<pair<int, int>> arr;

        for(auto i : nums) {
            int rev = binaryReflection(i);
            arr.push_back({rev, i});
        }

        sort(arr.begin(), arr.end());

        vector<int> ans;

        for(int i=0; i<nums.size(); i++)
            ans.push_back(arr[i].second);

        return ans;
    }
};