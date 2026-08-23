/*
    You are given a string s consisting of lowercase English letters. You can perform the following operations any number of times (including zero) and in any order:
    Increment: Choose any index i and replace s[i] with the next lowercase English letter. The letter after 'z' is 'a'. Left rotate: Move the first character of the string to 
    the end. Return the minimum number of operations required to make s a palindrome.

    Example 1:
    Input: s = "abc"
    Output: 2
    Explanation: One optimal solution: Left rotate the string: "abc" -> "bca". Increment 'a' to 'b': "bca" -> "bcb". "bcb" is a palindrome. Thus, the answer is 2.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getCost(char a, char b) {
        int x = abs(a - b);
        return min(x, 26 - x);
    }
    
    int minOperations(string s) {
        int ans = INT_MAX;
        int n = s.size();

        for(int rotation =0; rotation <n; rotation ++) {
            int cost = rotation;

            for(int i=0; i<n/2; i++)
                cost += getCost(s[i], s[n-1-i]);

            ans = min(ans, cost);

            rotate(s.begin(), s.begin()+1, s.end());
        }

        return ans;
    }
};