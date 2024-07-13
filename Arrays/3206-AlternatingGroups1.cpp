/*
    There is a circle of red and blue tiles. You are given an array of integers colors. The color of tile i is represented by colors[i]:
    colors[i] == 0 means that tile i is red. colors[i] == 1 means that tile i is blue.
    Every 3 contiguous tiles in the circle with alternating colors (the middle tile has a different color from its left and right tiles)
    is called an alternating group. Return the number of alternating groups.
    Note that since colors represents a circle, the first and the last tiles are considered to be next to each other.

    Example 1:
    Input: colors = [1,1,1]
    Output: 0
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int ans = 0;
        int n = colors.size();

        for(int i=0; i<colors.size(); i++) {
            if(i>0 && i<n-1) {
                if(colors[i-1] == colors[i+1] && colors[i] != colors[i-1])
                    ans++;
            } else {
                if(i == 0) {
                    if(colors[n-1] == colors[i+1] && colors[i] != colors[i+1])
                        ans ++;
                } else if (i == n-1) {
                    if(colors[0] == colors[n-2] && colors[n-1] != colors[n-2])
                        ans++;
                }
            }
        }

        return ans;
    }
};