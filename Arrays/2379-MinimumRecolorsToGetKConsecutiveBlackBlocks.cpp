/*
    You are given a 0-indexed string blocks of length n, where blocks[i] is either 'W' or 'B', representing the color of the ith block. The characters 'W'
    and 'B' denote the colors white and black, respectively. You are also given an integer k, which is the desired number of consecutive black blocks.
    In one operation, you can recolor a white block such that it becomes a black block. Return the minimum number of operations needed such that there is 
    at least one occurrence of k consecutive black blocks.

    Example 1:
    Input: blocks = "WBBWWBBWBW", k = 7
    Output: 3
    Explanation:
    One way to achieve 7 consecutive black blocks is to recolor the 0th, 3rd, and 4th blocks so that blocks = "BBBBBBBWBW". 
    It can be shown that there is no way to achieve 7 consecutive black blocks in less than 3 operations. Therefore, we return 3.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans = INT_MAX;

        int cnt = 0;
        for(int i=0; i<k; i++) {
            if(blocks[i] == 'W')
                cnt++;
        }

        ans = min(ans, cnt);

        for(int i=k; i<blocks.size(); i++) {
            char f = blocks[i - k];
            char n = blocks[i]; 

            if(f == 'W')
                cnt--;
            if(n == 'W')
                cnt++;

            ans = min(ans, cnt);
        } 

        return ans;
    }
};