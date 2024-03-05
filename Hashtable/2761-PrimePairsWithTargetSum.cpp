/*
    You are given an integer n. We say that two integers x and y form a prime number pair if:
        1 <= x <= y <= n
        x + y == n
        x and y are prime numbers
    Return the 2D sorted list of prime number pairs [xi, yi]. The list should be sorted in increasing order of xi. 
    If there are no prime number pairs at all, return an empty array.
    Note: A prime number is a natural number greater than 1 with only two factors, itself and 1.

    Example 1:
    Input: n = 10
    Output: [[3,7],[5,5]]
    Explanation: In this example, there are two prime pairs that satisfy the criteria. 
    These pairs are [3,7] and [5,5], and we return them in the sorted order as described in the problem statement.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<vector<int>> ans;

        vector<bool> isPrime(n + 1, true);

        // Sieve of Eratosthenes to find primes up to n
        for (long long i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (long long j = i * i; j <= n; j += i)
                    isPrime[j] = false;
            }
        }

        unordered_map<int, int> mp;

        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) 
                mp[i]++;
        }

        for(auto i : mp) {
            int prime = i.first;
            int count = i.second;
            int complement = n - prime;
            if (mp.find(complement) != mp.end()) {
                if (count > 0 && mp[complement] > 0) {
                    if(complement > prime)
                        ans.push_back({prime, complement});
                    else
                        ans.push_back({complement, prime});
                    mp[prime]--;
                    mp[complement]--;
                }
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};