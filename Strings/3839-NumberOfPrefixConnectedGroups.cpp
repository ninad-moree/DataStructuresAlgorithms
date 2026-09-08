/*
    You are given an array of strings words and an integer k. Two words a and b at distinct indices are prefix-connected if a[0..k-1] == b[0..k-1]. A connected group is a set 
    of words such that each pair of words is prefix-connected. Return the number of connected groups that contain at least two words, formed from the given words. Note:
    Words with length less than k cannot join any group and are ignored. Duplicate strings are treated as separate words.
    
    Example 1:
    Input: words = ["apple","apply","banana","bandit"], k = 2
    Output: 2
    Explanation: Words sharing the same first k = 2 letters are grouped together: words[0] = "apple" and words[1] = "apply" share prefix "ap". words[2] = "banana" and words[3] 
    = "bandit" share prefix "ba". Thus, there are 2 connected groups, each containing at least two words.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        int n = words.size();
        sort(words.begin(), words.end());

        if(words.size() <= 1)
            return 0;

        int ans = 0;
        int i = 0;

        while (i < n) {
            if (words[i].size() < k) {
                i++;
                continue;
            }

            string prefix = words[i].substr(0, k);

            int j = i + 1;

            while (j < n && words[j].size() >= k && words[j].substr(0, k) == prefix) 
                j++;

            if (j - i >= 2)
                ans++;

            i = j;
        }

        return ans;
    }
};