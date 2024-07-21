/*
    You are given a positive integer array skill of even length n where skill[i] denotes the skill of the ith player. Divide the players into 
    n / 2 teams of size 2 such that the total skill of each team is equal. The chemistry of a team is equal to the product of the skills of the 
    players on that team. Return the sum of the chemistry of all the teams, or return -1 if there is no way to divide the players into teams such 
    that the total skill of each team is equal.

    Example 1:
    Input: skill = [3,2,5,1,3,4]
    Output: 22
    Explanation: 
    Divide the players into the following teams: (1, 5), (2, 4), (3, 3), where each team has a total skill of 6.
    The sum of the chemistry of all the teams is: 1 * 5 + 2 * 4 + 3 * 3 = 5 + 8 + 9 = 22.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long ans = -1;

        sort(skill.begin(), skill.end());

        bool isPossile = true;
        int curr = skill[0] + skill[skill.size()-1];
        ans = skill[0] * skill[skill.size()-1];;

        for(int i=1; i<skill.size()/2; i++) {
            if(curr !=  skill[i] + skill[skill.size()-i-1]) {
                ans = -1;
                break;
            }
                
            ans += (skill[i] * skill[skill.size()-i-1]);
        }

        return ans;
    } 
};