/*
    You are given a 2D integer array matrix of size n x n representing the adjacency matrix of an undirected graph with n vertices labeled from 0 to n - 1. matrix[i][j] = 1 
    indicates that there is an edge between vertices i and j. matrix[i][j] = 0 indicates that there is no edge between vertices i and j. The degree of a vertex is the number of 
    edges connected to it. Return an integer array ans of size n where ans[i] represents the degree of vertex i.

    Example 1:
    Input: matrix = [[0,1,1],[1,0,1],[1,1,0]]
    Output: [2,2,2]
    Explanation: Vertex 0 is connected to vertices 1 and 2, so its degree is 2. Vertex 1 is connected to vertices 0 and 2, so its degree is 2. Vertex 2 is connected to vertices
    0 and 1, so its degree is 2. Thus, the answer is [2, 2, 2].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<int> ans(n);

        for(int i=0; i<n; i++) {
            int res = 0;

            for(int j=0; j<n; j++) 
                res += matrix[i][j];

            ans[i] = res;
        }

        return ans;
    }
};