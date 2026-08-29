/*
    You are given a 0-indexed array of positive integers nums and a positive integer limit. In one operation, you can choose any two indices i and j and swap nums[i] and 
    nums[j] if |nums[i] - nums[j]| <= limit. Return the lexicographically smallest array that can be obtained by performing the operation any number of times. An array a is 
    lexicographically smaller than an array b if in the first position where a and b differ, array a has an element that is less than the corresponding element in b. 

    Example 1:
    Input: nums = [1,5,3,9,8], limit = 2
    Output: [1,3,5,8,9]
    Explanation: Apply the operation 2 times: - Swap nums[1] with nums[2]. The array becomes [1,3,5,9,8] - Swap nums[3] with nums[4]. The array becomes [1,3,5,8,9]
    We cannot obtain a lexicographically smaller array by applying any more operations. Note that it may be possible to get the same result by doing different operations.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> arr = nums;
        sort(arr.begin(), arr.end());

        int grpNo = 0;

        unordered_map<int, int> numToGrp; // {num --> group number} // which element belongs to which grp
        numToGrp[arr[0]] = grpNo;

        unordered_map<int, vector<int>> grpToList; // {group number --> {numbers}} // elements belonging to same grp
        grpToList[grpNo].push_back(arr[0]);

        for(int i=1; i<arr.size(); i++) {
            if(abs(arr[i] - arr[i-1]) > limit)
                grpNo++;
            
            numToGrp[arr[i]] = grpNo;
            grpToList[grpNo].push_back(arr[i]);
        }

        for(int i=0; i<nums.size(); i++) {
            int num = nums[i];
            int grp = numToGrp[num];

            nums[i] = grpToList[grp][0];
            grpToList[grp].erase(grpToList[grp].begin());
        }

        return nums;
    }
};