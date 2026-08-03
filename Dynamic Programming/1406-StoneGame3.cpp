/*
    Alice and Bob continue their games with piles of stones. There are several stones arranged in a row, and each stone has an associated value which is an integer given in the 
    array stoneValue. Alice and Bob take turns, with Alice starting first. On each player's turn, that player can take 1, 2, or 3 stones from the first remaining stones in the 
    row. The score of each player is the sum of the values of the stones taken. The score of each player is 0 initially. The objective of the game is to end with the highest 
    score, and the winner is the player with the highest score and there could be a tie. The game continues until all the stones have been taken. Assume Alice and Bob play 
    optimally. Return "Alice" if Alice will win, "Bob" if Bob will win, or "Tie" if they will end the game with the same score.

    Example 1:
    Input: stoneValue = [1,2,3,7]
    Output: "Bob"
    Explanation: Alice will always lose. Her best move will be to take three piles and the score become 6. Now the score of Bob is 7 and Bob wins.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int idx, vector<int>& stoneValue, vector<int>& dp) {
        if(idx >= stoneValue.size())
            return 0;

        if(dp[idx] != INT_MIN)
            return dp[idx];

        int alice = INT_MIN;
        int sum = 0;

        for(int i=0; i<3 && idx + i < stoneValue.size(); i++) {
            sum += stoneValue[idx+i];

            // whatever I take, minus the best the opponent can do from here on
            alice = max(alice, sum - solve(idx+i+1, stoneValue, dp));
        }

        return dp[idx] = alice;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int total = 0;

        for(auto i : stoneValue)
            total += i;

        vector<int> dp(n, INT_MIN);
        
        int ans = solve(0, stoneValue, dp); // Alice's score - Bob's score

        if(ans  == 0)
            return "Tie";
        return ans > 0  ? "Alice" : "Bob";
    }
};
