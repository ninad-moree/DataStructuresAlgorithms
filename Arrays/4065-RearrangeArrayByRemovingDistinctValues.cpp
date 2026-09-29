/*
    You are given an integer array nums. You start with an empty array ans. Repeat the following operation until nums is empty: Identify all distinct values currently present 
    in nums. Remove one occurrence of every distinct value currently in nums, and append those values to ans in ascending order. Return the array ans.

    Example 1:
    Input: nums = [3,1,3,2,1,3]
    Output: [1,2,3,1,3,3]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;
        vector<int> freq(101);
        int size = 0;

        for(auto i : nums) {
            if(freq[i] == 0)
                size++;
            freq[i]++;
        }
        
        while(size) {
            for(int i=1; i<=100; i++) {
                if(freq[i] > 0) {
                    ans.push_back(i);
                    freq[i]--;

                    if(freq[i] == 0)
                        size--;
                }
            }
        }

        return ans;
    }
};