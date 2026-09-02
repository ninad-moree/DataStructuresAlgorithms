/*
    You are given an integer n. Let r be the integer formed by reversing the digits of n. Return the sum of all prime numbers between min(n, r) and max(n, r), inclusive.

    Example 1:
    Input: n = 13
    Output: 132
    Explanation: The reverse of 13 is 31. Thus, the range is [13, 31]. The prime numbers in this range are 13, 17, 19, 23, 29, and 31.
    The sum of these prime numbers is 13 + 17 + 19 + 23 + 29 + 31 = 132.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverseNum(int n) {
        string s = to_string(n);
        reverse(s.begin(), s.end());
        int res = stoi(s);

        return res;
    }

    vector<int> primeNum(int n) {
        vector<int> prime(n+1, 1);
        prime[0] = 0;
        prime[1] = 0;

        for(int i=2; i * i <= n; i++) {
            if(prime[i]) {
                for(int j=i*i; j<=n; j+=i) 
                    prime[j] = 0;
            }
        }

        return prime;
    }

    int sumOfPrimesInRange(int n) {
        int revN = reverseNum(n);

        int mini = min(n, revN);
        int maxi = max(n, revN);

        vector<int> prime = primeNum(maxi);

        int ans = 0;

        for(int i=mini; i<=maxi; i++) {
            if(prime[i])
                ans += i;
        }

        return ans;
    }
};