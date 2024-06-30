/*
    You are given two integers red and blue representing the count of red and blue colored balls. You have to arrange these balls to 
    form a triangle such that the 1st row will have 1 ball, the 2nd row will have 2 balls, the 3rd row will have 3 balls, and so on.
    All the balls in a particular row should be the same color, and adjacent rows should have different colors.
    Return the maximum height of the triangle that can be achieved.

    Example 1:
    Input: red = 2, blue = 4
    Output: 3
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int red, int blue) {
        int height = 0;
        bool flag = true;
        int lvl = 1;

        while(red>0 || blue>0) {
            if(flag) {
                if(red >= lvl)
                    red = red - lvl;
                else
                    break;
            } else {
                if(blue >= lvl)
                    blue = blue - lvl;
                else
                    break;
            }
            height++;
            lvl++;
            flag = !flag;
        }

        return height;
    }

    int maxHeightOfTriangle(int red, int blue) {
        int h1 = solve(red, blue);
        int h2 = solve(blue, red);
        return max(h1, h2);
    }
};