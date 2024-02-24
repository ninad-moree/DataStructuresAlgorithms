/*
    You are given a 0-indexed string num representing a non-negative integer.
    In one operation, you can pick any digit of num and delete it. Note that if you delete all the digits of num, num becomes 0.
    Return the minimum number of operations required to make num special.
    An integer x is considered special if it is divisible by 25.

    Example 1:
    Input: num = "2245047"
    Output: 2
    Explanation: Delete digits num[5] and num[6]. The resulting number is "22450" which is special since it is divisible by 25.
    It can be shown that 2 is the minimum number of operations required to get a special number.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperations(string num) {
        int cnt0 = 0;
        for(auto i : num) {
            if(i == '0')
                cnt0++;
        }

        int ans = INT_MAX;

        for(int i=0; i<num.size()-1; i++) {
            for(int j=i+1; j<num.size(); j++) {
                int a = num[i] - '0';
                int b = num[j] - '0';
                int c = a*10 + b;

                if(c==0 || c==25 || c==50 || c==75) 
                    ans = min(ans, static_cast<int>(num.size()) - i - 2);
            }
        }

        if(ans == INT_MAX) {
            if(cnt0 == 1)
                return static_cast<int>(num.size()) - 1;
            else
                return static_cast<int>(num.size());
        }

        return ans;
    }
};