/*
    Given an array of non-negative integers arr, you are initially positioned at start index of the array. When you are at index i, you can jump to i + arr[i] or i - arr[i], 
    check if you can reach any index with value 0. Notice that you can not jump outside of the array at any time.

    Example 1:
    Input: arr = [4,2,3,0,3,1,2], start = 5
    Output: true
    Explanation:  All possible ways to reach at index 3 with value 0 are:  index 5 -> index 4 -> index 1 -> index 3, index 5 -> index 6 -> index 4 -> index 1 -> index 3 
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int x, vector<int>& arr, vector<int>& vis) {
        if(arr[x] == 0)
            return true;
        
        if(vis[x])
            return false;

        vis[x] = 1;
        
        int dx[] = {-arr[x], arr[x]};

        for(int i=0; i<2; i++) {
            int nx = x + dx[i];

            if(nx >= 0 && nx < arr.size()) {
                if(dfs(nx, arr, vis))    
                    return true;
            }
        }

        return false;
    }

    bool canReach(vector<int>& arr, int start) {
        vector<int> vis(arr.size());
        return dfs(start, arr, vis);
    }
};