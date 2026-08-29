/*
    You are given an n x m integer matrix matrix containing non-negative integers. A non-zero cell (row, col) checks the cells near it as follows: 
    Let x = matrix[row][col].  Consider every cell within x rows and x columns of (row, col). Ignore cells that are outside the matrix. Ignore the cells where both the row 
    distance and column distance are exactly x. The cell (row, col) is a local maximum if it is non-zero and no considered cell has a value greater than x. 
    Return an integer denoting the number of local maximums in matrix.

    ​​​​​​​Example 1:
    Input: matrix = [[0,0,0,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,2,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,0,0]]
    Output: 1
    Explanation: For the non-zero cell (3, 3), x = matrix[3][3] = 2. There are no other non-zero cells, so the answer is 1.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countLocalMaximums(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int ans = 0;

        unordered_map<int, vector<pair<int, int>>> mp;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++)
                mp[matrix[i][j]].push_back({i, j});
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                int x = matrix[i][j];
                int r = i;
                int c = j;

                if(x == 0)
                    continue;

                bool isMax = true;

                for(int val=x+1; val<=200 && isMax; val++) {
                    for(auto i : mp[val]) {
                        int nx = i.first;
                        int ny = i.second;

                        int dx = abs(nx - r);
                        int dy = abs(ny - c);

                        // inside cell within x rows and x columns of (row, col).
                        if(dx <= x && dy <= x) {
                            // cells where both the row distance and column distance are exactly x.
                            if(dx == x && dy == x)
                                continue;
                            
                            isMax = false;
                            break;
                        }
                    }
                }

                if(isMax)
                    ans++;
            }
        }

        return ans;
    }
};