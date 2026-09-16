/*
    You are given two integer arrays, technique1 and technique2, each of length n, where n represents the number of tasks to complete. If the ith task is completed using 
    technique 1, you earn technique1[i] points. If it is completed using technique 2, you earn technique2[i] points. You are also given an integer k, representing the minimum 
    number of tasks that must be completed using technique 1. You must complete at least k tasks using technique 1 (they do not need to be the first k tasks). The remaining 
    tasks may be completed using either technique. Return an integer denoting the maximum total points you can earn.

    Example 1:
    Input: technique1 = [5,2,10], technique2 = [10,3,8], k = 2
    Output: 22
    Explanation: We must complete at least k = 2 tasks using technique1. Choosing technique1[1] and technique1[2] (completed using technique 1), and technique2[0] (completed 
    using technique 2), yields the maximum points: 2 + 10 + 10 = 22.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        int n = technique1.size();
        long long sum = 0;

        vector<int> diff(n);

        for(int i=0; i<n; i++) {
            sum += technique2[i];

            diff[i] = technique1[i] - technique2[i];
        }

        sort(diff.rbegin(), diff.rend());

        for(int i=0; i<n; i++) {
            if(i < k || diff[i] > 0) 
                sum += diff[i];
        }

        return sum;
    }
};