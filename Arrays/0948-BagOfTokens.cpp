/*
    You start with an initial power of power, an initial score of 0, and a bag of tokens given as an integer array tokens, where each 
    tokens[i] donates the value of tokeni.
    Your goal is to maximize the total score by strategically playing these tokens. In one move, you can play an unplayed token in one 
    of the two ways (but not both for the same token):
    Face-up: If your current power is at least tokens[i], you may play tokeni, losing tokens[i] power and gaining 1 score.
    Face-down: If your current score is at least 1, you may play tokeni, gaining tokens[i] power and losing 1 score.
    Return the maximum possible score you can achieve after playing any number of tokens.

    Example 1:
    Input: tokens = [100], power = 50
    Output: 0
    Explanation: Since your score is 0 initially, you cannot play the token face-down. You also cannot play it face-up since your power (50) 
    is less than tokens[0] (100).
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());

        int currPower = power;
        int score = 0;
        int maxScore = 0;

        int i = 0;
        int j = tokens.size()-1;

        while(i<=j) {
            if(currPower >= tokens[i]) {
                score++;
                currPower -= tokens[i];
                i++;
                maxScore = max(maxScore, score);
            } else if(score >= 1) {
                score--;
                currPower += tokens[j];
                j--;
            } else 
                break;
        }

        return maxScore;
    }
};