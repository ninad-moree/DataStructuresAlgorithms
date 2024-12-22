/*
    Given an integer, convert it to a roman numeral.

    Example 1:
    Input: num = 3
    Output: "III"
    Explanation: 3 is represented as 3 ones.

    Example 2:
    Input: num = 58
    Output: "LVIII"
    Explanation: L = 50, V = 5, III = 3.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        int integers[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string romans[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

        string ans;

        for(int i=0;i<13;i++) {
            while(num>=integers[i]) {
                ans.append(romans[i]);
                num = num - integers[i];
            }
        }
        return ans;
    }
};