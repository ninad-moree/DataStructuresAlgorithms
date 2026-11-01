/*
    You are given two integers n and s. Consider all prime numbers less than or equal to n. Select some of these primes such that: The sum of the selected primes is less than or
    equal to s. The number of selected primes is maximized. Each prime can be selected at most once. Return an integer array containing the selected primes in increasing order.
    If multiple optimal selections exist, return any of them. If no prime can be selected, return an empty array.

    Example 1:
    Input: n = 7, s = 20
    Output: [2,3,5,7]
    Explanation: The prime numbers less than or equal to n = 7 are 2, 3, 5, and 7. The sum of all these primes is 2 + 3 + 5 + 7 = 17, which is less than or equal to s = 20.
    Thus, the answer is [2, 3, 5, 7].
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

    vector<int> maxPrimes(int n, int s) {
        vector<int> ans;

        vector<bool> primes = isPrime(n);

        int sum = 0;
        for(int i=0; i<primes.size(); i++) {
            if(primes[i]) {
                if(sum + i > s)
                    break;
                sum += i;
                ans.push_back(i);
            }
        }

        return ans;
    }
};