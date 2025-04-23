/*
    The beauty of a string is the difference in frequencies between the most frequent and least frequent characters. For example, the beauty of 
    "abaacc" is 3 - 1 = 2. Given a string s, return the sum of beauty of all of its substrings.

    Example 1:
    Input: s = "aabcb"
    Output: 5
    Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int beautySum(string s) {
        int ans = 0;

        for(int i=0; i<s.size(); i++) {
            vector<int> freq(26, 0);

            for(int j=i; j<s.size(); j++) {
                char ch = s[j];
                freq[ch - 'a']++;

                int maxi = 0;
                int mini = INT_MAX;

                for(int k=0; k<26; k++) {
                    if(freq[k] > 0) {
                        maxi = max(maxi, freq[k]);
                        mini = min(mini, freq[k]);
                    }
                }

                ans += (maxi - mini);
            }
        }

        return ans;
    }
};