/*
    You are given a positive integer n, representing an n x n city. You are also given a 2D grid buildings, where buildings[i] = [x, y] denotes a unique building located at 
    coordinates [x, y]. A building is covered if there is at least one building in all four directions: left, right, above, and below.
    Return the number of covered buildings.

    Input: n = 3, buildings = [[1,2],[2,2],[3,2],[2,1],[2,3]]
    Output: 1

    Explanation:
    Only building [2,2] is covered as it has at least one building:
    above ([1,2]) below ([3,2]) left ([2,1]) right ([2,3]) Thus, the count of covered buildings is 1.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int ans = 0;
        
        vector<int> minRow(n+1, n+1);
        vector<int> maxRow(n+1);
        vector<int> minCol(n+1, n+1);
        vector<int> maxCol(n+1);

        for(auto i : buildings) {
            int x = i[0];
            int y = i[1];

            maxRow[y] = max(maxRow[y], x);
            minRow[y] = min(minRow[y], x);
            maxCol[x] = max(maxCol[x], y);
            minCol[x] = min(minCol[x], y);
        }

        for(auto i : buildings) {
            int x = i[0];
            int y = i[1];

            if(x > minRow[y] && x < maxRow[y] && y > minCol[x] && y < maxCol[x])
                ans++;
        }

        return ans;
    }
};