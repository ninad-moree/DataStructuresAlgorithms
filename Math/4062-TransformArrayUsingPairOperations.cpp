/*
    You are given two integer arrays source and target. In one operation, you may choose two distinct indices i and j in source, along with any integer delta. Then update 
    source as follows: source[i] = source[i] + source[j] - delta, source[j] = delta Return true if it is possible to make source equal to target after performing the operation 
    any (including zero) number of times. Otherwise, return false.

    Example 1:
    Input: source = [1,2,3], target = [0,2,4]
    Output: true
    Explanation: Choose indices i = 0 and j = 2, and set delta = 4. Before operation, source[0] = 1 and source[2] = 3. After the operation, source[0] = 1 + 3 - 4 = 0, source[2]
    = 4 Hence, source becomes [0, 2, 4], which is equal to target. Therefore, the answer is true.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        long long s1 = 0;
        long long s2 = 0;

        for(auto i : source)
            s1 += i;
        
        for(auto i : target)
            s2 += i;

        return s1 == s2;
    }
};