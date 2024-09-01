/*
    You are given a string s of length n and an integer k, where n is a multiple of k. Your task is to hash the string s into a new string called 
    result, which has a length of n / k. First, divide s into n / k  substrings, each with a length of k. Then, initialize result as an empty string.
    For each substring in order from the beginning: The hash value of a character is the index of that character in the English alphabet 
    (e.g., 'a' → 0, 'b' → 1, ..., 'z' → 25). Calculate the sum of all the hash values of the characters in the substring.
    Find the remainder of this sum when divided by 26, which is called hashedChar. Identify the character in the English lowercase alphabet that 
    corresponds to hashedChar. Append that character to the end of result. Return result.

    Example 1:
    Input: s = "abcd", k = 2
    Output: "bf"
    Explanation:
    First substring: "ab", 0 + 1 = 1, 1 % 26 = 1, result[0] = 'b'.
    Second substring: "cd", 2 + 3 = 5, 5 % 26 = 5, result[1] = 'f'.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string stringHash(string s, int k) {
        string ans = "";
        
        vector<string> res;
        for(int i=0; i<s.size(); i+=k) {
            string str = "";
            int cnt = 0;
            int j = i;
            
            while(cnt < k && j<s.size()) {
                str += s[j];
                j++;
                cnt++;
            }

            res.push_back(str);
        }

        for(int i=0; i<res.size(); i++) {
            string str = res[i];

            int hash = 0;

            for(int i=0; i<str.size(); i++) 
                hash += (str[i]-'a');
        
            hash = hash%26;

            ans += ('a' + hash);
        }

        return ans;
    }
};