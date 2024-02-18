/*
    There are several cards arranged in a row, and each card has an associated number of points. 
    The points are given in the integer array cardPoints.
    In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.
    Your score is the sum of the points of the cards you have taken.
    Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

    Example 1:
    Input: cardPoints = [1,2,3,4,5,6,1], k = 3
    Output: 12
    Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize 
    your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0;
        for(auto i : cardPoints)
            sum += i;

        int m = cardPoints.size() - k;
        int ans = 0;
        int windowSum = 0;
        
        for(int i=0;i<m;i++) 
            windowSum += cardPoints[i];

        ans = sum - windowSum;

        for (int i = m; i < cardPoints.size(); i++) {
            windowSum -= cardPoints[i - m];
            windowSum += cardPoints[i];
            ans = max(ans, sum - windowSum);
        }

        return ans;
    }
};