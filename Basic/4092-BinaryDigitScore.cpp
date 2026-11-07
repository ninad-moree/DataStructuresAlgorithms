/*
    You are given two integers a and b. Let s1 and s2 be the number of set bits in the binary representations of a and b, respectively. The score of these integers is defined 
    as follows: If s1 >= s2, the score is s1 * s2. Otherwise, the score is s2 / s1 using integer division. Return an integer representing the score of a and b.

    Example 1:
    Input: a = 14, b = 6
    Output: 6
    Explanation: The binary representation of a = 14 is "1110", so s1 = 3. The binary representation of b = 6 is "110", so s2 = 2. Since s1 > s2, the score of a and b is s1 * s2
    = 3 * 2 = 6.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int setBits(int num) {
        int ans = 0;

        while(num > 0) {
            int rem = num % 2;
            num = num / 2;

            if(rem == 1)
                ans++;
        }

        return ans;
    }

    int calculateScore(int a, int b) {
        int s1 = setBits(a);
        int s2 = setBits(b);

        if(s1 >= s2)
            return s1 * s2;

        return s2/s1; 
    }
};