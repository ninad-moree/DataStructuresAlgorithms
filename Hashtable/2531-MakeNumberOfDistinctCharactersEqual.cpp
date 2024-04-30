/*
    You are given two 0-indexed strings word1 and word2.
    A move consists of choosing two indices i and j such that 0 <= i < word1.length and 0 <= j < word2.length and swapping word1[i] with word2[j].
    Return true if it is possible to get the number of distinct characters in word1 and word2 to be equal with exactly one move. Return false otherwise.

    Example 1:
    Input: word1 = "ac", word2 = "b"
    Output: false
    Explanation: Any pair of swaps would yield two distinct characters in the first string, and one in the second string.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isItPossible(string word1, string word2) {
        vector<int> m1(26, 0);
        vector<int> m2(26, 0);

        for(auto i : word1)
            m1[i - 'a']++;

        for(auto i : word2)
            m2[i - 'a']++;

        for(int i=0; i<26; i++) {
            for(int j=0; j<26; j++) {
                if(m1[i] != 0 && m2[j] != 0) {
                    m1[i]--;
                    m2[j]--;
                    m1[j]++;
                    m2[i]++;

                    int cnt1 = 0;
                    int cnt2 = 0;

                    for(auto k : m1) {
                        if(k > 0)
                            cnt1++;
                    }

                    for(auto k : m2) {
                        if(k > 0)
                            cnt2++;
                    }

                    if(cnt1 == cnt2)
                        return true;
                    
                    m1[i]++;
                    m2[j]++;
                    m1[j]--;
                    m2[i]--;
                }
            }
        }

        return false;
    }
};