/*
    You are given an integer n. A number is called digitorial if the sum of the factorials of its digits is equal to the number itself. Determine whether any permutation of n 
    (including the original order) forms a digitorial number. Return true if such a permutation exists, otherwise return false. Note: The factorial of a non-negative integer x,
    denoted as x!, is the product of all positive integers less than or equal to x, and 0! = 1. A permutation is a rearrangement of all the digits of a number that does not 
    start with zero. Any arrangement starting with zero is invalid.

    Example 1:
    Input: n = 145
    Output: true
    Explanation: The number 145 itself is digitorial since 1! + 4! + 5! = 1 + 24 + 120 = 145. Thus, the answer is true.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> factorial() {
        vector<int> ans(10);
        ans[0] = 1;
        ans[1] = 1;

        for(int i=2; i<10; i++) 
            ans[i] = i * ans[i-1];

        return ans;
    }

    bool isDigitorialPermutation(int n) {
        vector<int> facts = factorial();

        int num = n;
        int factSum = 0;

        while(n) {
            int digit = n % 10;
            n = n/10;

            factSum += facts[digit];
        }

        vector<int> freqN(10, 0); 
        n = num; 
        
        while (n > 0) {
            freqN[n % 10]++;
            n /= 10;
        }

        vector<int> freqSum(10, 0);
        n = factSum;

        while (n > 0) {
            freqSum[n % 10]++;
            n /= 10;
        }

        return freqN == freqSum;
    }
};