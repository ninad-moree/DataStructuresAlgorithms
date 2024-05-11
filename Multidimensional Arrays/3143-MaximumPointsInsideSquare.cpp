/*
    You are given a 2D array points and a string s where, points[i] represents the coordinates of point i, and s[i] represents the tag of point i.
    A valid square is a square centered at the origin (0, 0), has edges parallel to the axes, and does not contain two points with the same tag.
    Return the maximum number of points contained in a valid square.
    Note:
    A point is considered to be inside the square if it lies on or within the square's boundaries. The side length of the square can be zero.
    
    Example 1:
    Input: points = [[2,2],[-1,-2],[-4,4],[-3,1],[3,-3]], s = "abdca"
    Output: 2
    Explanation:
    The square of side length 4 covers two points points[0] and points[1].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        int n = points.size();
        
        for(int i=0; i<n; i++) {
            points[i][0] = abs(points[i][0]);
            points[i][1] = abs(points[i][1]);
        }
        
        int l = 0;
        int r = 1e9;
        int res = 0;
        
        while(l <= r) {
            int mid = (l+r) /2;
            
            map<char, int> mp;
            bool isValid = true;
            
            for(int i=0; i<n; i++) {
                if(points[i][0] <= mid && points[i][1] <= mid)
                    mp[s[i]]++;
            }
            
            for(auto it : mp) {
                if(it.second > 1) {
                    isValid = false;
                    break;
                }
            }
            
            if(isValid) {
                res = mid;
                l = mid +1;
            } else 
                r = mid-1;
            
        }
        
        int cnt = 0;
        for(int i=0; i<n; i++) {
            if(points[i][0] <= res && points[i][1] <= res)
                cnt++;
        }
        
        return cnt;
    }
};