/*
    An integer x is numerically balanced if for every digit d in the number x, there are exactly d occurrences of that digit in x. Given an integer n, return the smallest 
    numerically balanced number strictly greater than n.

    Example 1:
    Input: n = 1
    Output: 22
    Explanation:  22 is numerically balanced since: - The digit 2 occurs 2 times.  It is also the smallest numerically balanced number strictly greater than 1.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nextBeautifulNumber(int n) {
        n++;
        
        while(n <= 1224444) {
            vector<int> count(10);
            int num = n;

            while(num > 0) {
                int digit = num%10;
                num = num/10;
                count[digit]++;
            }
            
            bool ans = true;
            for(int i=0; i<10; i++) {
                if(count[i] > 0 && count[i] != i) {
                    ans = false;
                    break;
                }
            }

            if(ans)
                break;
            
            n++;
        }

        return n;
    }
};