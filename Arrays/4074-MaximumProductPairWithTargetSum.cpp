/*
    You are given an integer array nums and an integer target. A pair of distinct indices (i, j) is valid if: nums[i] + nums[j] == target and nums[i] > nums[j]
    Return a valid pair [i, j] whose product nums[i] * nums[j] is maximum among all valid pairs. If no valid pair exists, return [-1, -1]. If multiple valid pairs achieve the 
    maximum product, you may return any of them.

    Example 1:
    Input: nums = [1,2,3,4], target = 5
    Output: [2,1]
    Explanation: There are 2 valid pairs: Both pairs sum to 5 and satisfy nums[i] > nums[j]. The second pair has the larger product, 3 * 2 = 6, so the answer is [2, 1].
    No.	(i, j)	nums[i]	nums[j]	Sum	Product
    1	(3, 0)	4	1	5	4
    2	(2, 1)	3	2	5	6
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        int n = nums.size();
        int prod = INT_MIN;
        int x = -1, y = -1;

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i != j) {
                    int n1 = nums[i];
                    int n2 = nums[j];



                    if(n1 + n2 == target && n1 > n2) {
                        if(prod < n1 * n2) {
                            prod = n1 * n2;
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        return {x, y};
    }
};