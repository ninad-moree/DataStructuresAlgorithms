/*
    You are given two integers n and m that consist of the same number of digits. You can perform the following operations any number of times:
    Choose any digit from n that is not 9 and increase it by 1. Choose any digit from n that is not 0 and decrease it by 1.
    The integer n must not be a prime number at any point, including its original value and after each operation. The cost of a transformation is the sum of all values that n 
    takes throughout the operations performed. Return the minimum cost to transform n into m. If it is impossible, return -1.

    Example 1:
    Input: n = 10, m = 12
    Output: 85
    Explanation: We perform the following operations:
    Increase the first digit, now n = 20. Increase the second digit, now n = 21. Increase the second digit, now n = 22. Decrease the first digit, now n = 12.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> generatePrime() {
        vector<int> prime(1e4+1, 1);
        prime[0] = prime[1] = 0;

        for(int i=2; i<=1e4; i++) {
            if(prime[i]) {
                for(int j=i*i; j<=1e4; j+=i)
                    prime[j] = 0;
            }
        }

        return prime;
    }

    int minOperations(int n, int m) {
        vector<int> prime = generatePrime();
        if(prime[n] || prime[m])
            return -1;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_map<int, int> vis;
        pq.push({n, n});

        while(!pq.empty()) {
            int steps = pq.top().first;
            int curr = pq.top().second;
            pq.pop();

            if(curr == m)
                return steps;

            if(vis.find(curr) != vis.end())
                continue;
            vis[curr]++;

            string s = to_string(curr);
            for(int i=0; i<s.size(); i++) {
                char ch = s[i];

                if(s[i] < '9') {
                    s[i]++;
                    int next = stoi(s);

                    if(!prime[next] && vis.find(next) == vis.end())
                        pq.push({steps + next, next});
                    
                    s[i] = ch;
                }

                if(s[i] > '0') {
                    s[i]--;
                    int next = stoi(s);

                    if(!prime[next] && vis.find(next) == vis.end())
                        pq.push({steps + next, next});
                    
                    s[i] = ch;
                }
            }
        }

        return -1;
    }
};