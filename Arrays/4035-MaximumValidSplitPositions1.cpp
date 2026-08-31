/*
    You are given an integer array nums. You may remove at most one element from nums. Let arr be the array of remaining elements in their original order, and let m be its 
    length. A split position i of arr is valid if: 0 <= i < m - 1, and gcd(arr[0..i]) == gcd(arr[i + 1..m - 1]). An array of length 1 has no valid split positions. The score of
    arr is the number of valid split positions in it. Return the maximum possible score of arr. Here, gcd(a) denotes the greatest common divisor of all elements in the array a.

    Example 1:
    Input: nums = [10,30,15,10]
    Output: 2
    Explanation: One optimal solution is to remove nums[2] = 15. Then arr = [10, 30, 10].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i=-1; i<n; i++) {
            vector<int> arr;

            for(int j=0; j<n; j++) {
                if(i == j)
                    continue;
                arr.push_back(nums[j]);
            }

            int m = arr.size();

            if(m < 2)
                continue;

            vector<int> prefix(m);
            vector<int> suffix(m);
            
            prefix[0] = arr[0];
            for(int j=1; j<m; j++)
                prefix[j] = __gcd(prefix[j-1], arr[j]);

            suffix[m-1] = arr[m-1];
            for(int j=m-2; j>=0; j--) 
                suffix[j] = __gcd(suffix[j+1], arr[j]);

            int score = 0;

            for(int j=0; j<m-1; j++) {
                if(prefix[j] == suffix[j+1])
                    score++;
            }

            ans = max(ans, score);
        }

        return ans;
    }
};