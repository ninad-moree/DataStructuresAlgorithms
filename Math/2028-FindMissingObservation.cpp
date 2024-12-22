/*
    You have observations of n + m 6-sided dice rolls with each face numbered from 1 to 6. n of the observations went missing, 
    and you only have the observations of m rolls. Fortunately, you have also calculated the average value of the n + m rolls.
    You are given an integer array rolls of length m where rolls[i] is the value of the ith observation. You are also given the 
    two integers mean and n.
    Return an array of length n containing the missing observations such that the average value of the n + m rolls is exactly mean. 
    If there are multiple valid answers, return any of them. If no such array exists, return an empty array.
    The average value of a set of k numbers is the sum of the numbers divided by k.

    Example 1:
    Input: rolls = [3,2,4,3], mean = 4, n = 2
    Output: [6,6]
    Explanation: The mean of all n + m rolls is (3 + 2 + 4 + 3 + 6 + 6) / 6 = 4.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int> ans;

        int m = rolls.size();
        int totalSum = mean*(n+m);

        int sum = 0;
        for(int i=0;i<m;i++)
            sum+=rolls[i];
        
        int ansSum = totalSum - sum;

        if (ansSum < n || ansSum > n * 6)
            return ans;

        int equalShare = ansSum / n;
        int remainder = ansSum % n;

        for (int i = 0; i < n; i++) {
            if (remainder > 0) {
                ans.push_back(equalShare + 1);
                remainder--;
            } else
                ans.push_back(equalShare);
        }

        return ans;
    }
};