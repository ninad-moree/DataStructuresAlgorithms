/*
    You are given an integer array nums, where nums[i] represents the points scored in the ith game. There are exactly two players. Initially, the first player is active and 
    the second player is inactive. The following rules apply sequentially for each game i: If nums[i] is odd, the active and inactive players swap roles. In every 6th game 
    (that is, game indices 5, 11, 17, ...), the active and inactive players swap roles. The active player plays the ith game and gains nums[i] points. Return the score 
    difference, defined as the first player's total score minus the second player's total score.

    Example 1:
    Input: nums = [1,2,3]
    Output: 0
    Explanation:​​​​​​​ Game 0: Since the points are odd, the second player becomes active and gains nums[0] = 1 point. Game 1: No swap occurs. The second player gains nums[1] = 2 
    points. Game 2: Since the points are odd, the first player becomes active and gains nums[2] = 3 points. The score difference is 3 - 3 = 0.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int p1 = 0;
        int p2 = 0;
        bool isP1 = true;

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] % 2 == 1) 
                isP1 = !isP1;

            if(i % 6 == 5)
                isP1 = !isP1;

            if (isP1) 
                p1 += nums[i]; 
            else 
                p2 += nums[i];
        }

        return p1 - p2;
    }
};