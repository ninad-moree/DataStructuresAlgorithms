/*
    You are given a positive integer n. Continuously replace n with the sum of its prime factors.  Note that if a prime factor divides n multiple 
    times, it should be included in the sum as many times as it divides n. Return the smallest value n will take on.

    Example 1:
    Input: n = 15
    Output: 5
    Explanation: Initially, n = 15.
    15 = 3 * 5, so replace n with 3 + 5 = 8.
    8 = 2 * 2 * 2, so replace n with 2 + 2 + 2 = 6.
    6 = 2 * 3, so replace n with 2 + 3 = 5.
    5 is the smallest value n will take on.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1)
            return false;
        if (n <= 3)
            return true;
        if (n % 2 == 0 || n % 3 == 0)
            return false;
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        }
        return true;
    }

    void primeFact(int n, vector<int>& pf) {
        while (n % 2 == 0) {
            pf.push_back(2);
            n /= 2;
        }
        for (int i = 3; i * i <= n; i += 2) {
            while (n % i == 0) {
                pf.push_back(i);
                n /= i;
            }
        }
        if (n > 2)
            pf.push_back(n);
    }

    int smallestValue(int n) {
        while (!isPrime(n)) {
            vector<int> v;
            primeFact(n, v);
            int sum = 0;
            for (int i = 0; i < v.size(); i++)
                sum += v[i];
            if (sum == n)
                break;
            n = sum;
        }
        return n;
    }
};
