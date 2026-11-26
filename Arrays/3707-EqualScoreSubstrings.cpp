/*
    You are given a string s consisting of lowercase English letters. The score of a string is the sum of the positions of its characters in the alphabet, where 'a' = 1, 
    'b' = 2, ..., 'z' = 26. Determine whether there exists an index i such that the string can be split into two non-empty substrings s[0..i] and s[(i + 1)..(n - 1)] that have 
    equal scores. Return true if such a split exists, otherwise return false.

    Example 1:
    Input: s = "adcb"
    Output: true
    Explanation: Split at index i = 1: Left substring = s[0..1] = "ad" with score = 1 + 4 = 5. Right substring = s[2..3] = "cb" with score = 3 + 2 = 5
    Both substrings have equal scores, so the output is true.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool scoreBalance(string s) {
        vector<int> arr;
        int sum = 0;

        for(int i=0; i<s.size(); i++) {
            int n = s[i] - 'a' + 1;
            sum += n;
            arr.push_back(n);
        }

        int curr = 0;
        for(int i=0; i<arr.size(); i++) {
            curr += arr[i];

            if(curr == sum - curr)
                return true;
        }

        return false;
    }
};