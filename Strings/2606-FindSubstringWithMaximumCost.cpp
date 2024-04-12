/*
    You are given a string s, a string chars of distinct characters and an integer array vals of the same length as chars.
    The cost of the substring is the sum of the values of each character in the substring. The cost of an empty string is considered 0.
    The value of the character is defined in the following way:
    If the character is not in the string chars, then its value is its corresponding position (1-indexed) in the alphabet.
    For example, the value of 'a' is 1, the value of 'b' is 2, and so on. The value of 'z' is 26.
    Otherwise, assuming i is the index where the character occurs in the string chars, then its value is vals[i].
    Return the maximum cost among all substrings of the string s.

    Example 1:
    Input: s = "adaa", chars = "d", vals = [-1000]
    Output: 2
    Explanation: The value of the characters "a" and "d" is 1 and -1000 respectively.
    The substring with the maximum cost is "aa" and its cost is 1 + 1 = 2.
    It can be proven that 2 is the maximum cost.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        vector<int> arr(26, 0);

        for(int i=0; i<26; i++) 
            arr[i] = i+1;
        
        for(int i=0; i<chars.size(); i++) 
            arr[chars[i] - 'a'] = vals[i];

        int ans = 0;
        int sum = 0;

        for(int i=0; i<s.size(); i++) {
            sum += arr[s[i] - 'a'];
            ans = max(ans, sum);
            if(sum < 0)
                sum = 0;
        }

        return ans;
    }
};