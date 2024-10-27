/*
    Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

    Example 1:
    Input: matrix =
    [
        [0,1,1,1],
        [1,1,1,1],
        [0,1,1,1]
    ]
    Output: 15
    Explanation: 
    There are 10 squares of side 1.
    There are 4 squares of side 2.
    There is  1 square of side 3.
    Total number of squares = 10 + 4 + 1 = 15.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int ans = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                int maxi = min(m-i, n-j);

                for(int k=1; k<=maxi; k++) {
                    bool ones = true;

                    for(int x=0; x<k; x++) {
                        for(int y=0; y<k; y++) {
                            if(matrix[i+x][j+y] != 1) {
                                ones = false;
                                break;
                            }
                        }
                        if(!ones)
                            break;
                    }   

                    if(ones)
                        ans++;
                    else
                        break;
                }
            }
        }

        return ans;
    }
};