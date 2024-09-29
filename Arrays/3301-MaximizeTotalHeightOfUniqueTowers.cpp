/*
    You are given an array maximumHeight, where maximumHeight[i] denotes the maximum height the ith tower can be assigned. Your task is to assign a 
    height to each tower so that: The height of the ith tower is a positive integer and does not exceed maximumHeight[i].
    No two towers have the same height. Return the maximum possible total sum of the tower heights. If it's not possible to assign heights, return -1.

    Example 1:
    Input: maximumHeight = [2,3,4,3]
    Output: 10
    Explanation: We can assign heights in the following way: [1, 2, 4, 3].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        sort(maximumHeight.rbegin(), maximumHeight.rend());

        for(int i=1; i<maximumHeight.size(); i++) 
            maximumHeight[i] = min(maximumHeight[i], maximumHeight[i-1] - 1);

        for(int i=1; i<maximumHeight.size(); i++) {
            if(maximumHeight[i] == maximumHeight[i-1] || maximumHeight[i]<=0)
                return -1;
        }

        long long sum = 0;
        for(int i=0; i<maximumHeight.size(); i++) 
            sum += maximumHeight[i];

        return sum;
    }
};