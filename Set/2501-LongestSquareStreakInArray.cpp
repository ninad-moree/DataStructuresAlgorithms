/*
    You are given an integer array nums. A subsequence of nums is called a square streak if:
    The length of the subsequence is at least 2, and
    after sorting the subsequence, each element (except the first element) is the square of the previous number.
    Return the length of the longest square streak in nums, or return -1 if there is no square streak.

    Example 1:
    Input: nums = [4,3,6,16,8,2]
    Output: 3
    Explanation: Choose the subsequence [4,16,2]. After sorting it, it becomes [2,4,16].
    - 4 = 2 * 2.
    - 16 = 4 * 4.
    Therefore, [4,16,2] is a square streak.
    It can be shown that every subsequence of length 4 is not a square streak.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        set<double> s;
        for(auto i : nums)
            s.insert(i);

        int ans = 1;

        for(int i=0; i<nums.size(); i++) {
            double n = (double)nums[i];
            n = sqrt(n);
            int curr = 1;
            while (true) {
                if(s.find(n) != s.end()) {
                    curr++;
                    n = sqrt(n);
                } else
                    break;
            }
            ans = max(ans, curr);
        }

        if(ans == 1)
            return -1;
        return ans;
    }
};