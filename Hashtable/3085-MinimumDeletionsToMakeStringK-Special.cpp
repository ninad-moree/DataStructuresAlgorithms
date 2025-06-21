/*
    You are given a string word and an integer k.
    We consider word to be k-special if |freq(word[i]) - freq(word[j])| <= k for all indices i and j in the string.
    Here, freq(x) denotes the frequency of the character x in word, and |y| denotes the absolute value of y.
    Return the minimum number of characters you need to delete to make word k-special.

    Example 1:
    Input: word = "aabcaba", k = 0
    Output: 3
    Explanation: We can make word 0-special by deleting 2 occurrences of "a" and 1 occurrence of "c". Therefore, word becomes equal to "baba" where 
    freq('a') == freq('b') == 2.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<int, long long> mp;
        for(auto i : word)
            mp[i]++;
        
        int cnt = word.size();

        for(auto i : mp) {
            int del = 0;

            for(auto j : mp) {
                if(i.second > j.second)
                    del += j.second;
                else if(j.second > i.second + k)
                    del += j.second - (i.second + k);
            }

            cnt = min(cnt, del);
        }

        return cnt;
    }
};