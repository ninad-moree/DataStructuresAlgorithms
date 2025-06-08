/*
    Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order. You must write an algorithm that runs in 
    O(n) time and uses O(1) extra space. 

    Example 1:
    Input: n = 13
    Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;

        for(int i=1; i<=9; i++)
            solve(i, n, ans);

        return ans;
    }

    void solve(int curr, int limit, vector<int>& num) {
        if(curr > limit)
            return;

        num.push_back(curr);

        for(int i=0; i<=9; i++) {
            int next = curr*10 + i;

            if(next <= limit)
                solve(next, limit, num);
            else
                break;
        }
    }
};