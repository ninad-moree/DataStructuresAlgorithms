/*
    You are given an array of integers nums of size 3. Return the maximum possible number whose binary representation can be formed by concatenating the
    binary representation of all elements in nums in some order. Note that the binary representation of any number does not contain leading zeros.

    Example 1:
    Input: nums = [1,2,3]
    Output: 30
    Explanation:
    Concatenate the numbers in the order [3, 1, 2] to get the result "11110", which is the binary representation of 30.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string toBinary(int n) {
        string ans = "";

        while(n > 0) {
            int d = n%2;
            n = n/2;
            ans +=  to_string(d);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }

    int solve(string res) {
        int ans = 0;

        reverse(res.begin(), res.end());

        int mult = 1;

        for(auto i : res) {
            string a = "";
            a += i;

            int d = stoi(a);
            ans += (d*mult);
            mult *= 2;
        }

        return ans;
    }

    int maxGoodNumber(vector<int>& nums) {
        string s1 = "";
        s1 += toBinary(nums[0]) + toBinary(nums[1]) + toBinary(nums[2]);

        string s2 = "";
        s2 += toBinary(nums[0]) + toBinary(nums[2]) + toBinary(nums[1]);

        string s3 = "";
        s3 += toBinary(nums[1]) + toBinary(nums[0]) + toBinary(nums[2]);

        string s4 = "";
        s4 += toBinary(nums[1]) + toBinary(nums[2]) + toBinary(nums[0]);

        string s5 = "";
        s5 += toBinary(nums[2]) + toBinary(nums[0]) + toBinary(nums[1]);

        string s6 = "";
        s6 += toBinary(nums[2]) + toBinary(nums[1]) + toBinary(nums[0]);

        int v1 = solve(s1);
        int v2 = solve(s2);
        int v3 = solve(s3);
        int v4 = solve(s4);
        int v5 = solve(s5);
        int v6 = solve(s6);

        vector<int> vec = {v1, v2, v3, v4, v5, v6};

        int maxi = v1;
        for(int i=1; i<6; i++) {
            maxi = max(maxi, vec[i]);
        }

        return maxi;
        
    }
};