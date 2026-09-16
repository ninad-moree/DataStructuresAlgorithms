/*
    You are given an integer array nums. For each element nums[i], you may perform the following operations any number of times (including zero): Increase nums[i] by 1, or
    Decrease nums[i] by 1. A number is called a binary palindrome if its binary representation without leading zeros reads the same forward and backward. Your task is to return
    an integer array ans, where ans[i] represents the minimum number of operations required to convert nums[i] into a binary palindrome.

    Example 1:
    Input: nums = [1,2,4]
    Output: [0,1,1]
    Explanation: One optimal set of operations: nums[i]	Binary(nums[i]), ans = [0, 1, 1].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string toBinary(int x) {
        string s = "";

        while (x) {
            s += (x % 2) + '0';
            x /= 2;
        }

        return s;
    }

    bool isPalindrome(int n) {
        string bin = toBinary(n);

        string rev = bin;
        reverse(rev.begin(), rev.end());

        return bin == rev;
    }

    vector<int> minOperations(vector<int>& nums) {
        vector<int> palindromes;

        for(int i=1; i<=5000; i++) {
            if(isPalindrome(i))
                palindromes.push_back(i);
        }

        vector<int> ans;

        for(auto n : nums) {
            int i = 0;
            int j = palindromes.size() - 1;
            bool isCalc = false;

            while(i <= j) {
                int mid = i + (j - i) / 2;

                if(palindromes[mid] == n) {
                    ans.push_back(0);
                    isCalc = true;
                    break;
                } else if(palindromes[mid] > n) 
                    j = mid - 1;
                else 
                    i = mid + 1;
            }

            if(!isCalc) {
                int mini = INT_MAX;

                if(i < palindromes.size())
                    mini = min(mini, palindromes[i] - n);

                if(j >= 0)
                    mini = min(mini, n - palindromes[j]);

                ans.push_back(mini);
            }
        }

        return ans;
    }
};