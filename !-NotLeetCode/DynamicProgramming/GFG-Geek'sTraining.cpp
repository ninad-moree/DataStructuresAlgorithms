/*
    Geek is going for a training program. He can perform any of these activities: Running, Fighting, and Learning Practice. Each activity has some 
    point on each day. As Geek wants to improve all his skills, he can't do the same activity on two consecutive days. Help Geek to maximize his 
    merit points as you are given a 2D array of points arr, corresponding to each day and activity.

    Example:
    Input: n=3 and arr[]= [[1,2,5],[3,1,1],[3,3,3]]
    Output:11
    Explanation:Geek will learn a new move and earn 5 point then on second day he will do running and earn 3 point and on third day he will do 
    fighting and earn 3 points so, maximum point is 11.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr, int n) {
        vector<vector<int>> dp(n, vector<int>(3));
        
        for(int i=0; i<3; i++)
            dp[n-1][i] = arr[n-1][i];
            
        for(int i=n-2; i>=0; i--) {
            for(int j=0; j<3; j++) {
                if(j == 0) {
                    dp[i][j] = arr[i][j] + max(dp[i+1][j+1], dp[i+1][j+2]);
                } else if(j == 1)
                    dp[i][j] = arr[i][j] + max(dp[i+1][j-1], dp[i+1][j+1]);
                else
                    dp[i][j] = arr[i][j] + max(dp[i+1][j-1], dp[i+1][j-2]);
            }
        }
        
        int ans = max(dp[0][0], max(dp[0][1], dp[0][2]));
        return ans;
    }
};