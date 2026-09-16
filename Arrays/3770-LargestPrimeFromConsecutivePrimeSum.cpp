/*
    You are given an integer n. Return the largest prime number less than or equal to n that can be expressed as the sum of one or more consecutive prime numbers starting from 
    2. If no such number exists, return 0.

    Example 1:
    Input: n = 20
    Output: 17
    Explanation: The prime numbers less than or equal to n = 20 which are consecutive prime sums are: 2 = 2, 5 = 2 + 3, 17 = 2 + 3 + 5 + 7.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> isPrime(int n) {
        vector<int> prime(n+1, 1);
        prime[0] = prime[1] = 0;

        for(int i=2; i*i <= n; i++) {
            if(prime[i]) {
                for(int j=i*i; j<=n; j+=i)
                    prime[j] = 0;
            }
        }

        return prime;
    }

    int largestPrime(int n) {
        vector<int> prime = isPrime(n);
        vector<int> primes;

        for(int i=2; i<prime.size(); i++) {
            if(prime[i])
                primes.push_back(i);
        }

        int ans = 0;
        int sum = 0;

        for(int i = 0; i < primes.size(); i++) {
            sum += primes[i];

            if(sum > n)
                break;

            if(prime[sum])
                ans = sum;
        }

        return ans;
    }
};