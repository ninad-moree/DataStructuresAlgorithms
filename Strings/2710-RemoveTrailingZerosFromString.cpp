/*
    Given a positive integer num represented as a string, return the integer num without trailing zeros as a string.

    Example 1:
    Input: num = "51230100"
    Output: "512301"
    Explanation: Integer "51230100" has 2 trailing zeros, we remove them and return integer "512301".
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeTrailingZeros(string num) {
        string ans;

        int k = 0;

        for(int i=num.size()-1; i>=0; i--) {
            if(num[i] == '0')
                continue;
            else {
                k=i;
                break;
            }
        }

        ans = num.substr(0, k+1);

        return ans;
    }
};