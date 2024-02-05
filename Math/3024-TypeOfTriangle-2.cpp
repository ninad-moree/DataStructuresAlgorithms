/*
    You are given a 0-indexed integer array nums of size 3 which can form the sides of a triangle.
    A triangle is called equilateral if it has all sides of equal length.
    A triangle is called isosceles if it has exactly two sides of equal length.
    A triangle is called scalene if all its sides are of different lengths.
    Return a string representing the type of triangle that can be formed or "none" if it cannot form a triangle.

    Example 1:
    Input: nums = [3,3,3]
    Output: "equilateral"
    Explanation: Since all the sides are of equal length, therefore, it will form an equilateral triangle.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string triangleType(vector<int>& nums) {
        int l1 = nums[0];
        int l2 = nums[1];
        int l3 = nums[2];

        if(l1+l2 <= l3 || l2+l3 <= l1 || l3+l1 <= l2)
            return "none";
        
        if(l1==l2 && l2==l3)
            return "equilateral";

        if(l1==l2 || l2==l3 || l3==l1)
            return "isosceles";

        return "scalene";
    }
};