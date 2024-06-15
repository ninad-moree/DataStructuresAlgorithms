/*
    You are given an m x n matrix grid consisting of positive integers. Perform the following operation until grid becomes empty:
    Delete the element with the greatest value from each row. If multiple such elements exist, delete any of them.
    Add the maximum of deleted elements to the answer.
    Return the answer after performing the operations described above.

    Example 1:
    Input: grid = [[1,2,4],[3,3,1]]
    Output: 8
    Explanation: The diagram above shows the removed values in each step.
    - In the first operation, we remove 4 from the first row and 3 from the second row (notice that, there are two cells with value 3 and we can 
    remove any of them). We add 4 to the answer.
    - In the second operation, we remove 2 from the first row and 3 from the second row. We add 3 to the answer.
    - In the third operation, we remove 1 from the first row and 1 from the second row. We add 1 to the answer.
    The final answer = 4 + 3 + 1 = 8.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        for(int i=0; i<grid.size(); i++)
            sort(grid[i].begin(), grid[i].end());
        
        int ans = 0;

        for(int col = grid[0].size()-1; col>=0; col--) {
            int maxi = INT_MIN;
            for(int row = 0; row<grid.size(); row++) 
                maxi = max(maxi, grid[row][col]);
            ans += maxi;
        }

        return ans;
    }
};