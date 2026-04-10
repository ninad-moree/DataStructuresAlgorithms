/*
    You are given an integer array nums. A tuple (i, j, k) of 3 distinct indices is good if nums[i] == nums[j] == nums[k]. The distance of a good tuple is abs(i - j) + 
    abs(j - k) + abs(k - i), where abs(x) denotes the absolute value of x. Return an integer denoting the minimum possible distance of a good tuple. If no good tuples exist, 
    return -1.

    Example 1:
    Input: nums = [1,2,1,1,3]
    Output: 6
    Explanation: The minimum distance is achieved by the good tuple (0, 2, 3). (0, 2, 3) is a good tuple because nums[0] == nums[2] == nums[3] == 1. Its distance is abs(0 - 2)
    + abs(2 - 3) + abs(3 - 0) = 2 + 1 + 3 = 6.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp; // number, {index};

        for(int i=0; i<nums.size(); i++) 
            mp[nums[i]].push_back(i);

        int ans = INT_MAX;

        for(auto i : mp) {
            vector<int> arr =  i.second;

            if(arr.size() >= 3) {
                for(int j=0; j<arr.size()-2; j++) {
                    int idx1 = arr[j];
                    int idx2 = arr[j+1];
                    int idx3 = arr[j+2];

                    int dist = abs(idx1 - idx2) + abs(idx2 - idx3) + abs(idx3 - idx1);

                    ans = min(ans, dist);
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};