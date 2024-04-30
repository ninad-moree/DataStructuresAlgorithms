/*
    Given four integers length, width, height, and mass, representing the dimensions and mass of a box, respectively, return a string representing the category of the box.
    The box is "Bulky" if:
    Any of the dimensions of the box is greater or equal to 104.
    Or, the volume of the box is greater or equal to 109.
    If the mass of the box is greater or equal to 100, it is "Heavy".
    If the box is both "Bulky" and "Heavy", then its category is "Both".
    If the box is neither "Bulky" nor "Heavy", then its category is "Neither".
    If the box is "Bulky" but not "Heavy", then its category is "Bulky".
    If the box is "Heavy" but not "Bulky", then its category is "Heavy".

    Example 1:
    Input: length = 1000, width = 35, height = 700, mass = 300
    Output: "Heavy"
    Explanation: 
    None of the dimensions of the box is greater or equal to 104. 
    Its volume = 24500000 <= 109. So it cannot be categorized as "Bulky".
    However mass >= 100, so the box is "Heavy".
    Since the box is not "Bulky" but "Heavy", we return "Heavy".
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        string type;

        if( length >= 1e4 || width >= 1e4 || height >= 1e4 || (long long)length * width * height >= 1e9 ) {
            if( mass < 100)
                type = "Bulky";
            if( mass >= 100)
                type = "Both";
        }
        else if (mass >= 100) 
            type = "Heavy";
        else 
            type = "Neither";

        return type;
    }
};