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
    vector<int> nextSmallestElement(vector<int> &arr, int size) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(size);

        for(int i = size - 1; i >= 0; i--) {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr)
                s.pop();
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    vector<int> prevSmallestElement(vector<int> &arr, int size) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(size);

        for(int i = 0; i < size; i++) {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr)
                s.pop();
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int> heights) {
        int n = heights.size();

        vector<int> next(n);
        next = nextSmallestElement(heights, n);

        vector<int> prev(n);
        prev = prevSmallestElement(heights, n);

        int area = 0;
        for(int i = 0; i < n; i++) {
            int l = heights[i];

            if (next[i] == -1) 
                next[i] = n;

            int b = next[i] - prev[i] - 1;

            int newArea = l * b;
            area = max(area, newArea);
        }
        return area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;

        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> heights(m, vector<int>(n, 0));

        // Calculate heights based on the matrix
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    if (i > 0)
                        heights[i][j] = heights[i - 1][j] + 1;
                    else
                        heights[i][j] = 1;
                }
            }
        }

        int area = largestRectangleArea(heights[0]);

        for(int i = 1; i < m; i++) {
            area = max(area, largestRectangleArea(heights[i]));
        }
        return area;
    }
};