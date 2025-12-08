/*
    A square triple (a,b,c) is a triple where a, b, and c are integers and a2 + b2 = c2. Given an integer n, return the number of square triples such that 1 <= a, b, c <= n.

    Example 1:
    Input: n = 5
    Output: 2
    Explanation: The square triples are (3,4,5) and (4,3,5).
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countTriples(int n) {
        int ans = 0;

        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                int c2 = a*a + b*b;
                int c = sqrt(c2);

                if (c <= n && c*c == c2) 
                    ans++;
            }
        }

        return ans;
    }
};