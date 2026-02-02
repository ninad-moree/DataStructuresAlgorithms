/*
    Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

    Example 1:
    Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
    Output: 6
    Explanation: The maximal rectangle is shown in the above picture.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &histo) {
        stack<int> st; // Stack to store indices of the histogram bars
        int maxA = 0; 
        int n = histo.size();

        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
                int height = histo[st.top()]; 
                st.pop();

                int width;
                if (st.empty()) 
                    width = i; 
                else 
                    width = i - st.top() - 1; 
                
                maxA = max(maxA, width * height);
            }
            st.push(i);
        }
        return maxA;
    }


    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxArea = 0;
        vector<int> height(matrix[0].size(), 0);

        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[0].size(); j++) {
                if(matrix[i][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            }

            int area = largestRectangleArea(height);
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};