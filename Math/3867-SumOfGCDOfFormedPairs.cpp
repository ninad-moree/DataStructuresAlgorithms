/*
    You are given an integer array nums of length n. Construct an array prefixGcd where for each index i:
    Let mxi = max(nums[0], nums[1], ..., nums[i]). prefixGcd[i] = gcd(nums[i], mxi). After constructing prefixGcd:
    Sort prefixGcd in non-decreasing order. Form pairs by taking the smallest unpaired element and the largest unpaired element. Repeat this process until no more pairs can be 
    formed. For each formed pair, compute the gcd of the two elements. If n is odd, the middle element in the prefixGcd array remains unpaired and should be ignored.
    Return an integer denoting the sum of the GCD values of all formed pairs. The term gcd(a, b) denotes the greatest common divisor of a and b.

    Example 1:
    Input: nums = [2,6,4]
    Output: 2
    Explanation:
    Construct prefixGcd:
    i	nums[i]	mxi	prefixGcd[i]
    0	2	    2	2
    1	6	    6	6
    2	4	    6	2
    prefixGcd = [2, 6, 2]. After sorting, it forms [2, 2, 6]. Pair the smallest and largest elements: gcd(2, 6) = 2. The remaining middle element 2 is ignored. Thus, the sum is 2.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxi(n);
        maxi[0] = nums[0];

        for(int i=1; i<n; i++) 
            maxi[i] = max(maxi[i-1], nums[i]);
        
        vector<int> prefix(n);

        for(int i=0; i<n; i++) 
            prefix[i] = __gcd(nums[i], maxi[i]);

        sort(prefix.begin(), prefix.end());

        int i = 0;
        int j = n-1;
        long long ans = 0;

        while(i < j) {
            ans += __gcd(prefix[i], prefix[j]);
            i++;
            j--;
        }

        return ans;
    }
};