/*
    You are given an array words of n strings. Each string has length m and contains only lowercase English letters. Two strings s and t are similar if we can apply the 
    following operation any number of times (possibly zero times) so that s and t become equal. Choose either s or t. Replace every letter in the chosen string with the next 
    letter in the alphabet cyclically. The next letter after 'z' is 'a'. Count the number of pairs of indices (i, j) such that: i < j, words[i] and words[j] are similar.
    Return an integer denoting the number of such pairs.

    Example 1:
    Input: words = ["fusion","layout"]
    Output: 1
    Explanation:
    words[0] = "fusion" and words[1] = "layout" are similar because we can apply the operation to "fusion" 6 times. The string "fusion" changes as follows.
    "fusion" -> "gvtjpo" -> "hwukqp" -> "ixvlrq" -> "jywmsr" -> "kzxnts" -> "layout"
*/

#include<bits/stdc++.h>
using namespace std;    

class Solution {
public:
    void normalise(string& s) {
        char ch = s[0];

        for(char& c : s) {
            c -= (ch - 'a');

            if(c < 'a')
                c += 26;
        }
    }

    long long countPairs(vector<string>& words) {
        int n = words.size();

        unordered_map<string, int> mp;
        mp.reserve(n);

        long long cnt = 0;

        for(auto i : words) {
            normalise(i);
            cnt += mp[i]++;
        }

        return cnt;
    }
};