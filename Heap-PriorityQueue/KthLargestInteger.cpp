/*
    You are given an array of strings nums and an integer k. Each string in nums represents an integer without leading zeros.

    Return the string that represents the kth largest integer in nums.

    Note: Duplicate numbers should be counted distinctly. For example, if nums is ["1","2","2"], "2" is the first largest integer, 
    "2" is the second-largest integer, and "1" is the third-largest integer.

    Example 1:
    Input: nums = ["3","6","7","10"], k = 4
    Output: "3"
    Explanation:
    The numbers in nums sorted in non-decreasing order are ["3","6","7","10"].
    The 4th largest integer in nums is "3".
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>>pq;

            for(int i = 0 ; i < nums.size() ;i++) {
                int len = nums[i].length();
                pq.push({len,nums[i]});

                if(pq.size() > k)
                    pq.pop();
            }

        return  pq.top().second;
    }
};