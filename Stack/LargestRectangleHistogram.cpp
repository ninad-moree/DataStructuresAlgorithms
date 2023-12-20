/*
    Given an array of integers heights representing the histogram's bar height where the width of 
    each bar is 1, return the area of the largest rectangle in the histogram.

    Input: heights = [2,1,5,6,2,3]
    Output: 10
    Explanation: The above is a histogram where width of each bar is 1.
    The largest rectangle is shown in the red area, which has an area = 10 units.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextSmallestElement(vector<int> &arr, int size) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(size);

        for(int i=size-1;i>=0;i--) {
            int curr = arr[i];
            while(s.top()!=-1 && arr[s.top()] >= curr)
                s.pop();
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }

    vector<int> prevSmallestElement(vector<int> &arr, int size) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(size);

        for(int i=0;i<size;i++) {
            int curr = arr[i];
            while(s.top()!=-1 && arr[s.top()] >= curr)
                s.pop();
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> next(n);
        next = nextSmallestElement(heights, n);

        vector<int> prev(n);
        prev = prevSmallestElement(heights, n);

        int area = 0;
        for(int i=0;i<n;i++) {
            int l = heights[i];

            if(next[i]==-1) next[i]=n;

            int b = next[i]-prev[i]-1;

            int newArea = l*b;
            area = max(area, newArea);
        }
        return area;
    }
};