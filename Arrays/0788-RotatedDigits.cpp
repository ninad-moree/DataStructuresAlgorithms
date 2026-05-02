/*
    An integer x is a good if after rotating each digit individually by 180 degrees, we get a valid number that is different from x. Each digit must be rotated - we cannot choose
    to leave it alone. A number is valid if each digit remains a digit after rotation. For example:
    0, 1, and 8 rotate to themselves, 2 and 5 rotate to each other (in this case they are rotated in a different direction, in other words, 2 or 5 gets mirrored),
    6 and 9 rotate to each other, and the rest of the numbers do not rotate to any other number and become invalid.
    Given an integer n, return the number of good integers in the range [1, n].

    Example 1:
    Input: n = 10
    Output: 4
    Explanation: There are four good numbers in the range [1, 10] : 2, 5, 6, 9. Note that 1 and 10 are not good numbers, since they remain unchanged after rotating.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rotMap = {0, 1, 5, -1, -1, 2, 9, -1, 8, 6};

    bool isValid(string num) {
        string ans = "";

        for(auto i : num) {
            int n = i - '0';  
            
            if(rotMap[n] == -1)  
                return false;
            
            ans += to_string(rotMap[n]);
        }

        return ans != num;
    }

    int rotatedDigits(int n) {
        int ans = 0;

        for(int i=1; i<=n; i++) {
            string num = to_string(i);

            if(isValid(num))
                ans++;
        }

        return ans;
    }
};