/*
    Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order. You must write an algorithm that runs in 
    O(n) time and uses O(1) extra space. 

    Example 1:
    Input: n = 13
    Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> nums;

        for(int i=1; i<=n; i++) 
            nums.push_back(to_string(i));

        sort(nums.begin(), nums.end());

        vector<int> ans;
        for(auto i : nums)
            ans.push_back(stoi(i));

        return ans;
    }
};