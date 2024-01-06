/*
    Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), 
    ans[i] is the number of 1's in the binary representation of i.

    Example 1:
    Input: n = 2
    Output: [0,1,1]
    Explanation:
    0 --> 0
    1 --> 1
    2 --> 10
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void convertToBinary(int n, vector<int>& toBinary) {
        if(n==0) 
            toBinary.push_back(0);
        while(n!=0) {
            toBinary.push_back(n%2);
            n=n/2;
        }
        reverse(toBinary.begin(), toBinary.end());
    }

    int countOnes(vector<int>& nums) {
        int cnt=0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]==1) 
                cnt++;
        }
        return cnt;
    }
    
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0;i<n+1;i++) {
            vector<int> toBinary;
            convertToBinary(i, toBinary);
            ans.push_back(countOnes(toBinary));
        }
        return ans;
    }
};