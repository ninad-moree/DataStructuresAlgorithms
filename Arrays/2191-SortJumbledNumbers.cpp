/*
    You are given a 0-indexed integer array mapping which represents the mapping rule of a shuffled decimal system. mapping[i] = j means digit i should 
    be mapped to digit j in this system. The mapped value of an integer is the new integer obtained by replacing each occurrence of digit i in the 
    integer with mapping[i] for all 0 <= i <= 9. You are also given another integer array nums. Return the array nums sorted in non-decreasing order 
    based on the mapped values of its elements.
    Notes:
    Elements with the same mapped values should appear in the same relative order as in the input.
    The elements of nums should only be sorted based on their mapped values and not be replaced by them.
    
    Example 1:
    Input: mapping = [8,9,4,0,2,1,3,5,7,6], nums = [991,338,38]
    Output: [338,38,991]
    Explanation: 
    Map the number 991 as follows:
    1. mapping[9] = 6, so all occurrences of the digit 9 will become 6.
    2. mapping[1] = 9, so all occurrences of the digit 1 will become 9.
    Therefore, the mapped value of 991 is 669.
    338 maps to 007, or 7 after removing the leading zeros.
    38 maps to 07, which is also 7 after removing leading zeros.
    Since 338 and 38 share the same mapped value, they should remain in the same relative order, so 338 comes before 38.
    Thus, the sorted array is [338,38,991].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, pair<int, int>>> mp;
        
        for (int i = 0; i < nums.size(); ++i) {
            int original = nums[i];
            string s = to_string(original);
            string d = "";
            
            for (char ch : s) 
                d += to_string(mapping[ch - '0']);
            
            int n = stoi(d);
            mp.push_back({original, {n, i}});
        }

        sort(mp.begin(), mp.end(), [](const auto& a, const auto& b) {
            if (a.second.first == b.second.first) 
                return a.second.second < b.second.second;
            return a.second.first < b.second.first;
        });
        
        vector<int> ans;
        for (const auto& p : mp) 
            ans.push_back(p.first);
        
        return ans;
    }
};
