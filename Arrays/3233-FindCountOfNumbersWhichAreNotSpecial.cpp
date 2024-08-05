/*
    You are given 2 positive integers l and r. For any number x, all positive divisors of x except x are called the proper divisors of x.
    A number is called special if it has exactly 2 proper divisors. For example:
    The number 4 is special because it has proper divisors 1 and 2. The number 6 is not special because it has proper divisors 1, 2, and 3.
    Return the count of numbers in the range [l, r] that are not special.

    Example 1:
    Input: l = 5, r = 7
    Output: 3
    Explanation: There are no special numbers in the range [5, 7].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> isPrime(int r) {
        vector<bool> isPrimeNum(r + 1, true);
        isPrimeNum[0] = isPrimeNum[1] = false;

        for (int p = 2; p * p <= r; p++) {
            if (isPrimeNum[p]) {
                for (int i = p * p; i <= r; i += p) 
                    isPrimeNum[i] = false;
            }
        }

        return isPrimeNum;
    }
    
    int nonSpecialCount(int l, int r) {
        int sr = sqrt(r);
        vector<bool> prime = isPrime(sr);

        int ans = 0;
        
        for(int i=2; i<=sr; i++) {
            if(prime[i]) {
                int sq = i*i;
                if(sq >=l && sq <=r)
                    ans++;
            }
        }

        int total = r-l+1;

        return total - ans;
    }

};