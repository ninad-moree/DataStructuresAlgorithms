/*
    You are given a 2D integer array coordinates and an integer k, where coordinates[i] = [xi, yi] are the coordinates of the ith point in a 2D plane.
    We define the distance between two points (x1, y1) and (x2, y2) as (x1 XOR x2) + (y1 XOR y2) where XOR is the bitwise XOR operation.
    Return the number of pairs (i, j) such that i < j and the distance between points i and j is equal to k.

    Example 1:
    Input: coordinates = [[1,2],[4,2],[1,3],[5,2]], k = 5
    Output: 2
    Explanation: We can choose the following pairs:
    - (0,1): Because we have (1 XOR 4) + (2 XOR 2) = 5.
    - (2,3): Because we have (1 XOR 5) + (3 XOR 2) = 5.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
        map<pair<int,int>, int> mp;
        int cnt = 0;

        for(auto i : coordinates)
            mp[{i[0], i[1]}]++;

        for(int i=0;i<coordinates.size();i++) {
            int x1 = coordinates[i][0];
            int y1 = coordinates[i][1];

            mp[{x1,y1}]--;

            for(int j=0;j<=k;j++) {
                int x2 = x1^j;
                int y2 = (k-j)^y1;
                
                if(mp.find({x2,y2}) != mp.end())
                    cnt += mp[{x2,y2}];
            }
        }

        return cnt;
    }
};