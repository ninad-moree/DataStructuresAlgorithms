/*
    You are given a positive integer array of length 3. Determine if there exists a triangle with positive area whose three side lengths are given by the elements of sides.
    If such a triangle exists, return an array of three floating-point numbers representing its internal angles (in degrees), sorted in non-decreasing order. Otherwise, return 
    an empty array. Answers within 10-5 of the actual answer will be accepted.

    Example 1:
    Input: sides = [3,4,5]
    Output: [36.86990,53.13010,90.00000]
    Explanation: You can form a right-angled triangle with side lengths 3, 4, and 5. The internal angles of this triangle are approximately 36.869897646, 53.130102354, and 90 
    degrees respectively.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        int a = sides[0];
        int b = sides[1];
        int c = sides[2];

        if(a + b <= c || b + c <= a || c + a <= b)
            return {};

        // cos(A) = (b^2 + c^2 - a^2) / (2bc)
        double A = acos((b*b + c*c - a*a) / (2.0*b*c)) * 180 / M_PI;
        double B = acos((a*a + c*c - b*b ) / (2.0*a*c)) * 180 / M_PI;
        double C = acos((b*b + a*a - c*c) / (2.0*a*b)) * 180 / M_PI;

        vector<double> ans = {A, B, C};
        sort(ans.begin(), ans.end());

        return ans;
    }
};