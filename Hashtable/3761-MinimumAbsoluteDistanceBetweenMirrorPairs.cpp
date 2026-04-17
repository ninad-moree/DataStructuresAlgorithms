/*
    You are given an integer array nums. A mirror pair is a pair of indices (i, j) such that: 0 <= i < j < nums.length, and reverse(nums[i]) == nums[j], where reverse(x) denotes
    the integer formed by reversing the digits of x. Leading zeros are omitted after reversing, for example reverse(120) = 21. Return the minimum absolute distance between the 
    indices of any mirror pair. The absolute distance between indices i and j is abs(i - j). If no mirror pair exists, return -1.

    Example 1:
    Input: nums = [12,21,45,33,54]
    Output: 1
    Explanation: The mirror pairs are:
    (0, 1) since reverse(nums[0]) = reverse(12) = 21 = nums[1], giving an absolute distance abs(0 - 1) = 1.
    (2, 4) since reverse(nums[2]) = reverse(45) = 54 = nums[4], giving an absolute distance abs(2 - 4) = 2.
    The minimum absolute distance among all pairs is 1.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverseNum(int n) {
        int rev = 0;
        while(n > 0) {
            rev = rev * 10 + (n % 10);
            n /= 10;
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = INT_MAX;

        for(int i=0; i<nums.size(); i++) {
            int curr = nums[i];
            int rev = reverseNum(nums[i]);
            
            if(mp.find(curr) != mp.end()) 
                ans = min(ans, abs(i - mp[curr]));

            mp[rev] = i;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};