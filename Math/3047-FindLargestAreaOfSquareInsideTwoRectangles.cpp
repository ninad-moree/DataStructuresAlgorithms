/*
    There exist n rectangles in a 2D plane. You are given two 0-indexed 2D integer arrays bottomLeft and topRight, 
    both of size n x 2, where bottomLeft[i] and topRight[i] represent the bottom-left and top-right coordinates of 
    the ith rectangle respectively.
    You can select a region formed from the intersection of two of the given rectangles. You need to find the largest 
    area of a square that can fit inside this region if you select the region optimally.
    Return the largest possible area of a square, or 0 if there do not exist any intersecting regions between the rectangles.

    Example 1:
    Input: bottomLeft = [[1,1],[2,2],[3,1]], topRight = [[3,3],[4,4],[6,6]]
    Output: 1
    Explanation: A square with side length 1 can fit inside either the intersecting region of rectangle 0 and rectangle 1, 
    or the intersecting region of rectangle 1 and rectangle 2. Hence the largest area is side * side which is 1 * 1 == 1.
    It can be shown that a square with a greater side length can not fit inside any intersecting region.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        long long ans=0;

        for(int i=0;i<bottomLeft.size();i++){
            for(int j=i+1;j<bottomLeft.size();j++){
                long long x1 = max(bottomLeft[i][0], bottomLeft[j][0]);
                long long x2 = min(topRight[i][0], topRight[j][0]);
                long long y1 = max(bottomLeft[i][1], bottomLeft[j][1]);
                long long y2 = min(topRight[i][1], topRight[j][1]);
                
                if(x1<x2 && y1<y2){
                    long long s = min(x2-x1, y2-y1);
                    ans = max(ans, s*s);
                }
            }
        }

        return ans;
        // int ans = 0;
        // int n = bottomLeft.size();

        // for(int i=0 ; i<n; i++) {
        //     vector<int> bl1 = bottomLeft[i];
        //     vector<int> tr1 = topRight[i];

        //     for(int j=i+1; j<n; j++) {
        //         vector<int> bl2 = bottomLeft[j];
        //         vector<int> tr2 = topRight[j];

        //         if(bl2[0] >= tr1[0] || bl1[0] >= tr2[0])
        //             continue;
        //         if(bl2[1] >= tr1[1] || bl1[1] >= tr2[1])
        //             continue;

        //         int x1 = max(bl1[0], bl2[0]);
        //         int y1 = max(bl1[1], bl2[1]);

        //         int x2 = min(tr1[0], tr2[0]);
        //         int y2 = min(tr1[1], tr2[1]);

        //         int edge1 = x2-x1;
        //         int edge2 = y2-y1;

        //         ans = max(ans, min(edge1, edge2));
        //     }
        // }

        // return static_cast<long long>(ans) * ans;
    }
};