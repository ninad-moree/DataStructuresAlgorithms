/*
    You are given a binary string s and a positive integer k. A substring of s is beautiful if the number of 1's in it is exactly k. Let len be the length of the shortest 
    beautiful substring. Return the lexicographically smallest beautiful substring of string s with length equal to len. If s doesn't contain a  beautiful substring, return an 
    empty string. A string a is lexicographically larger than a string b (of the same length) if in the first position where a and b differ,  a has a character strictly larger 
    than the corresponding character in b. For example, "abcd" is lexicographically larger than "abcc" because the first position they differ is at the fourth character,  and 
    d is greater than c.
    
    Example 1:
    Input: s = "100011001", k = 3
    Output: "11001"
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int cnt1 = 0;
        for(auto i : s) {
            if(i == '1')
                cnt1++;
        }

        if(cnt1 < k)
            return "";

        string ans = s;
        int cnt = 0;

        int left = 0;

        for(int right=0; right<s.size(); right++) {
            cnt += s[right] - '0';

            while(cnt > k || s[left] == '0') {
                cnt -= s[left] - '0';
                left++;
            }

            if(cnt == k) {
                string res = s.substr(left, right - left + 1);

                if(res.size() < ans.size() || res.size() == ans.size() && res < ans)
                    ans = move(res);
            }
        }

        return ans;
    }
};

