/*
    There are n soldiers standing in a line. Each soldier is assigned a unique rating value. You have to form a team of 3 soldiers amongst them under 
    the following rules: Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
    A team is valid if: (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).
    Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).

    Example 1:
    Input: rating = [2,5,3,4,1]
    Output: 3
    Explanation: We can form three teams given the conditions. (2,3,4), (5,4,1), (5,3,1). 
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans = 0;
        int n = rating.size();

        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                for(int k=j+1; k<n; k++) {
                    int r1 = rating[i];
                    int r2 = rating[j];
                    int r3 = rating[k];

                    if((r1>r2 && r2>r3) || (r1<r2 && r2<r3))
                        ans++;
                }
            }
        }

        return ans;
    }
};