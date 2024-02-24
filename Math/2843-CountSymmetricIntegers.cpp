/*
    You are given two positive integers low and high.
    An integer x consisting of 2 * n digits is symmetric if the sum of the first n digits of x is equal to 
    the sum of the last n digits of x. Numbers with an odd number of digits are never symmetric.
    Return the number of symmetric integers in the range [low, high].

    Example 1:
    Input: low = 1, high = 100
    Output: 9
    Explanation: There are 9 symmetric integers between 1 and 100: 11, 22, 33, 44, 55, 66, 77, 88, and 99.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;

        for(int i=low;i<=high;i++) {
            string str = to_string(i);
            int n = str.size();

            if(n%2==1)
                continue;
            else {
                int m = n/2;
                
                int a = 0;
                int b = 0;

                for(int i=0;i<m;i++) {
                    int c =  str[i] - '0';
                    a += c;
                }

                for(int i=m;i<str.size();i++) {
                    int c =  str[i] - '0';
                    b += c;
                }

                if(a == b)
                    ans++;
            }
        }

        return ans;
    }
};