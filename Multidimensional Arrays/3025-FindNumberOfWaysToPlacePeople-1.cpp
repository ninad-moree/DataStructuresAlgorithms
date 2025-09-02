/*
    You are given a 2D array points of size n x 2 representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi]. We define 
    the right direction as positive x-axis (increasing x-coordinate) and the left direction as negative x-axis (decreasing x-coordinate). Similarly, we
    define the up direction as positive y-axis (increasing y-coordinate) and the down direction as negative y-axis (decreasing y-coordinate) You have to
    place n people, including Chisato and Takina, at these points such that there is exactly one person at every point. Chisato wants to be alone with 
    Takina, so Chisato will build a rectangular fence with Chisato's position as the upper left corner and Takina's position as the lower right corner 
    of the fence (Note that the fence might not enclose any area, i.e. it can be a line). If any person other than Chisato and Takina is either inside
    the fence or on the fence, Chisato will be sad. Return the number of pairs of points where you can place Chisato and Takina, such that Chisato does
    not become sad on building the fence. Note that Chisato can only build a fence with Chisato's position as the upper left corner, and Takina's 
    position as the lower right corner. 

    Example 1:
    Input: points = [[1,1],[2,2],[3,3]]
    Output: 0
    Explanation: There is no way to place Chisato and Takina such that Chisato can build a fence with Chisato's position as the upper 
    left corner and Takina's position as the lower right corner. Hence we return 0. 
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        auto compare = [] (vector<int>& a, vector<int>& b) {
            if(a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        };

        sort(points.begin(), points.end(), compare);

        int ans  = 0;

        for(int i=0; i<points.size(); i++) {
            for(int j=i+1; j<points.size(); j++) {
                if(points[i][1] >= points[j][1]) {
                    bool isTrue = true;

                    for(int k=i+1; k<j; k++) {
                        if(points[k][1] <= points[i][1] && points[k][1] >= points[j][1])
                            isTrue = false;
                    }

                    if(isTrue)
                        ans++;
                }
            }
        }

        return ans;
    }
};