/*
    You are given an array of positive integers nums of length n.
    A polygon is a closed plane figure that has at least 3 sides. The longest side of a polygon is smaller than the sum of its other sides.
    Conversely, if you have k (k >= 3) positive real numbers a1, a2, a3, ..., ak where a1 <= a2 <= a3 <= ... <= ak and a1 + a2 + a3 + ... + ak-1 > ak, then there always exists a polygon with k sides whose lengths are a1, a2, a3, ..., ak.
    The perimeter of a polygon is the sum of lengths of its sides.
    Return the largest possible perimeter of a polygon whose sides can be formed from nums, or -1 if it is not possible to create a polygon.

    Example 1:
    Input: nums = [5,5,5]
    Output: 15
    Explanation: The only possible polygon that can be made from nums has 3 sides: 5, 5, and 5. The perimeter is 5 + 5 + 5 = 15.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long ans = -1;

        sort(nums.begin(), nums.end());

        vector<long long>prefix(nums.size());
        prefix[0] = nums[0];

        for(int i=1;i<nums.size();i++)
            prefix[i] = prefix[i-1] + nums[i];

        int i = nums.size() -1;
        int j = nums.size() -2;

        while(j>=0) {
            if(prefix[j]>nums[i]) {
                ans = (long long) prefix[i];
                break;
            }
            i--;
            j--;
        }

        return ans;
    }
};