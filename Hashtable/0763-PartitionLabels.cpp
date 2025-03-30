/*
    You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part. For 
    example, the string "ababcc" can be partitioned into ["abab", "cc"], but partitions such as ["aba", "bcc"] or ["ab", "ab", "cc"] are invalid.
    Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.
    Return a list of integers representing the size of these parts.

    Example 1:
    Input: s = "ababcbacadefegdehijhklij"
    Output: [9,7,8]
    Explanation: The partition is "ababcbaca", "defegde", "hijhklij". This is a partition so that each letter appears in at most one part.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> sizes;
        vector<int> lastIdx(26, 0);

        for(int i=0; i<s.size(); i++) 
            lastIdx[s[i] - 'a'] = i;

        int start = 0;
        int end = 0;

        for(int i=0; i<s.size(); i++) {
            end = max(end, lastIdx[s[i] - 'a']);

            if(i == end) {
                sizes.push_back(i - start + 1);
                start = i+1;
            }
        }

        return sizes;
    }
};