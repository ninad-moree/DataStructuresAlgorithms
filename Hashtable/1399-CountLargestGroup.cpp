/*
    You are given an integer n. Each number from 1 to n is grouped according to the sum of its digits. Return the number of groups that have the 
    largest size.

    Example 1:
    Input: n = 13
    Output: 4
    Explanation: There are 9 groups in total, they are grouped according sum of its digits of numbers from 1 to 13:
    [1,10], [2,11], [3,12], [4,13], [5], [6], [7], [8], [9]. There are 4 groups with largest size.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumDigits(int n) {
        int sum = 0;

        while(n > 0) {
            sum += n%10;
            n = n/10;
        }

        return sum;
    }

    int countLargestGroup(int n) {
        unordered_map<int, vector<int>> mp;

        for(int i=1; i<=n; i++) {
            if(i <= 9)
                mp[i].push_back(i);
            else {
                int sum = sumDigits(i);
                mp[sum].push_back(i);
            }
        }

        int maxi = 0;
        for(auto i : mp) {
            vector<int> v = i.second;
            int s = v.size();
            maxi = max(maxi, s);
        }

        int ans = 0;
        for(auto i : mp) {
            vector<int> v = i.second;
            if(v.size() == maxi)
                ans++;
        }

        return ans;
    }
};