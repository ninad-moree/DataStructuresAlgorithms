/*
    You are given an integer n. An integer x is considered good if there exist at least two distinct pairs (a, b) such that: a and b are positive integers.
    a <= b, x = a^3 + b^3. Return an array containing all good integers less than or equal to n, sorted in ascending order.

    Example 1:
    Input: n = 4104
    Output: [1729,4104]
    Explanation: Among integers less than or equal to 4104, the good integers are:
    1729: 13 + 123 = 1729 and 93 + 103 = 1729. 4104: 23 + 163 = 4104 and 93 + 153 = 4104. Thus, the answer is [1729, 4104].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        unordered_map<long long, int> mp;

        for(int a = 1; ; a++) {
            long long a3 = 1LL * a * a * a;

            if(a3 >= n)
                break;

            for(int b = a + 1; ; b++) {
                long long b3 = 1LL * b * b * b;
                long long x = a3 + b3;

                if(x > n)
                    break;

                mp[x]++;
            }
        }

        vector<int> ans;

        for(auto i : mp) {
            int x = i.first;
            int cnt = i.second;
            
            if(cnt >= 2)
                ans.push_back(x);
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};