/*
    Given an integer num, return the number of digits in num that divide num. An integer val divides nums if nums % val == 0.

    Example 1:
    Input: num = 7
    Output: 1
    Explanation: 7 divides itself, hence the answer is 1.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDigits(int num) {
        string n = to_string(num);
        
        int ans = 0;
        for(int i=0; i<n.size(); i++) {
            string c = "";
            c += n[i];

            int d = stoi(c);

            if(num % d == 0)
                ans++;
        }

        return ans;
    }
};