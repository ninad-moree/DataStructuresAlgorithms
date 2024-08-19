/*
    Geek wants to climb from the 0th stair to the (n-1)th stair. At a time the Geek can climb either one or two steps. A height[N] array is also 
    given. Whenever the geek jumps from stair i to stair j, the energy consumed in the jump is abs(height[i]- height[j]), where abs() means the 
    absolute difference. return the minimum energy that can be used by the Geek to jump from stair 0 to stair N-1.

    Example:
    Input: height = {10 20 30 10}
    Output: 20
    Explanation: Geek jump from 1st to 2nd stair(|20-10| = 10 energy lost). Then a jump from the 2nd to the last stair(|10-20| = 10 energy lost).
    so, total energy lost is 20 which is the minimum.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        if(n==1)
            return 0;
            
        vector<int> dp(n, 0);
        dp[0] = 0;
        dp[1] = abs(height[1] - height[0]);
        
        for(int i=2; i<height.size(); i++) {
            int one = dp[i-1] + abs(height[i] - height[i-1]);
            int two = dp[i-2] + abs(height[i] - height[i-2]);
            
            dp[i] = min(one, two);
        }
        
        return dp[n-1];
    } 
};