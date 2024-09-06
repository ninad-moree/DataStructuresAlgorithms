/*
    You are given a sorted unique integer array nums. A range [a,b] is the set of all integers from a to b 
    (inclusive). Return the smallest sorted list of ranges that cover all the numbers in the array exactly.
    That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such 
    that x is in one of the ranges but not in nums.
    Each range [a,b] in the list should be output as:
    "a->b" if a != b
    "a" if a == b

    Example 1:
    Input: nums = [0,1,2,4,5,7]
    Output: ["0->2","4->5","7"]
    Explanation: The ranges are:
    [0,2] --> "0->2"
    [4,5] --> "4->5"
    [7,7] --> "7"
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size() == 0)
            return {};

        vector<string> ans;

        int num = nums[0];
        int start = nums[0];
        int len = 1;

        for(int i=1; i<nums.size(); i++) {
            if(nums[i] == num + 1) {
                len++;
                num = nums[i];
            } else {
                if(len == 1) {
                    string st = to_string(num);
                    ans.push_back(st);
                } else {
                    int end = start + len - 1;

                    string res = "";
                    res += (to_string(start) + "->" + to_string(end));
                    ans.push_back(res);
                }
                num = nums[i];
                start = nums[i];
                len = 1;
            }
        }

        if(len == 1) {
            string st = to_string(num);
            ans.push_back(st);
        } else {
            long long int end = start - 1 + len;

            string res = "";
            res += (to_string(start) + "->" + to_string(end));
            ans.push_back(res);
        }

        return ans;
    }
};